int A = 10;
int B = 11;
int C = 12;
int D = 13;
int income = 0;
int i = 0, n;
void setup()
{
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
    income = Serial.read() - '0';
    n = income;
    i = 0;
    int digitalled[4] = {0, 0, 0, 0};
    do {
        digitalled[i++] = n % 2;
        n /= 2;
    } while(n != 0) ;
    digitalWrite(A, digitalled[0]);
    digitalWrite(B, digitalled[1]);
    digitalWrite(C, digitalled[2]);
    digitalWrite(D, digitalled[3]);
    delay(1000);
  }
}
