
void Left_Right(){
 
int Rotation_Speed = 150;
int Slow_Turn_Speed= 0;
int time_Millis = 50; 
Backwards(150);
 delay(100);
 Stop();

stabilize(300);

Sensor_Read();
while(M==0){
  Sensor_Read();
  Lefts(Rotation_Speed);

}
delay(200);

while(M==1){
  Sensor_Read();
  Lefts(Rotation_Speed);
  if (LL ==0)
     Lefts(Slow_Turn_Speed);
}

Stop();


 stabilize(500);


Stop();

////////////////////////////////////////////////////////////////////////////


 if(digitalRead(Prox_Far)==0){
  True=1;
  Buzzer_Block();

 }



//////////////////////////////////////////////////////////////////////////////
Sensor_Read();
while(M==0){
  Sensor_Read();
  Rights(Rotation_Speed);

}
delay(200);


while(M==1){
  Sensor_Read();
  Rights(Rotation_Speed);
    if (RR ==0)
     Rights(Slow_Turn_Speed);

}

Stop();



 stabilize(500);

  Sensor_Read();
  while (BL==0 || BR==0){
    Line_Following();
}

     Line_Follow(500);
  


  
}

