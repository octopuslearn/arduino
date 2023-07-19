/*弹幕说，构造函数名称和类名称相同*/

#include "Led.h"
PwmLed myPwmLed;//建立全局对象
void setup() {
  Serial.begin(9600);
  int myPwmLed_pin=myPwmLed.getledPin();//就算子类中啥也没有但不响使用
  myPwmLed.change_ledPin(3);
  Serial.print("getledPin: "); Serial.println(myPwmLed.getledPin());
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
