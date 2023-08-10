#include <Servo.h>
#include <stdio.h>
#define b1 A0
#define b2 A1
#define b3 A2
#define b4 A3
bool S1=false;
bool S2=false;
bool S3=false;
bool S4=false;
int C_1=10;
int C_2=10;
int C_3=10;
int C_4=10;
char in = 0;
Servo ser1;
Servo ser2;
Servo ser3;
Servo ser4;
void setup() {
  ser1.attach(13); 
  ser2.attach(12); 
  ser3.attach(11); 
  ser4.attach(10); 
  Serial.begin(9600);
  count();
}

void loop() {

  ser1.write(0);
  ser2.write(0);
  ser3.write(0);
  ser4.write(0);
  if(Serial.available()!=0)
  {
    in = Serial.read();
    switch(in){
    case '1':
    {
      count();
      break;
    }
    case '2':
    {
      empt();
      break;
    }
    }
  }
  S1=digitalRead(b1);
  S2=digitalRead(b2);
  S3=digitalRead(b3);
  S4=digitalRead(b4);
  if(S1 && C_1>0)  
  {
    ser1.write(180);
    C_1--;
    delay(1500);
  }
  if(S2 && C_2>0)  {
    ser2.write(180);
    C_2--;
    delay(1500);
    }
  if(S3 && C_3>0)  {
    ser3.write(180);
    C_3--;
    delay(1500);
    }
  if(S4 && C_4>0)  {
    ser4.write(180);
    C_4--;
    delay(1500);
    }
  S1=false;
  S2=false;
  S3=false;
  S4=false;
  delay(50);
  if(C_1==0) {disp(1);C_1=-1;}
  if(C_2==0) {disp(2);C_2=-1;}
  if(C_3==0) {disp(3);C_3=-1;}
  if(C_4==0) {disp(4);C_4=-1;}
  }
  void count()
  {
    Serial.println("\n**** List of Items and Count****");
    Serial.print("Item 1: ");
    Serial.println((C_1 == -1)?0:C_1);
    Serial.print("Item 2: ");
    Serial.println((C_2 == -1)?0:C_2);
    Serial.print("Item 3: ");
    Serial.println((C_3 == -1)?0:C_3);
    Serial.print("Item 4: ");
    Serial.println((C_4 == -1)?0:C_4);
    Serial.println();
  }

  void disp(int a)
  {
    Serial.println("\n**** Warnning ****");
    Serial.print("Item ");
    Serial.print(a);
    Serial.println(" is Empty");
    Serial.println();
  }

  void empt()
  {
    Serial.println("\n**** List of Empty Items****");
    if(C_1==-1) Serial.println("Item 1");
    if(C_2==-1) Serial.println("Item 2");
    if(C_3==-1) Serial.println("Item 3");
    if(C_4==-1) Serial.println("Item 4");
    Serial.println();
  }
