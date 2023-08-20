long seconds = 0;

void setup()
{
  Serial.begin(9600);
//  seconds = 24*60*60;//19:29:46.231 -> 20864,,,明显错误了正确结果是86400。
  //错误的理由是24*60*60是整数相乘结果是整数，86400超了整数范围，所以是20864
  /*解决办法，24*60*60L加个L*/
  seconds = 24*60*60L;
  Serial.println(seconds);
}

void loop()
{

}
