#include <EEPROM.h>

unsigned int length = 0;

void showAll(unsigned int eepromLength);


void setup()
{
  Serial.begin(9600);

  unsigned int eepromLength = getEEPROMLength(true);//获取EEPROM大小
}
void loop()
{
  showAll(length);
}


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


void showAll(unsigned int eepromLength)
{
  for(int add = 0;add < eepromLength; add++){
    byte data = EEPROM.read(add);
    Serial.print("Address ");
    Serial.print(add);
    Serial.print(" -> ");
    Serial.println(data);
  }
}
