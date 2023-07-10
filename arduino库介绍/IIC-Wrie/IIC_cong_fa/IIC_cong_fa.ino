#include <Wire.h>

void setup() {
  Wire.begin(8);//Wire初始化，以从设备加入总线（地址8）
  Serial.begin(9600);
  Wire.onRequest(requestEvent_1);//注册请求响应事件
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
}

/*当接收到来自主机的数据时执行的事件函数*/
//主机请求，从机回应请求-就执行这个函数
void requestEvent_1()
{
  Wire.write("hello ");//  用6个字节的消息进行响应
}
