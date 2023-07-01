#include <Stepper.h>
const int a=32;
const int b=64;
const float c=a*b;
int k;
/*强烈注意：此处是转子转一周的步数，，，注意啊，在此浪费了连个小时*/Stepper Stepper1(a,2,7,4,8);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  k=c;
  Stepper1.setSpeed(800);
  Stepper1.step(k);
  delay(1000);
  // put your main code here, to run repeatedly:
   k=-c;
  Stepper1.setSpeed(800);
  Stepper1.step(k);
  delay(1000);

}
