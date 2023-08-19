#include "Wire.h"//iic,twi(twi兼容iic，是为了逃避iic专利费的)

#define ADDRESS 0x8
byte temp = 24;//摄氏度
byte unitType = 0;//0-摄氏度，1-华氏度


void requestEvent();
void receiveEvent(int howMany_bytes);

void setup()
{
  Serial.begin(9600);
  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);//收到数据后，执行receiveEvent。从设备接收便调用。设定到底是摄氏度还是华氏度
  Wire.onRequest(requestEvent);//收到需求指令，执行requestEvent。从设备相应请求。获取当前的温度值
}

void loop()
{
  delay(100);
}

//收到数据时执行，即从机接收到数据时调用此函数
void receiveEvent(int howMany_bytes)
{
  String cmd = " ";//UNIT0-5 bytes
  while(Wire.available() > 1)//读取UNIT，而不读取0/1
  {
    char c = Wire.read();
    cmd.concat(c);
  }
  Serial.println(cmd);//读取0/1
  if(cmd == "UNIT") unitType = Wire.read();
  cmd = " ";
}

void requestEvent()
{
  switch(unitType)
  {
    case 0:Wire.write(temp);break;//返回摄氏度
    case 1:Wire.write((uint8_t)((temp*1.8)+32));break;//返回华氏度
    default:break;
  }
}
