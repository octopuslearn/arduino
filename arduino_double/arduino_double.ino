#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  unsigned int eepromLength = getEEPROMLength(true);//获取EEPROM大小
}
void loop()
{}


unsigned int getEEPROMLength(bool choose)
{
  unsigned int length = EEPROM.length();//获取EEPROM存储单元
  if(choose == true)
  {
    Serial.print("EEPROM length:  ");Serial.println(length);
  }
  return length;
}
