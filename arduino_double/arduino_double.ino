#include <Arduino_AVRSTL.h>

using namespace std;

void setup()
{  
  Serial.begin(9600);
  while(!Serial) {};//等待用户打开串口监视器
} 

void loop()
{
}
