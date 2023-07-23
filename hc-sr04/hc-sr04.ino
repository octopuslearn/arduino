#define trig 8//控制
#define echo 9//信号

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(40);
  
  digitalWrite(trig, LOW);

  int value_in=pulseIn(echo, HIGH)/58;//获取高电平-距离
  Serial.println(value_in);
  // put your main code here, to run repeatedly:

}
