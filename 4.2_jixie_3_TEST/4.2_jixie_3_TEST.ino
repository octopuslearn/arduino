/**********
 * g-获取舵机角度信息
 * i-舵机回中
 * x-舵机X串口指令控制
 * y-舵机Y串口指令控制
 * m-模式 1-手动模式 0-指令模式
 * o-手控舵机X移动减3度
 * p-手控舵机Y移动减5度
 * l-手控舵机X移动加3度，注意此处为小写字母L
 * r-手控舵机X移动加5度
 **********/


/*****
 * 主要思路
 * 1.判断何种工作模式
 * 2.若手动模式-清除指令模式中的干扰因素-根据串口数据执行相应操作，错误操作报错 2.a.1若是手动操作指令o、p,分别减3、5，否则执行其他的操作-写入
 * 2.若指令模式-清除手动模式中的干扰因素-根据串口数据执行相应操作同上
 *****/
#include <Servo.h>

#define laser 2//激光

Servo servo_x,servo_y;//创建舵机对象

int angle_x,angle_y;//舵机x转动角度，舵机y
int TXD_angle;//读取旋转角度

int angle_x_min=0;//转动角度限定
int angle_x_max=180;
int angle_y_min=0;//转动角度限定
int angle_y_max=180;


bool mode;//舵机工作模式
int Servo_speed=15;

void setup() {
  Serial.begin(9600);
  pinMode(laser,OUTPUT);
  servo_x.attach(3);//舵机x-3引脚
  delay(200);//稳定性等待
  servo_y.attach(5);
  delay(200);
  
  servo_x.write(90);//舵机初值
  delay(10);
  servo_y.write(90);
  delay(10);
}

void loop() {
  pinMode(laser,HIGH);//打开激光
    
  if(Serial.available()>0)//接收到数据
  {
    char TXD_dat=Serial.read();//读取数据
    if(mode==0)
      Servo_directivescontrol(TXD_dat);//指令模式，参数：串口指令
    else 
      Servo_Manualcontrol(TXD_dat);//手动模式，参数：串口指令
  }
}

/*指令模式*/
void Servo_directivescontrol(char TXD_dats)
{
  if(TXD_dats=='o' || TXD_dats=='p' || TXD_dats=='l' || TXD_dats=='r')//清除错误指令
  {
    Serial.println("正在清除手动模式中错误指令！");
    delay(100);
    while(Serial.available()) Serial.read();//直到清除完所有错误指令
    return; 
  }
  
  if(TXD_dats=='x' || TXD_dats=='y')////注意：必须在判断一次
  {
    TXD_angle=Serial.parseInt();//读取旋转角度
    Servo_classify(TXD_dats,TXD_angle,Servo_speed);//舵机分类及写入，参数：串口数据，舵机速度
  }
  else
  {  
    switch(TXD_dats)
    {
      case 'm':mode=1;//切换成手动模式
              Serial.print("控制模式：");Serial.println("手动模式");
              break;
      case 'g':getResourse();break;
      case 'i':goback();break;
      default:Serial.println("指令模式中无此指令");break;
    }
  }
}

