
/*错误*/  //Led myLed;//全局对象
            //a在此处创建对象报错



class Led{//规定类的名称第一个字母大写
  public:
    Led();//构造函数//a这种都没有返回值这种东西//构造函数和析构函数不必非得出现 
          //a不能在类的外面调用表
/*注意：构造函数的参数是有数据类型的*/    Led(int userledPin);//有参数的构造函数
    
    ~Led();//析构函数
           //a不能在类的外面调用表
    void on();//公共成员函数，即可以在类的外面调用
    
    void off();//公共成员函数，即可以在类的外面调用
    int ledPin=2;//公共成员变量
};//分号表示类结束



//Led myLed;//全局对象
//          //a在此处创建对象不报错

Led::Led(){//::说明了构造函数Led()来自Led类；()说明了参数，此处无参数
  Serial.println("AAAAAAA");//{}构造函数的内容
  pinMode(2,OUTPUT);
}
Led::Led(int userledPin):/*此为方法2.*/ledPin(userledPin){
/*此为方法1.*/  //  ledPin=userledPin;
  pinMode(ledPin,OUTPUT);
}


Led::~Led(){
  Serial.println("BBBBBBB");
}


void Led::on()
{
  digitalWrite(ledPin,LOW);
}


void Led::off(){
  digitalWrite(ledPin,HIGH);
}

void setup() {
  Serial.begin(9600);
  Led myLed;//建立对象,Led类的对象，局部对象//a对象也有作用域，类似于局部变量和全局对象
            //b建立对象后立马会调用构造函数Led();
            //c执行完void setup()中的所有语句后，将这个局部对象Led myLed;删除，在删除前立马检测这个对象有无析构函数，若有则立马执行~Led();析构函数   
/*建对象时就要写入*/  Led myLed2(7);//a创建对象时就要写入
  // put your setup code here, to run once:
  Serial.println("CCCCCCCC");
  for(int i=0;i<3;i++)
  {
    myLed.on();
/*7不是从这里写的，而是创建对象时写的*/    //myLed2.on(7);
    myLed2.on();
    delay(1000);
    myLed.off();
    myLed2.off();
    delay(1000);
  }
}

void loop() {
//  for(int i=0;i<3;i++)//公共成员函数可以在类外使用
//  {
//    myLed.on();
//    delay(1000);
//    myLed.off();
//    delay(1000);
//  }
////  Led myLed;//全局对象就可在任何地方使用
/*???不是说构造函数、析构函数都不能在其他地方使用吗？？？
为何构造函数不报错且能用。而析构函数不可以*/  //Led();

/*错误：析构函数编译报错*/ // ~Led();
  // put your main code here, to run repeatedly:

}
