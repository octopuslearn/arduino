#define ARDUINO
//#define ESP32
//#define ESP8266


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("goggo");
  #if(defined ESP32) || (defined ESP8266)//注意没有大括号，是defined
    vTaskDelay(3000);
  #elif(defined ARDUINO)
    delay(3000);
  #else
    Serial.println("开发板型号错误");
  #endif//不可缺少
}
