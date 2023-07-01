#include <FastLED.h>

#define maike A0//麦克风

#define NUM_LEDS 120//led个数
#define DATA_PIN 2//控制引脚

int output;
int intput;

int flagled;


CRGB leds[NUM_LEDS];//设置/清除led数据

void setup() {
  FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);//指定led型号，leds数组，led个数
  // put your setup code here, to run once:

}


void loop() {
  intput=analogRead(maike);
  output=map(intput,0,1023,1,120);
    Serial.print("intput: "); Serial.println(intput);
    Serial.print("亮："); Serial.println(output);
    if(output>63)//当前值大于上一次值，亮
    {
      flagled=1;
    }
    else
    {
      flagled=0;
    }
    handleRGB();

}

void handleRGB()
{
        switch(flagled)
        {
          case 1: fill_solid(leds,output,CRGB::Yellow);FastLED.show();delay(1000);break;
            
          case 0:fill_solid(leds,120,CRGB::Black);FastLED.show();break;
         }
}
