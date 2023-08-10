#define LF 3
#define LR 5
#define RF 6
#define RR 9

char ch;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  pinMode(LF, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RR, OUTPUT);

}

void loop()
{
  if(Serial.available())
  {
    ch = Serial.read();
    
    if(ch == 'W') Forward();
    else if(ch == 'S') Reverse();
    else if(ch == 'D') Right();
    else if(ch == 'A') Left();
  }
  delay(100);
}


void Forward()
{
  Serial.println(ch);
  digitalWrite(LF,HIGH);
  digitalWrite(RF,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RR,LOW);
}

void Reverse()
{
  Serial.println(ch);
  digitalWrite(LR,HIGH);
  digitalWrite(RR,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(RF,LOW);
}

void Right()
{
  Serial.println(ch);
  digitalWrite(LR,HIGH);
  digitalWrite(RF,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(RR,LOW);
}

void Left()
{
  Serial.println(ch);
  digitalWrite(LF,HIGH);
  digitalWrite(RR,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RF,LOW);
}
