#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  while(!Serial);

  Wire.begin();//无形参，即主机
  Wire.setClock(100000);//默认100k
  Wire.setWireTimeout(300, true);//超时时间???
}
void loop()
{
  Serial.println("Scanning...");
  for(int i = 0;i<128;i++)
  {
    Wire.beginTransmission(i);//准备向指定的地址开始传输数据
    byte code = Wire.endTransmission();//结束传输
    if(code==0)//反馈0，代表受到回应，即应答位Aick=0
    {
      Serial.print("Found: 0x");
      Serial.println(i, HEX);
    }
  }
}
