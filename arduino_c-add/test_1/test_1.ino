class Led{//建立类
  public:
    Led();//构造函数  ////执行完这个//Led myLed;建立Led类的对象 后马上执行Led();//构造函数
    ~Led();//析构函数 是构造函数前加~  
};


Led::Led(){//Led()此函数来自Led类
  Serial.println("ssss");
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
}
Led::~Led(){
  Serial.println("aaa");
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  Led myLed;//建立Led类的对象 //有作用域 //故当setup执行完后此对象就没了，但在此之前会检查一下类中有没有析构函数，有的话先执行析构函数再删除
}

void loop() {
  // put your main code here, to run repeatedly:

}
