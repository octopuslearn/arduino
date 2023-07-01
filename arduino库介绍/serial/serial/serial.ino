#include <Keypad.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial_1(2,3);

//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//}

//void loop() {
//  // put your main code here, to run repeatedly:
//  if(Serial.available())                //判读接收缓冲区中有无数据
//  {
////    char a = Serial.read();           //读取接收缓冲区中的一个字节，读完删除
////    Serial.print(a);
//    int int_a = Serial.parseInt();      //获取接收到的数据中的整数部分/*不可以和Serial.read()同时使用*/
//    Serial.println(int_a);
//
//  }
//}



const byte ROWS = 2;      //4行
const byte COLS = 4;      //2列

char keys[ROWS][COLS]={       //定义键值
  {'1','2','3','4'},
  {'5'},
};

byte rowPins[ROWS]={4,5};                       //行连接引脚
byte colPins[COLS]={6,9,10,11};                 //列连接引脚

Keypad customkeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);//创建对象Keypad,该对象使用4,5作为行引脚6,9,10,11作为列引脚，1行6列总共六个建


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial_1.begin(9600);     //软件串口
}


void loop()
{
  char key_value= customkeypad.getKey(); 
  if(key_value)
  {
//    Serial.println(key_value);
    switch(key_value)
    {
      case '1':BTserial_1.print('1');break;     //虚拟串口发送响应指令
      case '2':BTserial_1.print('2');break;
      case '3':BTserial_1.print('3');break;
      case '4':BTserial_1.print('4');break;
      case '5':BTserial_1.print('5');break;
      case '6':break;
      default:break;
    }
  }
}
