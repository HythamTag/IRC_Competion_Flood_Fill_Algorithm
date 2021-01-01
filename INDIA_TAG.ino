//col 1 raw 3,4,5
// prox 5 close,9 far
#include <Servo.h>
#include <DueFlashStorage.h>
DueFlashStorage dueFlashStorage;

int plus=0;
int No_Nodes=0;int True=0;int scan=0; int Detect_Node=0;
int Prox_Close=5;int Prox_Far=9;int buzzer=22;
int Box_Left=0; int tue=0;
int LL;int RR;int M;int BL;int BR;int l;int r;int LLL;int RRR;int IRC_CUNT=0;
int flag=1;
int Line_Following_Time=200;
int increment=0;
int Raise_Block=0;

//True :There is Box In LEft
 /*int OneZeros[9][6] =  {{0, 1, 1, 0, 1, 0},
                        {0, 0, 1, 1, 1, 0},
                        {0, 1, 1, 0, 1, 1},
                        {0, 0, 1, 0, 1, 0},
                        {0, 0, 1, 0, 1, 0},
                        {0, 0, 0, 1, 1, 0},
                        {1, 0, 0, 0, 1, 0},
                        {1, 1, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1, 0}};
                                
*/
int OneZeros[9][6]={};   
                   
long duration;int distance;



Servo servo1_catch; // create servo object to control a servo
Servo servo1_lift1;
Servo servo1_lift2;




int GATE[2]={4,4};
int Wait_Manual[2]={8,4};
int Box_Location[2]={3,1};
int Box_Dotnation[2]={2,5};
int Box2_Location[2]={5,0};
int Box2_Dotnation[2]={6,2};


int IRC[3][100]= {};


int Before_Last_Location[2]={};
int Last_Location[2]={};


 int start[2]= {0,2};
 int finish[2] ={8,0};




unsigned long previousMillis = 0;  



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(33,INPUT);
pinMode(35,INPUT);
pinMode(53,INPUT);
pinMode(51,INPUT);
pinMode(49,INPUT);
pinMode(47,INPUT);
pinMode(45,INPUT);
pinMode(53,INPUT);


pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(22, OUTPUT); // Sets the trigPin as an Output
pinMode(24, INPUT); // Sets the echoPin as an Input
pinMode(46,OUTPUT);
pinMode(24, INPUT_PULLUP);



servo1_catch.attach(13);
servo1_lift1.attach(12);

servo1_catch.write(100);
servo1_lift1.write(60);



while(digitalRead(24)==1){}
delay(100);
int verv=0;
int toto=0;
int after = millis();
while(digitalRead(24)==0){}
delay(400);
while(verv==0){

  int read1 = digitalRead(34);
  while(digitalRead(24)==1){}
  read1 = digitalRead(24);
  int before=millis();
  while(read1==0){
    delay(50);
    read1 = digitalRead(24);
    after = millis();
    toto=1; 
    if((after-before)>=1000)
    read1=1;
    }
    
  if((after-before)>=1000 & toto==1){
    verv=1;
    Long_Beep();
  }
  else if((after-before)<1000 & toto==1){
    
    if(increment ==4)
      increment=0;
    for(int i=0;i<=increment;i++)
      Beep1();
     increment++;
    }
  
}

Serial.println(increment);



if(increment==0){
  Serial.println("scan");
  delay(3000);
      while (BL==0 || BR==0)
    Line_Following();
    Sensor_Read();
      Line_Follow(300);
  



  
  Scan_All();
  IRC_Complete_Move();
  for (int i=0;i<=IRC[2][0];i++)
    dueFlashStorage.write(i+6,IRC[0][i]);
    dueFlashStorage.write(5,IRC[2][0]);
    dueFlashStorage.write(0,0);
    Long_Beep();
}
else
  {
    delay(3000);
    while (BL==0 || BR==0)
    Line_Following();
    Sensor_Read();
    unsigned long currentMillis = millis();
    unsigned long previousMillis = millis();
 
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis();
      Line_Following();
  }
  

    IRC_Move();
  }


/*

delay(3000);
scan=1;
//Box_Left=1;
Scan_Straight(0,0);
Scan_Straight(1,0);
Scan_Straight(2,0);
Stop();*/
/*delay(3000);
//Scan_All();
IRC_Complete_Move();*/
/*
delay(5000);
scan=0;
Move_Straight();
Move_Left();
Move_Right();
Move_Right();
Move_Right();
Move_Straight();
Move_Straight();
Serial.println("Done");
Stop();
*/
}

void loop() {
  //Serial.print(digitalRead(5));
   // Serial.println(digitalRead(9));
  // put your main code here, to run repeatedly:

//
//digitalWrite(22,1);
Sensor_Read();
//digitalWrite(22,1);
//Serial.print(digitalRead(7));
//Serial.print(digitalRead(6));
//Serial.print(digitalRead(5));
//Serial.print(digitalRead(4));
//Serial.print(digitalRead(3));
//Serial.print(digitalRead(2));

//Serial.println(digitalRead(9));

//Serial.println(digitalRead(24));


}
