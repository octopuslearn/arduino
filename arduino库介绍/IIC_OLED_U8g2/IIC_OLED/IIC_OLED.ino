#include <TimerOne.h>

#include <U8g2lib.h>
#include <U8x8lib.h>


#include <Wire.h>


/*
* SCL 20
* SDA 21
*/
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE);
void setup(){
  u8g2.begin();//初始化演示器
  pinMode(2, INPUT_PULLUP);
  // put your setup code here, to run once:

}

void loop() {
  bool button = digitalRead(2);
  u8g2.clearBuffer();                //清除内部缓冲区
  u8g2.setFont(u8g2_font_8x13B_mr);//设置字体集-10像素高度
  u8g2.drawStr(0,10,"button value: ");//x-0,y-必须留够字的大小（10个像素高）
  u8g2.setCursor(120,10);//y-同理
  u8g2.print(button);
  u8g2.sendBuffer();                 //绘制缓冲区的内容
  // put your main code here, to run repeatedly:
  delay(10);
}
