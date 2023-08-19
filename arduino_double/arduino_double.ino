
#define  button 2
#define  debounce 120//消抖


bool btnStatusPrevious = 0;
bool btnStatusCurrent = 0;



int i = 0; 
void setup() {

  Serial.begin(9600);
  pinMode(button, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  btnStatusCurrent = digitalRead(button);


// //按键被一直按下去
//   if(btnStatusCurrent == HIGH)
//   {
//     Serial.println("按键按下");
//   }
//   else
//   {
//     Serial.println("按键弹起");
//   }
  
  // //按键按下去的瞬间
  // //当前按钮状态是high，之前按键状态是low--->按下
  // if((btnStatusCurrent == HIGH) && (btnStatusPrevious == LOW))
  // {
  //   i++;//按一下累计了七次
  //   Serial.print("i: ");Serial.print(i);Serial.print("\t");
  //   Serial.println("按键按一下");
  //   // delay(debounce);//消抖？？？--->没错消抖了
  //   i = 0;
  // }

  // if((btnStatusCurrent == LOW) && (btnStatusPrevious == HIGH))
  // {
  //   i++;//按一下累计了七次
  //   Serial.print("i: ");Serial.print(i);Serial.print("\t");
  //   Serial.println("弹起");
  //   // delay(debounce);//消抖？？？--->没错消抖了
  //   i = 0;
  // }
  

//单击，双击，三击
clickTick();


  btnStatusPrevious = btnStatusCurrent;//按键更新
}

void clickTick()
{
  static unsigned int clickMaxperiod = 500; //检测周期
  static unsigned int preeCount = 0;        //按键按下次数
  static bool isStart = 0;                  //检测周期开始标志
  static unsigned long startTime = 0;       //检测周期开始时间

  if((btnStatusCurrent == LOW) && (btnStatusPrevious == HIGH))
  {
    if(isStart == 0)
    {
      isStart = 1;//检测周期开始
      preeCount = 1;//当前按钮次数1
      startTime = millis();//获取周期开始时间
    }
    else
    {
      preeCount++;//按键次数累计
    }
    delay(debounce);//按键消抖
  }  
    
    if(((millis() - startTime) > clickMaxperiod) && isStart)//检测周期内获取按键按下次数
    {
      isStart = 0;//停止检测周期
      switch(preeCount)
      {
        case 1:btnSingle();break;
        case 2:btnDouble();break;
        case 3:btnTriple();break;
        default:break;
      }
    }
}


void btnSingle(){
  Serial.println("btnSingle");
}
void btnDouble(){
  Serial.println("btnDouble");
}
void btnTriple(){
  Serial.println("btnTriple");
}
