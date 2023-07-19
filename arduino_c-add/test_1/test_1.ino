class Led{//建立类
  public://在pulic后的是公共成员函数，公共成员函数可以在类的外面调用
  /*//构造函数-无返回值*/ //注意：构造函数不可在类的外面调用
  //非必须的
    Led();//构造函数  ////执行完这个//Led myLed;建立Led类的对象 后马上执行Led();//构造函数
  /*//析构函数-无返回值*/  //注意：析构函数不可在类的外面调用
  //非必须的
    ~Led();//析构函数 是构造函数前加~  

    void on();//类的成员函数，公共成员函数可以在类的外面调用
    void off();//类的成员函数，公共成员函数可以在类的外面调用
};


Led::Led(){//Led()此函数来自Led类
  Serial.println("ssss");
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
}
Led::~Led(){
  Serial.println("aaa");
}

void Led::off(){
  digitalWrite(2,LOW);
}

void Led::on(){//on()属于Led类
  digitalWrite(2,HIGH);
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Led myLed;//建立Led类的对象 //有作用域 //故当setup执行完后此对象就没了，但在此之前会检查一下类中有没有析构函数，有的话先执行析构函数再删除
  for(int i=0;i<3;i++)
  {
    myLed.on();//检查myLed对象中有无on()函数，有就执行
    delay(1000);
    myLed.off();
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
