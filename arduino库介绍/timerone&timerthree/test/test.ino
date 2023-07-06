#include <TimerOne.h>
#define hy5   12    //OUT1
int a;
int flag=0;
int i=0;
int s=0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(hy5, INPUT);
  Timer1.initialize(1000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt(trun_LR90);
}


void loop()
{
  Serial.print(i);Serial.println();
  a=digitalRead(hy5);
//  if(a==1)
//  {
//    s=1;
//    Serial.println("伟大的");
//    if(flag==1)
//    {
//      flag=0;
//      Serial.println("sssssssss");
//      while(1);
//    }
//  }
hihi();
}

void hihi()
{
  if(a==1)
    {
      s=1;
      Serial.println("伟大的");
      if(flag==1)
      {
        flag=0;
        Serial.println("sssssssss");
        while(1);
      }
    }
}

void trun_LR90()
{
  if(s==1)
  {
    i++;
   s=0;
    if(i>200)
    {
      i=0;
      flag=1;
    }
  }
}
