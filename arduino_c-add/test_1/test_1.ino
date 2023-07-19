/*弹幕说，构造函数名称和类名称相同*/

class Led{//建立类
  public://在pulic后的是公共成员函数（变量），公共成员函数(变量)可以在类的外面调用
  /*//构造函数-无返回值*/ //注意：构造函数不可在类的外面调用
  //非必须的
    Led();//构造函数  ////执行完这个//Led myLed;建立Led类的对象 后马上执行Led();//构造函数
  /*//析构函数-无返回值*/  //注意：析构函数不可在类的外面调用
  //非必须的
    ~Led();//析构函数 是构造函数前加~  

    Led(int userLedPin);//构造函数-有参数


    void on();//类的成员函数，公共成员函数可以在类的外面调用
    void off();//类的成员函数，公共成员函数可以在类的外面调用
//    int ledPin=2;//公共成员变量
    int getledPin();//测试通过公共成员函数可以在将私有成员变量在类外使用


   private://类外部无法使用但是，类的内部可以使用
    int ledPin=2;//私有成员变量
};

//为构造函数里的变量赋值
//Led::Led(int userLedPin){//参数必须和Led(int userLedPin);//构造函数-有参数一致
//  Serial.println("Led::Led(int userLedPin)---succeed");
//  ledPin = userLedPin;  
//  pinMode(userLedPin,OUTPUT);
//}
/*以下，等同上*/
//为构造函数里的变量赋值
Led::Led(int userLedPin) : ledPin(userLedPin){//参数必须和Led(int userLedPin);//构造函数-有参数一致
  Serial.println("Led::Led(int userLedPin)---succeed");
  pinMode(userLedPin,OUTPUT);
}
/*以上，等同上*/

Led::Led(){//Led()此函数来自Led类
  Serial.println("ssss");
  pinMode(2,OUTPUT);
}
Led::~Led(){
  Serial.println("aaa");
}

void Led::off(){
  digitalWrite(ledPin,LOW);
}

void Led::on(){//on()属于Led类
  digitalWrite(ledPin,HIGH);
}

int Led::getledPin(){
  return ledPin;
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Led myLed;//建立Led类的对象 //有作用域 //故当setup执行完后此对象就没了，但在此之前会检查一下类中有没有析构函数，有的话先执行析构函数再删除
  Led myLed2(7);//控制7号引脚led
  for(int i=0;i<3;i++)
  {
    myLed.on();//检查myLed对象中有无on()函数，有就执行  //此为控制2号引脚
    myLed2.on();                                    //此为控制7号引脚
    delay(1000);
    myLed.off();
    myLed2.off();
    delay(1000);
  }


/*以下，测试公共成员变量可以在类外使用*/
//  int myLed2Pin=myLed.ledPin;
//  Serial.print("myLed2Pin: ");Serial.println(myLed2Pin);
/*以上，测试公共成员变量可以在类外使用*/

/*以下，测试通过公共成员函数可以在将私有成员变量在类外使用*/
  int myLed2Pin=myLed.getledPin();
  Serial.print("myLed2Pin: ");Serial.println(myLed2Pin);
/*以上，测试通过公共成员函数可以在将私有成员变量在类外使用*/
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
