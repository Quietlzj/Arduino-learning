int comechar = 0;
int ledpin = 13;
void dot()             //'*'
{
  digitalWrite(ledpin,HIGH);
  delay(250);
  digitalWrite(ledpin, LOW);
  delay(250);
}
void dash()            //'-'
{
  digitalWrite(ledpin, HIGH);
  delay(1000);
  digitalWrite(ledpin, LOW);
  delay(250);
}
void space()           //间隔
{
  delay(3000);
}
char MORSE[][5] = {
  {'*', '-'},           //A
  {'-', '*', '*', '*'}, //B
  {'-', '*', '-', '*'}, //C
  {'-', '*', '*'},      //D
  {'*'},                //E
  {'*', '*', '-', '*'}, //F
  {'-', '-', '*'},      //G
  {'*', '*', '*', '*'}, //H
  {'*', '*'},           //I
  {'*', '-', '-', '-'}, //J
  {'-', '*', '-'},      //K
  {'*', '-', '*', '*'}, //L
  {'-', '-'},           //M
  {'-', '*'},           //N
  {'-', '-', '-'},      //O
  {'*', '-', '-', '*'}, //P
  {'-', '-', '*', '-'}, //Q
  {'*', '-', '*'},      //R
  {'*', '*', '*'},      //S
  {'-'},                //T
  {'*', '*', '-'},      //U
  {'*', '*', '*', '-'}, //V
  {'*', '-', '-'},      //W
  {'-', '*', '*', '-'}, //X
  {'-', '*', '-', '-'}, //Y
  {'-', '-', '*', '*'}, //Z
};
void setup() 
{
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  String morse = "";
  char sign;
  if (Serial.available() > 0)
  {
    comechar = Serial.read() - 97;
    if (comechar >= 0 && comechar <= 25)
    {
      morse = MORSE[comechar];
      morse += ' ';
      for (int i = 0;i < 5; i++)
      {
        sign = morse[i];
        if (sign == '*')
          dot();
        else if (sign == '-')
          dash();
        Serial.print(sign);
      }
      //Serial.print(morse);
    }
    else
    Serial.println();
    space();
  }
}
