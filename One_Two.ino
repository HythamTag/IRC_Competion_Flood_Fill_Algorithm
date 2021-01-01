int Rotation_Speed = 255;
int Slow_Turn_Speed= 200;
int time_Millis = 200;


void ss1(){ 
Stop();



if(scan==1 & Box_Left==1)
  Stop();
else {
  while (BL==0 || BR==0){
    Line_Following();
}

 //stabilize(200);
Stop();
}



  




  
}

void LL1(){
Stop();

 Backwards(255);
 delay(150);
 Stop();
 stabilize(300);
 
Sensor_Read();
M=0;
while(M==0){
  Sensor_Read();
  Lefts(Rotation_Speed);
  delay(100);
}
delay(100);
Sensor_Read();
while(M==1){
  Sensor_Read();
  Lefts(Rotation_Speed);
  if (M ==0){
     Rights(Slow_Turn_Speed);
     delay(100);}
}

Stop();

  while (BL==0 || BR==0){
    Line_Following();
}
  stabilize(200);
  Line_Follow(time_Millis);

Stop();

  
}






void RR1(){
Stop();
 Backwards(255);
 delay(150);
 Stop();
 stabilize(300);


Sensor_Read();
M=0;
while(M==0){
  Sensor_Read();
  
  Rights(Rotation_Speed);
  delay(100);
}
delay(100);

Sensor_Read();
M=1;
while(M==1){
  Sensor_Read();
  Rights(Rotation_Speed);
   if (M ==0){
     Lefts(Slow_Turn_Speed);
     delay(100);}
    
}

Stop();

  while (BL==0 || BR==0){
    Line_Following();
}

 stabilize(200);
 Line_Follow(time_Millis);

 Stop();



}


