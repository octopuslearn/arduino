class Led{//建立类
  public:
    Led();//构造函数  ////执行完这个//Led myLed;建立Led类的对象 后马上执行Led();//构造函数

};


Led::Led(){//Led()此函数来自Led类
  Serial.println("ssss");
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Led myLed;//建立Led类的对象
}

void loop() {
  // put your main code here, to run repeatedly:

}
