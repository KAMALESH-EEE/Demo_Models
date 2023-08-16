/*
This project done by KAMALESH R
GitHub Link 
Social Distance Monitor
*/

#define buzz A0
#define echo 3
#define trig 4

double duration; 
int distance;
void setup()   
{  
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);  
  Serial.begin(9600); 
} 

void loop()
{
  distance = dis();
  if(distance<20)
  {
  digitalWrite(buzz,HIGH);
  Serial.println("!Warning!");
  }
  delay(1000);
  digitalWrite(buzz,LOW);
}

double dis()   
{   
  digitalWrite(trig, LOW);  
  delayMicroseconds(4);  
  digitalWrite(trig, HIGH);  
  delayMicroseconds(15);  
  digitalWrite(trig, LOW);    
  duration = pulseIn(echo, HIGH);    
  return duration*(0.034/2);   
} 
