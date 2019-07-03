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
  delay(750);
  digitalWrite(ledpin, LOW);
  delay(250);
}
void c_space()           //char间隔
{
  delay(750);
}
void w_space()
{
  delay(1750);
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
        Serial.print(sign);
        if (sign == '*')
          dot();
        else if (sign == '-')
          dash();
        else
          c_space();
      }
    }
    else if (comechar == ' ' - 97)
    Serial.print("/ ");
    w_space();
  }
}
