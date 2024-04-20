// Created by Kamalesh R
// https://wokwi.com/projects/395684159337265153

const int b1 = A0;
const int b2 = A1;
const int b3 = A2;

const int l1 = A3;
const int l2 = A4;
const int l3 = A5;

const int buzz = 13;

int can_vote[]={0,0,0};
int led[] = {A3,A4,A5};

char t;

void setup()
{
  Serial.begin(115200);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  if (digitalRead(b1))
      vote(0);
  if (digitalRead(b2))
      vote(1);
  if (digitalRead(b3))
      vote(2);
  if (Serial. available())
  {
    t=Serial.read();
    if (t=='E')
      end();
  }
}

void vote(int canId)
{
  digitalWrite(led[canId],HIGH);
  can_vote[canId]+=1;
  Serial.println(canId+1);
  delay(7000);
  Serial.println("+++++++++");
  digitalWrite(led[canId],LOW);
  digitalWrite(buzz,HIGH);
  delay(1000);
  digitalWrite(buzz,LOW);
}

void end()
{

  Serial.print("Candidate 1: ");
  Serial.println(can_vote[0]);
  Serial.print("Candidate 2: ");
  Serial.println(can_vote[1]);
  Serial.print("Candidate 3: ");
  Serial.println(can_vote[2]);

  Serial.println("______________");
  Serial.print("Total Vote");
  Serial.println(can_vote[0]+can_vote[1]+can_vote[2]);

  while (1)
  {
    delay(10000);
  }

}

