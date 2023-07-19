/*弹幕说，构造函数名称和类名称相同*/

#include "Led.h"

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Led myLed;//建立Led类的对象 //有作用域 //故当setup执行完后此对象就没了，但在此之前会检查一下类中有没有析构函数，有的话先执行析构函数再删除
  myLed.change_ledPin(3); 
  Serial.print("验证更改: "); Serial.println(myLed.getledPin());//获取更改后的值，以验证
  
  Led myLed2(7);//控制7号引脚led
  for(int i=0;i<3;i++)
  {
    myLed.on();//检查myLed对象中有无on()函数，有就执行  //此为控制2号引脚
    myLed2.on();                                    //此为控制7号引脚
    delay(1000);
    myLed.off();
    myLed2.off();
    delay(1000);
  }


/*以下，测试公共成员变量可以在类外使用*/
//  int myLed2Pin=myLed.ledPin;
//  Serial.print("myLed2Pin: ");Serial.println(myLed2Pin);
/*以上，测试公共成员变量可以在类外使用*/

/*以下，测试通过公共成员函数可以在将私有成员变量在类外使用*/
  int myLed2Pin=myLed.getledPin();
  Serial.print("myLed2Pin: ");Serial.println(myLed2Pin);
/*以上，测试通过公共成员函数可以在将私有成员变量在类外使用*/
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
