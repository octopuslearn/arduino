#include "Led.h"

//为构造函数里的变量赋值
//Led::Led(int userLedPin){//参数必须和Led(int userLedPin);//构造函数-有参数一致
//  Serial.println("Led::Led(int userLedPin)---succeed");
//  ledPin = userLedPin;  
//  pinMode(userLedPin,OUTPUT);
//}
/*以下，等同上*/
//为构造函数里的变量赋值
Led::Led(int userLedPin) : ledPin(userLedPin){//参数必须和Led(int userLedPin);//构造函数-有参数一致
  pinMode(userLedPin,OUTPUT);
}
/*以上，等同上*/

Led::Led(){//Led()此函数来自Led类
  pinMode(2,OUTPUT);
}
Led::~Led(){
  Serial.println("aaa");
}

void Led::off(){
  digitalWrite(ledPin,LOW);
}

void Led::on(){//on()属于Led类
  digitalWrite(ledPin,HIGH);
}

int Led::getledPin(){
  return ledPin;
}

void Led::change_ledPin(int userLedPin){
  ledPin = userLedPin;
  pinMode(ledPin,OUTPUT);
}

void PwmLed::on(int userPwmVal){
  pwmValue = userPwmVal;
  analogWrite(getledPin(),pwmValue);//在子类中调用父类中的函数getledPin()
}

int PwmLed::getPwmVal(){
  return pwmValue;
}
