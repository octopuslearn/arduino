//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


//lcd初始化0x27-地址，16-显示行数，2-显示列数
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();//开启背光
  cursorOn();//显示游标，闪动游标
//  cursorOff();//不显示游标，不闪动游标
//  demo1();//基础：清除屏幕回到原点，设定坐标，显示内容
//  demo2();//读取CGRAM，也就是直接从lcd芯片里将字符弄出来显示
//  demo3();//注意事项，hd44780 一行保存40个字，然后才会换行 hd44780 并不知道你的LCD的尺寸的大小
//  demo4();//自定义图案，实际上只能自定义八个
//  demo5();//大图,也就是使用几个自定义的图案拼成一个大的图
/*这个没有做*/  //demo6();//显示中文--->和demo5一样
   demo7();//滚动效果
}


void loop()
{
}

//基础：清除屏幕回到原点，设定坐标，显示内容
void demo1()
{
  lcd.clear();//清除屏幕所有内容，并且将游标回执到原点
  lcd.print("Oc_learn");
  lcd.setCursor(0,1);//设定坐标(x,y)--->第二行第一个位置
  lcd.print("lcd 1602");
}

//显示游标，闪动游标
void cursorOn()
{
  lcd.cursor();//显示游标
  lcd.blink();//闪动游标
}

//不显示游标，不闪动游标
void cursorOff()
{
  lcd.noCursor();//显示游标
  lcd.noBlink();//闪动游标
}

//读取CGRAM
void demo2()
{
 lcd.clear();//清除屏幕所有内容，并将游标回执到原点
 lcd.write(0b10110001);//二进制方式读取--->A
// lcd.write(66);//十进制方式读取
// lcd.(0x43);//十六进制方式读取
}
//注意事项
void demo3()
{
//hd44780 一行保存40个字，然后才会换行
//hd44780 并不知道你的LCD的尺寸的大小
  lcd.print("abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz");
  delay(5000);

  lcd.home();
  lcd.print("finish!");
}

//自定义
void demo4()
{
byte customChar[] = {
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10101,
  B10101,
  B01010
};
  //一共有8个位置，0-7
  lcd.createChar(0, customChar);//将自定义的注册到0的位置

  lcd.home();
  //使用前，光标必须重设
  //也就是有home(),clear()或者setCursor()
  lcd.write(0);
}

//大图
void demo5()
{
  char sex[2][8]={
  {//0
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
  },
  
  {//1
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10001,
  B10101,
  B01010
  }
 };
  //一共有8个位置，0-7
  lcd.createChar(0, sex[0]);//将自定义的注册到0的位置
  lcd.createChar(1, sex[1]);//将自定义的注册到0的位置

  lcd.setCursor(0, 0);
  lcd.write(0);
  lcd.setCursor(0,1);
  lcd.write(1);

  lcd.setCursor(3, 0);
  lcd.print("sex!");
  lcd.setCursor(3, 1);
}

//滚动效果
void demo7()
{
  cursorOff();//不显示游标，不闪动游标
  lcd.clear();

  lcd.print("Let's go");

  for(int i = 0;i < 13;i++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for(int i = 0;i < 33;i++)
  {
    lcd.scrollDisplayRight();
    delay(150);
  }
  for(int i = 0;i < 20;i++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}
