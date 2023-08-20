#define ARDUINO
//#define ESP32
//#define ESP8266


//#define DEBUG 0//关闭DEBUG,只有0可以关闭DEBUG
#define DEBUG 1//打开DEBUG,除了0任何都可打开

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  #if DEBUG//用法3 DEBUG
    Serial.println("star");
  #endif

  
  Serial.println("goggo");
  #if(defined ESP32) || (defined ESP8266)//注意没有大括号，是defined
    vTaskDelay(3000);
  #elif(defined ARDUINO)
    delay(3000);
  #else
    Serial.println("开发板型号错误");
  #endif//不可缺少
}
