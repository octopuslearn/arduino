#include <Wire.h>

void setup() {
  Wire.begin();//开Wire初始化，加入I2C总线，主机身份
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Wire.requestFrom(8,6);  //主请求从设备（地址8）6个字节
  Serial.print("c:   ");
  while(Wire.available()) //当主从从设备接收到信息
  {
    char c = Wire.read(); //读从设备发来的一个字节的数据
                          //官网上没说到底几个字节
    Serial.print(c);
  }                       
  Serial.println();
  // put your main code here, to run repeatedly:
  delay(10);
}
