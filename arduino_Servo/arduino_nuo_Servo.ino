#include <Servo.h>
Servo Servo_x,Servo_y;

#define input_x A0
#define input_y A1
#define laser 2
#define button 7
#define Servo_xpin 5
#define Servo_ypin 3

bool button_flag=1;

void setup() {
  Servo_x.attach(Servo_xpin);
  delay(200);
  Servo_y.attach(Servo_ypin);
  delay(200);
  
  Serial.begin(9600);
  pinMode(input_x,INPUT);
  pinMode(input_y,INPUT);
  pinMode(laser,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  
  // put your setup code here, to run once:

}

void loop() {
//  bool buttonsta=digitalRead(button);
//  Serial.print("buttonsta:");Serial.println(buttonsta);
//  
//  if(buttonsta==LOW)
//  { 
//    Serial.println("111");
//    delay(20);
/////*此处为错误*/    bool buttondat=digitalRead(button);
/////*此处为错误*/    Serial.print("buttondat_in:");Serial.println(buttondat);
/////*此处为错误*/    while(buttondat==LOW);//等到松开,不等于0跳出while
/*注意应当实时获取按键状态*///    while(digitalRead(button)==LOW);
    
    Serial.println("start!!!");


//    Serial.print("button_flag___iii:");Serial.println(button_flag);
//    button_flag=!button_flag;
//    Serial.print("button_flagssssssss:");Serial.println(button_flag);
//    if(!button_flag)
//    {
//      Serial.print("button_flag___ooo:");Serial.println(button_flag);    
      int indat_x=analogRead(input_x);
      int indat_y=analogRead(input_y);
      int outdat_x=map(indat_x,0,1024,0,180);
      int outdat_y=map(indat_y,0,1024,0,180);
      Servo_x.write(outdat_x);
      delay(10);
      Servo_y.write(outdat_y);
      delay(10);
      
      Serial.print("indat_x: ");Serial.print(indat_x);Serial.print('\t');Serial.print(outdat_x);
      Serial.print('\t');
      Serial.print("indat_y: ");Serial.print(indat_y);Serial.print('\t');Serial.println(outdat_y);
      //delay(500);
//    }
//  }
  Serial.println("turn back!!!");
  // put your main code here, to run repeatedly:

}
