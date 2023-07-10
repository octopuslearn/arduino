#include <Wire.h>

int x = 0;
char s[10]={'1','2','3'};

void setup() {
  Wire.begin();//Wire初始化，主机加入IIC总线
  // put your setup code here, to run once:

}

void loop() {
  Wire.beginTransmission(8);  //主向从发送数据，开始传输 8-从设备地址
  // put your main code here, to run repeatedly:
  Wire.write("I don't know:     ");//发送字符串
  Wire.write(s,10);           //发送多个字节10-字节长度
  Wire.write(x);              //发送一个字节
  Wire.endTransmission();     //发送为完毕

  x++;
  delay(10);
}