/*手动模式-舵机分类及写入，参数：串口数据*/
void Servo_Manualcontrol(char TXD_datss)
{
  if(TXD_datss=='x' || TXD_datss=='y')//清除错误指令
  {
    Serial.println("正在清除手动模式中错误指令！");
    delay(100);
    while(Serial.available()) Serial.read();//直到清除完所有错误指令
    return; 
  }

/*调试1*/ Serial.print("调试111：串口接受到的数据");  Serial.println(TXD_datss);
  
  if(TXD_datss=='o')
  {
    int Mangle_x=Serial.parseInt();//串口数据转动角度，即每次要转动的角度，即微调
    int Manglenow_x=servo_x.read();//舵机X当前角度
/*调试2*/ Serial.print("调试999舵机当前角度");  Serial.println(Manglenow_x);    
/*调试2*/ Serial.print("调试222微调角度");  Serial.println(Mangle_x);
    int Mangleout_x=Manglenow_x-Mangle_x;//舵机实际应当转的角度
/*调试3*/ Serial.print("调试333舵机实际转动角度");  Serial.println(Mangleout_x);
    Servo_classify('x',Mangleout_x,Servo_speed);
  }
  else if(TXD_datss=='p')
  {
    int Mangle_y=Serial.parseInt();//串口数据转动角度，即每次要转动的角度，即微调
    int Manglenow_y=servo_y.read();//舵机X当前角度
    int Mangleout_y=Manglenow_y-Mangle_y;//舵机实际应当转的角度
    
    Servo_classify('y',Mangleout_y,Servo_speed);
  }
  else if(TXD_datss=='l')
  {
    int Mangle_l=Serial.parseInt();//串口数据转动角度，即每次要转动的角度，即微调
    int Manglenow_l=servo_x.read();//舵机X当前角度
    int Mangleout_l=Manglenow_l+Mangle_l;//舵机实际应当转的角度
    
    Servo_classify('x',Mangleout_l,Servo_speed);
  }
  else if(TXD_datss=='r')
  {
/*调试*/    Serial.println("AAAAA");
    int Mangle_r=Serial.parseInt();//串口数据转动角度，即每次要转动的角度，即微调
    int Manglenow_r=servo_y.read();//舵机X当前角度
    int Mangleout_r=Manglenow_r+Mangle_r;//舵机实际应当转的角度
    
    Servo_classify('y',Mangleout_r,Servo_speed);
  }
  else if(TXD_datss=='g')
    getResourse();
  else if(TXD_datss=='m')
  {
    mode=0;//切换成指令模式
    Serial.print("控制模式：");Serial.println("指令模式");
  }
  else if(TXD_datss=='i')
    goback();
  else
  {
    Serial.println("手动模式中无此指令！");
    return;
  }
}

/*舵机分类及写入，参数：串口数据，转动角度，舵机速度*/
void Servo_classify(char TXD_dats,int TXD_angles,int Servo_speeds)
{
  Servo replacement_Servo;//创建对象，用于比较
  int now_angle;//舵机当前角度
/*调试444*/ Serial.print("调试444：串口数据");  Serial.println(TXD_dats);  
  switch(TXD_dats) 
  {
    case 'x':
    {
      replacement_Servo=servo_x;//替换对象，以便于比较
      now_angle=replacement_Servo.read();//读取舵机当前角度
      
      if(TXD_angles>=angle_x_min && TXD_angles<=angle_x_max)//转动角度在限定范围内
        break;
      else
      {
        Serial.println("舵机X 转动角度超限制！");
        return;
      } 
    }
    
    case 'y':
    {
      replacement_Servo=servo_y;//替换对象，以便于比较
      now_angle=replacement_Servo.read();//读取舵机当前角度
      
      if(TXD_angles>=angle_y_min && TXD_angles<=angle_y_max)//转动角度在限定范围内
        break;
      else
      {
        Serial.println("舵机Y 转动角度超限制！");
        return;
      }
    }
  }


  
  if(now_angle < TXD_angles)//若当前角度<转动角度
  {
    for(int i=now_angle;i<=TXD_angles;i++)
    {
       replacement_Servo.write(i);
       delay(Servo_speeds);
    }
    Serial.print("舵机X");
  }
  else
  {
    for(int i=now_angle;i>=TXD_angles;i--)
    {
       replacement_Servo.write(i);//没有在此范围内声明
       delay(Servo_speeds);   
    }
    Serial.print("舵机Y");
  }
  Serial.print("舵机转动角度： "); Serial.println(TXD_angles);
  getResourse();
}

/*舵机回中*/
void goback()
{
  char back[][3]={
  {'x',90,TXD_angle},
  {'y',90,TXD_angle}
  };

  for(int i=0;i<=1;i++)
    Servo_classify(back[i][0],back[i][1],back[i][2]);
}

/*获取舵机信息*/
void getResourse()
{
  Serial.print("舵机当前角度： "); Serial.print("舵机X： ");  Serial.print(servo_x.read());  Serial.print("舵机Y： "); Serial.print('\t'); Serial.println(servo_y.read());
  Serial.print("舵机当前速度： "); Serial.println(Servo_speed);
  Serial.print("舵机当前模式： "); Serial.println(mode);
}
