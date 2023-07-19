#include <Arduino.h>
#ifndef __LED_H_//头文件可存放类的声明 //此语句的作用是防止重复定义
#define __LED_H_



/*以下，类的声明*/
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
    void change_ledPin(int userLedPin);

   private://类外部无法使用但是，类的内部可以使用
    int ledPin=2;//私有成员变量
};
/*以上，类的声明*/

//class PwmLed : protected Led  //protected-描述子类和父类的继承类型的
//class PwmLed : private Led  //private-描述子类和父类的继承类型的


class PwmLed : public Led{//子类PwmLed继承自父类Led   public-描述子类和父类的继承类型的 /*这种最常用*/
//只能继承Led的公共成员
//继承自父类的成员在子类中也是公共的成员   
};//就算子类中啥也没有但不响使用

#endif
