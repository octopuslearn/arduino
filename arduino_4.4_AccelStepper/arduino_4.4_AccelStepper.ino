///*变速运动，加速减速*/
//#include <AccelStepper.h>
//AccelStepper Stepper1(4,2,4,3,5);
//void setup() {
//  pinMode(A0,INPUT);
///*强烈注意：串口输出函数会严重降低程序运行速度，在此库中甚至使得最大速度和加速度无用*/  //Serial.begin(9600);
//  Stepper1.setMaxSpeed(1000.0);
//  Stepper1.setAcceleration(500.0);
//  // put your setup code here, to run once:
//
//}
//
//void loop() {
//  int in_x=analogRead(A0);
//  Stepper1.moveTo(in_x);
//  Serial.print("in_x: "); Serial.println(in_x);
//  int now_currentPosition=Stepper1.currentPosition();
//  Serial.print("now_currentPosition: "); Serial.println(now_currentPosition);
//  Stepper1.run();
//
//}

/*匀速运动*/
#include <AccelStepper.h>
AccelStepper Stepper1(4,2,4,3,5);
void setup() {
  pinMode(A0,INPUT);
/*强烈注意：串口输出函数会严重降低程序运行速度，在此库中甚至使得最大速度和加速度无用*/  //Serial.begin(9600);
  Stepper1.setMaxSpeed(1000.0);//设置电机最大速度
  Stepper1.setSpeed(600);//初始化电机速度
  // put your setup code here, to run once:

}

void loop() {
//  int in_x=analogRead(A0);
/*强烈注意：此处无用*/  //Stepper1.moveTo(1024);
/*强烈注意：匀速模式用runSpeed*/  Stepper1.runSpeed();

}
