#include <Servo.h>

Servo myservo;  
int pos = 0;    

void setup() {
  Serial.begin(9600);
  /***不插也是连接成功***/
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if(myservo.attached())
  {
    int c = myservo.attached();
    Serial.println(c);
    Serial.println("连接成功！");
//    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15);                       // waits 15ms for the servo to reach the position
//      Serial.print(pos);
//      Serial.print('\t');
//      int a = myservo.read();
//      Serial.println(a);
//    }
//    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15);                       // waits 15ms for the servo to reach the position
//      Serial.print(pos);
//      Serial.print('\t');
//      int b = myservo.read();
//      Serial.println(b);
//    }
  }
  else
  {
    Serial.println("连接失败！");  
  }
}

//void loop()
//{
//    for (pos = 2500; pos >= 0; pos -= 1)  // goes from 180 degrees to 0 degrees
//    {
//      /****此种方法不可行，精度太低****/
//      myservo.writeMicroseconds(pos);              
//      delay(100);                    
//      Serial.print(pos);
//      Serial.print('\t');
//      int b = myservo.read();
//      Serial.println(b);
//    }
//}
