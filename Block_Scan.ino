int delay_time =150;


void Move_Straight(){
  
Line_Following();
int Cross_Section = 0;
int dis=0;
int done_once=0;
while(Cross_Section==0)
{
  Line_Following();
  if(LLL==0 & RRR==0 & done_once==0){
    if((LL==1 && M==1)  ||  (l==1 && M==1)   ||(r==1 && M==1) ||  (RR==1 && M==1) ||(LLL==1 && LL==1) || (RRR==1 & RR==1) || LLL==1 || RRR==1){
       flag=0;

     
    }
   
    done_once=1;

  }
    
  if (BL==0 & BR==0)
    Cross_Section=1; 
}

Stop();
/*delay(50);
digitalWrite(buzzer,1);
delay(50);
digitalWrite(buzzer,0);
*/
ss1();
//Serial.println("Cross");
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////






    if(scan==1 & Box_Left==0 & tue==0)
    {   // Serial.println("NoLeft");
  
      if(digitalRead(Prox_Far)==0){
          plus+=1;
          Box_Left=3;
          stabilize(300);
      }
    }
    else if(scan==1 & Box_Left==1)
    {

       if(digitalRead(Prox_Far)==0){
           plus=3;
          stabilize(300);
     }
    else
     Left_Right();
    }
}

void Move_Backward(){
    
Sensor_Read();
Line_Following();
flag = M;
int Cross_Section = 0;
char x=1;
char y=0;
int finish=0;
int done_once=0;
while(Cross_Section==0)
{
  Line_Following();
  if(LLL==0 & RRR==0 & done_once==0){
    if((LL==1 && M==1)  ||  (l==1 && M==1)   ||(r==1 && M==1) ||  (RR==1 && M==1)){
       flag=0;
    }
      done_once=1;

  }
  if (BL==0 && BR==0)
    Cross_Section=1;
}


Sensor_Read();
while(M==0){
  Sensor_Read();
  Lefts(170);

}




while(M==1){
  Sensor_Read();
  Lefts(170);
}


while(M==0){
  Sensor_Read();
  Lefts(170);

}


while(M==1){
  Sensor_Read();
  Lefts(170);
    if (LL ==0)
     Lefts(0);


}

Line_Follow(300);
Stop();


}

void Move_Left(){ 

    
Line_Following();
int Cross_Section = 0;
int dis=0;
int done_once=0;
while(Cross_Section==0)
{
  Line_Following();
  if(LLL==0 & RRR==0 & done_once==0){
    if((LL==1 && M==1)  ||  (l==1 && M==1)   ||(r==1 && M==1) ||  (RR==1 && M==1) ||(LLL==1 && LL==1) || (RRR==1 & RR==1)|| LLL==1 || RRR==1){
       flag=0;
    }
      done_once=1;

  }
  if (BL==0 & BR==0)
    Cross_Section=1; 
}

//Stop();
/*delay(50);
digitalWrite(buzzer,1);
delay(50);
digitalWrite(buzzer,0);
*/
LL1();
//Serial.println("Cross");
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////






    if(scan==1 & Box_Left==0 & tue==0)
    {   // Serial.println("NoLeft");
  
      if(digitalRead(Prox_Far)==0){
          plus+=1;
          Box_Left=3;
          stabilize(300);
      }
    }

}

void Move_Right(){ 

    
Line_Following();
int Cross_Section = 0;
int dis=0;
int done_once=0;
while(Cross_Section==0)
{
  Line_Following();
  if(LLL==0 & RRR==0 & done_once==0){
    if((LL==1 && M==1)  ||  (l==1 && M==1)   ||(r==1 && M==1) ||  (RR==1 && M==1) ||(LLL==1 && LL==1) || (RRR==1 & RR==1)|| LLL==1 || RRR==1){
       flag=0;
       done_once=1;
    }
    else
      done_once=1;

  }
  if (BL==0 & BR==0)
    Cross_Section=1; 
}

Stop();
/*delay(50);
digitalWrite(buzzer,1);
delay(50);
digitalWrite(buzzer,0);
*/
RR1();
//Serial.println("Cross");
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////






    if(scan==1 & Box_Left==0 & tue==0)
    {   // Serial.println("NoLeft");
  
      if(digitalRead(Prox_Far)==0){
          plus+=1;
          Box_Left=3;
          stabilize(300);
      }
    }

}

void Raise_Block_Scan(){
servo1_lift1.write(5);
servo1_catch.write(50);
while(digitalRead(Prox_Close)==1)
{ 
  Line_Following_Block();
}
//////Pick Block
  Line_Follow_Block(100);
  Stop();
  Servo1();
  delay(300);
  //Back_Line_Following();
}

void Raise_Block1(){
  servo1_lift1.write(5);
  stabilize(500);
while(digitalRead(Prox_Close)==1)
{
  Line_Following_Block();
}
//////Pick Block
  Line_Follow_Block(100);
  Stop();
  stabilize(300);
     

  Servo1();
  delay(300);
  //Back_Line_Following();
   Sensor_Read();
  while(BL==1 || BR==1){
    Serial.println("Back");
   Sensor_Read();
   Backwards(170);
  }
  stabilize(500);
}

void Leave_Block(){
  Sensor_Read();
  

  while(BL==1 || BR==1){
   Sensor_Read();
   Backwards(120);
  }
  stabilize(1000);
  while(LL==1 || RR==1){
   Sensor_Read();
   Line_Following_Block();
  }
  Backwards(120);
  delay(250);
  Stop();
  delay(300);


  Servo2();
  delay(300);



  while(BL==1 || BR==1){
   Sensor_Read();
   Backwards(120);
  }

 Stop();

while(digitalRead(Prox_Far)==0)
  {

  
  stabilize(500);
  int Distance_Done=0;
  

    long currentMillis = millis();
    long previousMillis = millis()+3000;
    int diff =currentMillis - previousMillis ;
    while (Distance_Done==0) {
      if((currentMillis - previousMillis )>= 0)
        Distance_Done=1;
       currentMillis = millis();

       if(digitalRead(Prox_Far)==0)
       previousMillis = currentMillis+3000;


      Stop();
    }



    servo1_catch.write(100);


  }





  
  
}

void Open_Gate(){

  Stop();
     long currentMillis = millis();
   long previousMillis = millis();
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis(); 
      Stable();

  }

  
  
}

void Wait_Manuel(){

  
  
  servo1_catch.write(40);
  
  int flag=0;
  while(BL==1 || BR==1){
    Serial.println("Back");
   Sensor_Read();
   Backwards(170);
  }
    stabilize(1000);
    Stop();







   
  while(digitalRead(Prox_Far)==1)
  { } 

 int Distance_Done=0;
  
  if(digitalRead(Prox_Far)==0){
    
     long currentMillis = millis();
     long previousMillis = millis()+3000;
    int diff =currentMillis - previousMillis ;
    while (Distance_Done==0) {
      if((currentMillis - previousMillis )>= 0)
        Distance_Done=1;
      currentMillis = millis();


      if (digitalRead(Prox_Far)==0)
        previousMillis = currentMillis+3000;
        
      Stop();
    }


  while(BL==0 || BR==0){
    Serial.println("Back");
   Sensor_Read();
   Line_Following();
  }

    Line_Follow_Block(1000);
   




  
    
  }
  
Serial.println("Done");
  
}
