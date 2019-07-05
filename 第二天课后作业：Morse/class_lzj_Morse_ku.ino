#include <Morse.h>
int comechar = 0;
int ledpin = 13;
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
Morse morse(13);
void setup() {
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String m = "";
  char sign;
  if (Serial.available() > 0)
  {
    comechar = Serial.read() - 97;
    if (comechar >= 0 && comechar <= 25)
    {
      m = MORSE[comechar];
      m += ' ';
      for (int i = 0;i < 5; i++)
      {
        sign = m[i];
        Serial.print(sign);
        if (sign == '*')
          morse.dot();
        else if (sign == '-')
          morse.dash();
        else if (sign == ' ')
          morse.c_space();
      }
    }
    else if (comechar == ' ' - 97)
    {
      Serial.print("/ ");
      morse.w_space();
    }
  }
}
