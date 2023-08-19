#include <Wire.h>

#define ADDRESS 0x8
#define TEMP_TYPE 1 //1-华氏度，0-摄氏度

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(ADDRESS);
  Wire.write("UNIT");
  Wire.write(TEMP_TYPE);//华氏度
  Wire.endTransmission();
}

void loop()
{
  delay(1000);
  Wire.requestFrom(ADDRESS, 1);//向ADDRESS地址的从设备请求一个字节
  while(Wire.available())
  {
    byte temp = Wire.read();

    Serial.print("Temperature = ");
    Serial.print(temp);
    switch(TEMP_TYPE)
    {
      case 0:Serial.println("C");break;
      case 1:Serial.println("F");break;
      default:break;
    }
  }
}
