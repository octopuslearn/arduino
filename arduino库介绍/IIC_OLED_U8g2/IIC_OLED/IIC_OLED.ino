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
  // put your setup code here, to run once:

}

void loop() {
  u8g2.clearBuffer();                //清除内部缓冲区
  u8g2.setFont(u8g2_font_8x13B_mr);//设置字体集
  u8g2.drawStr(40,20,"oc_learn! ");
  u8g2.drawStr(20,40,"belive you!!!");
  u8g2.sendBuffer();                 //绘制缓冲区的内容
  // put your main code here, to run repeatedly:
  delay(1000);
}
