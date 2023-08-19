#include "OneButton.h"

#define button1 2

//按下GND有效
OneButton btn1 = OneButton(
  button1,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);


void setup() {
  Serial.begin(9600);

  btn1.setDebounceMs(10);//消抖
  btn1.setClickMs(1500);//用于区分单击和多击，即500ms内记录按下几次
  btn1.setPressMs(3000);//长按时间判定，800ms后算长按
  
  
  btn1.attachClick(btnattachClick);//单击
  btn1.attachDoubleClick(btnattachDoubleClick);//双击
  btn1.attachMultiClick(btnattachMultiClick);//多击
  btn1.attachLongPressStart(btnattachLongPressStart);//按住按键800ms后触发
  // btn1.attachDuringLongPress(btnattachDuringLongPress);//按住按钮定期触发
  btn1.attachLongPressStop(btnattachLongPressStop);//长时间按住按钮松开时触发
  // put your setup code here, to run once:

}

void loop() {
  btn1.tick();
  delay(10);
  // put your main code here, to run repeatedly:
}


void btnattachClick()
{
  Serial.println("单击");
}
void btnattachDoubleClick()
{
  Serial.println("双击");
}
void btnattachMultiClick()
{
  static int button_count = btn1.getNumberClicks();//获取点击次数
  switch(button_count)
  {
    // case 3:Serial.println("3击");break;
    default:Serial.print("点击次数： ");Serial.println(button_count);break;
  }
}
void btnattachLongPressStart()
{
  Serial.println("按住按键800ms后触发");
}
void btnattachDuringLongPress()
{
  Serial.println("按住按钮定期触发");
}
void btnattachLongPressStop()
{
  Serial.println("长时间按住按钮松开时触发");
}
