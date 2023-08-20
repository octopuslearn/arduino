#include <EEPROM.h>

unsigned int length = 0;

void showAll(unsigned int eepromLength);
void resetAll(unsigned int eepromLength, byte value = 255);









void setup()
{
  Serial.begin(9600);

  unsigned int eepromLength = getEEPROMLength(true);//获取EEPROM大小
}
void loop()
{
  // demo1
  // resetAll(1023, 233);//EEPROM写操作
  //demo2
  // showAll(length);//从EEPROM中读取1个字节
  //demo3
  eepromOperator();//此运算符允许像数组一样使用标识符。EEPROM单元可以使用此方法直接读取和写入
}







//获取eeprom大小
unsigned int getEEPROMLength(bool choose)
{
  // unsigned int length = EEPROM.length();//获取EEPROM存储单元
  length = EEPROM.length();//获取EEPROM存储单元
  if(choose == true)
  {
    Serial.print("EEPROM length:  ");Serial.println(length);
  }
  return length;
}


//从EEPROM读取一个字节，若果新的uno全是255
void showAll(unsigned int eepromLength)
{
  for(int add = 0;add < eepromLength; add++){//历遍0-1023，获取地址值
    byte data = EEPROM.read(add);
    Serial.print("Address ");
    Serial.print(add);
    Serial.print(" -> ");
    Serial.println(data);
  }
}

//EEPROM写操作
/*#####以下，EEPROM.write();每写1次3.3-5ms。如果写在loop中基本上5分钟就废了#####*/
void resetAll(unsigned int eepromLength, byte value = 255)
{
  for(int add = 0;add < eepromLength;add++)
  {
    EEPROM.write(add, value);
    Serial.print("Adreess:  ");Serial.print(add);
    Serial.print(" <- ");Serial.println(value);
  }
  showAll(eepromLength);
}
/*#####以上，EEPROM.write();每写1次3.3-5ms。如果写在loop中基本上5分钟就废了#####*/


//此运算符允许像数组一样使用标识符。EEPROM单元可以使用此方法直接读取和写入
void eepromOperator()
{
  if(EEPROM[0] != 100)
  {
    EEPROM[0] = 124;
  }
  Serial.print(" EEPROM[0]: ");Serial.println(EEPROM[0]);
}
