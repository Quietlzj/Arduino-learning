int leftpin = 11;
int rightpin = 12;
int income = 0;
void setup()
{
  pinMode(leftpin, OUTPUT);
  pinMode(rightpin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available() > 0)
  {
    income = Serial.read();
    ledstart();
    switch(income)
    {
      case 'f':
      forward();Serial.println("forward");break;
      case 'b':
      back();Serial.println("back");backled();break;
      case 'l':
      left();Serial.println("left");leftled();break;
      case 'r':
      right();Serial.println("right");rightled();break;
     }
  }
}
void back()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);  
}
void forward()
{
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}
void right()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}
void left()
{
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}
void backled()
{
  digitalWrite(leftpin,HIGH);
  digitalWrite(rightpin,HIGH);
}
void leftled()
{
  digitalWrite(leftpin,HIGH);
}
void rightled()
{
  digitalWrite(rightpin,HIGH);
}
void ledstart()
{
  digitalWrite(leftpin,LOW);
  digitalWrite(rightpin,LOW);
}
