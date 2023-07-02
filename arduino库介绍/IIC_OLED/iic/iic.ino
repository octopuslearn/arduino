#include <Wire.h> //引入IIC通讯所需要的Wire库文件


#include <Adafruit_SSD1306.h>       //引入OLED0.96所需要的库
#include <Adafruit_GFX.h>

#define SCREEN_WIDIH  128     //设置OLED宽度，单位：像素
#define SCREEN_HEIGHT 64      //高度

#define OLED_REST 4           //自定义重置引脚Adafruit_SSD1306所必须

Adafruit_SSD1306  OLED_dispaly(SCREEN_WIDIH, SCREEN_HEIGHT, &Wire, OLED_REST);//初始化构造器  //IIC总线实例，默认为&wrie

void setup()
{
  Wire.begin();     //初始化Wire库
  OLED_dispaly.begin(SSD1306_SWITCHCAPVCC, 0x3C);   //初始化OLED,IICd地址0x3c  //switchvcc： OLED的电压
}

void loop()
{
  OLED_dispaly.clearDisplay();      //清屏
  
  OLED_dispaly.setTextSize(2);      //设置字体大小 //字体大小倍数，s为1时为6x8，s为2时为12x16
  OLED_dispaly.setTextColor(WHITE); //设置字体颜色
  
  OLED_dispaly.setCursor(3,20);     //设置光标位置
  OLED_dispaly.print("OC_LEARN!!!");

  
  OLED_dispaly.display();           //显示内容      
  
}
