#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);
  Wire.onReceive(receiveEvent_1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
}

void receiveEvent_1()
{
  while(Wire.available()>1)
  {
    char c = Wire.read();
    Serial.print(c);
  }  
  int y = Wire.read();
  Serial.print("y:   ");  Serial.println(y);
}
