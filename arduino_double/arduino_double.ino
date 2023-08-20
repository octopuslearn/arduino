#include <Arduino_AVRSTL.h>
#include <vector>

using namespace std;

vector<byte> ledpins;//声明一个向量，size未知
int durations[]={100, 200, 300};//声明+初始化一个数组

void vectorinfo(const vector<byte> &vect)
{
  Serial.println("===== VECTOR INFOS =====");
  Serial.println(" 实际内存占用空间" + String(vect.capacity()));
  Serial.println(" 包含数据成员数量" + String(vect.size()));
  Serial.println("_________________________");  
}

void setup()
{  
  Serial.begin(9600);
  Serial.setTimeout(300);
  while(!Serial) {};//等待用户打开串口监视器
 
 vectorinfo(ledpins);//获取向量所占空间，成员数量

 Serial.println("开始录入 LED PIN");
 Serial.println("范围[1-13],输入-1结束录入");
 Serial.println("请输入要点亮的LED PIN");

 byte pin = 0;//0时存储输入的pin

 while(pin !=byte(-1))
 {
  while(Serial.available()>0)
  {
    pin = Serial.parseInt(SKIP_ALL);//Serial Terminal选择“没有结束符”

    if(pin == byte(-1)) break;

    if(pin >=1 and pin <= 13)
    {
      ledpins.push_back(pin);//用向量方法push_back将pin加到向量中去
      Serial.print("成功添加到向量：");
      Serial.println(pin);
    }
    else
    {
      Serial.println("错误数据，正确范围1-13");
    }
  }
 }

 Serial.print("ledpins vector = [");
 for(byte ledpin : ledpins)
 {
  Serial.print(ledpin);
  Serial.print(" ");
 }
 Serial.println("]");
 vectorinfo(ledpins);//获取向量所占空间，成员数量


 //将所有的pin端口设置为输出模式
 if(!ledpins.empty())//向量方法，判断向量是否为空
 {
  for(byte ledpin : ledpins)
  {
    pinMode(ledpin, OUTPUT);
  }
 }

 //倒计时
 int i = 0;
 Serial.println("点灯倒计时开始");
 while(i<10)
 {
  Serial.print(++i);//++i和i++不同？？？单句时不是相同吗 ++i先加后显示
  Serial.print("  ");
  delay(500);
 }
 Serial.println("\n开始你的表演");
} 


void loop()
{
  if(!ledpins.empty())
  {
    for(byte ledpin : ledpins)
    {
      for(int duration : durations)
      {
        Serial.println("ON " + String(ledpin) + " - " + String(duration) + "毫秒");
        digitalWrite(ledpin, HIGH);
        delay(durations);
        Serial.println("OFF " + String(ledpin) + " - " + String(duration) + "毫秒");
        digitalWrite(ledpin, LOW);
        delay(durations);
      }
    }
  }
}
