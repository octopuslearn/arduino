int a[200] = {0};//200*2 = 400 bytes
void setup()
{
  Serial.begin(9600);
  Serial.println("");//RAM-188

  //在没有for这条语句前RAM-188,有了for这条语句后RAM-588
  //这是因为编译器看到变量a声明，但是没有使用（即没有for）时将变量a给删除了
  for(int i : a) Serial.println(i);//RAM-588(188+400)
}

void loop()
{

}
