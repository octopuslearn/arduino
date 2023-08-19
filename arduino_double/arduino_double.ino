
const byte pins[]={2,3,4,5,6};
//结构体
struct LED{
  byte pin;
  unsigned int interval;
  unsigned long previousMillis;
};
//结构体数组
LED led2 = {2, 2000, 0};
LED led3 = {3, 3000, 0};
LED led4 = {4, 4000, 0};
LED led5 = {5, 5000, 0};
LED led6 = {6, 6000, 0};



LED leds[5]={led2,led3,led4,led5,led6};//用于存放引脚？？？
byte ledsLength = sizeof(leds)/sizeof(leds[0]);//获取数组元素个数


void setup()
{
  Serial.begin(9600);
  //demo1
  //for(byte pin : pins)  pinMode(pin,OUTPUT);//此为C++。在每次循环迭代中，变量 pin 将会被赋值为 pins 容器中的一个引脚号，然后使用 pinMode 函数将该引脚设置为输出模式。

  //demo2
  for(LED led : leds) pinMode(led.pin, OUTPUT);//将leds数组中的每一个设置为输出模式
}


void loop()
{
  //demo1
  //onLed();

  //demo2
  multitaskLED();
}

//每过1天亮一盏灯
void onLed()
{
  // unsigned long interval = 24*60*60*1000L;//一天，单位1ms  
  unsigned long interval = 1000L;//一天，单位1ms 
  for(byte pin : pins)
  {
    if(millis() >= pin*interval) digitalWrite(pin, HIGH);//当前时间大于引脚*一天的毫秒数，点亮相应的灯，由于教程上的灯连接到2引脚，所以第二天的时候才点亮第一盏灯
  }
}

void multitaskLED()
{
  unsigned long currentMillis = millis();//当前时间

  for(byte i = 0;i<ledsLength;i++)
  {
    if(currentMillis - leds[i].previousMillis >= leds[i].interval)//到达时间间隔
    {
      leds[i].previousMillis = currentMillis;//更新当前值
      digitalWrite(leds[i].pin, !digitalRead(leds[i].pin));
    }
  }
}
