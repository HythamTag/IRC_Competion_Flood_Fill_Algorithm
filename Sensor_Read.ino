int speeed = 255;

void Sensor_Read(){
 //  unsigned long currentMillis = millis();
// previousMillis = millis();
 
 // while (currentMillis - previousMillis <= 50) {
      RRR=!digitalRead(33);
      RR=!digitalRead(45);
      r=!digitalRead(47);
      M=!digitalRead(49);
      l=!digitalRead(51);
      LL=!digitalRead(53);
      LLL=!digitalRead(35);
      BR=!digitalRead(11);
      BL=!digitalRead(10);
      
     for(int i=0;i<=7;i++)
    if(M==1)
      {
      RRR=!digitalRead(33);
      RR=!digitalRead(45);
      r=!digitalRead(47);
      M=!digitalRead(49);
      l=!digitalRead(51);
      LL=!digitalRead(53);
      LLL=!digitalRead(35);
      BR=!digitalRead(11);
      BL=!digitalRead(10);
      
      
      }

    /*  
Serial.print(LLL);
Serial.print(LL);
Serial.print(l);
Serial.print(M);
Serial.print(r);
Serial.print(RR);
Serial.print(RRR);
Serial.print(BL);
Serial.println(BR);
*/

}

void Forward(){
  digitalWrite(7,1);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(6,0);
}

void Backward(){
  digitalWrite(7,0);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(6,1);
}

void Right(){
  digitalWrite(7,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(6,1);
}

void Left(){
  digitalWrite(7,0);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(6,0);
}

void Stop(){
  digitalWrite(7,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(6,0);
}

void Line_Following() {
   Sensor_Read();
   if( (LLL==0 & RRR==0) & ((M==1 & r==1) | (M==1 & l==1)) & scan==1){
    Sensor_Read();
     
      if(LLL==1&RRR==0)
        Right_Moves(speeed,150);   
        
      else if(LLL==0&RRR==1)
       Left_Moves(speeed,150);  
           
      else if(LL==1&RR==1)
        Forward_Moves(speeed);
    
      else if(LL==0&RR==0)
        Forward_Moves(speeed);
    
      else if(LL==1&RR==0)
        Right_Moves(speeed,90);   
        
      else if(LL==0&RR==1)
       Left_Moves(speeed,90);
       
   }
  


   
   else{  
      Sensor_Read();
      
      if(LLL==1&RRR==0)
        Right_Moves(speeed,150);   
        
      else if(LLL==0&RRR==1)
       Left_Moves(speeed,150);  
           
      else if(LL==1&RR==1)
        Forward_Moves(speeed);
    
      else if(LL==0&RR==0)
        Forward_Moves(speeed);
    
      else if(LL==1&RR==0)
        Right_Moves(speeed,90);   
        
      else if(LL==0&RR==1)
       Left_Moves(speeed,90);
       }

  
}


void Back_Line_Following(){ 
  Sensor_Read();
  while(BL==1 || BR==1){
   Sensor_Read();
  if(LL==1&RR==1)
    Backward();

  else if(LL==0&RR==0)
    Backward();

  else if(LL==1&RR==0)
    Right();   
    
  else if(LL==0&RR==1)
   Left();
  }
  Stop();

}

void Line_Following_Block(){
   Sensor_Read();
  if(LL==1&RR==1)
    Forwards(120);

  else if(LL==0&RR==0)
    Forwards(120);

  else if(LL==1&RR==0)
    Rights(120);   
    
  else if(LL==0&RR==1)
   Lefts(120);

  
}
/*
void Back_Line_Stability()
{
  
}*/

void Stable()
{
   Sensor_Read();
  if(LL==1&RR==1)
    Stop();

  else if(LL==0&RR==0)
     Stop();

  else if(LL==1&RR==0)
    Rights(70);   
    
  else if(LL==0&RR==1)
   Lefts(70);

  
}
