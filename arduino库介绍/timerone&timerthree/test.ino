#include <TimerOne.h>
int i = 0;
int LR90_flag = 0;

void setup()
{
//  Serial.begin(9600);
  pinMode(13,OUTPUT);

  Timer1.initialize(1000);  //定时器1初始化
  Timer1.attachInterrupt(trun_LR90);
}

void loop()
{
  Serial.print("累计：");  Serial.println(i);  Serial.print("\t");
  if(LR90_flag == 1)
  { 
    LR90_flag = 0;
    Serial.print("LR90_flag："); Serial.println(LR90_flag); 
    digitalWrite(13,!digitalRead(13));   
  }  
}

void trun_LR90()
{
  i++;
  if(i>100)
  {
    i = 0;
    LR90_flag = 1;
  }
}
