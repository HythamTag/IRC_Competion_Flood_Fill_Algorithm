

void Scan_All(){
  scan=1;
  Box_Left=0;
  
  Scan_Left(0,2);
  Scan_Right(0,1);
  Scan_Straight(1,1);
  Scan_Right(2,1);
  Scan_Left(2,2);
  Box_Left=1;
  Scan_Straight(3,2);

  if(Box_Left==1)
    Box_Left=0;
    flag=1;
  Scan_Straight(4,2);
  Scan_Right(5,2);
  Scan_Left(5,3);
  Scan_Straight(6,3);
  Scan_Straight(7,3);
  Scan_Left(8,3);
  Scan_Straight(8,2);
  Scan_Straight(8,1);
  Scan_Left(8,0);
  Scan_Left(7,0);
  Scan_Right(7,1);
  Scan_Right(6,1);
  Move_Right();
  Move_Right();
  flag=1;
  Scan_Straight(7,1);
  Scan_Left(7,2);
  Move_Right();
  Move_Right();
  flag=1;
  ///////////////////// 

  Move_Straight();
  Move_Straight();
  Move_Straight();
  flag=1;
  /////////////////////
  Scan_Straight(4,3);
  Scan_Straight(3,3);
  Scan_Right(2,3);
  Move_Left(); 
  flag=1;
  Scan_Left(1,2);  
  

  
  Scan_Right(1,3);
  Scan_Left(0,3); 
  Scan_Left(0,4);
  Scan_Straight(1,4);
  Scan_Straight(2,4);
  Scan_Straight(3,4);
  Scan_Straight(4,4);
  Scan_Straight(5,4);
  Scan_Straight(6,4);
  Scan_Straight(7,4);
  Scan_Straight(8,4);
   










    Serial.println("///////////////////////////////////");
  


   for(int l=8; l>=0; l--)
    {
        for(int k=0; k<=4 ; k++)
        {

            Serial.print(OneZeros[l][k]);
            Serial.print("   ");
        }
        Serial.println("");
        
    }

     Serial.println("");


 Serial.println("///////////////////////////////////");
  scan=0;
}  


void Scan_Straight(int j , int i){
     if(plus==1){
      plus=2;
      Serial.println("Raise Up");
      Box_Left=3;

    unsigned long currentMillis = millis();
    unsigned long previousMillis = millis();
    while (currentMillis - previousMillis <= 300) {
    currentMillis = millis(); 
    Stable();}


      
     Raise_Block_Scan();
     tue=1;
    }
    Move_Straight();
    if(True==1 & tue==0 & Box_Left==1){
    Box_Location[0]=3;
    Box_Location[1]=1;  
    Serial.print(j);
    Serial.print(i); 
    Box_Left=3;   
    }
    
    if ( plus==2){
    Box_Location[0]=j;
    Box_Location[1]=i;
    Buzzer_Block();
    Serial.print("hhhhhhhhhhhhhhhhhhhhhhhhhhh");
    Serial.print(j);
    Serial.print(i);
    plus=3;
    }
    if (flag==0){
      Buzzer_Node();
    }
    OneZeros[j][i]=flag;
   // Serial.print(OneZeros[j][i]);
    flag=1;
    True=0;


  

  
}
void Scan_Backward(int j , int i){

    Move_Backward();
    if (True==1 & flag==0){
    Box_Location[0]=j;
    Box_Location[1]=i;
    Buzzer_Block();
    }
    else if (True==0 & flag==0){
      Buzzer_Node();
    }
    OneZeros[j][i]=flag;
   // Serial.print(OneZeros[j][i]);
    flag=1;
    No_Nodes=0;

  
}
void Scan_Right(int j , int i){
     if(plus==1){
      plus=2;
      Serial.println("Raise Up");
     Raise_Block_Scan();
     tue=1;
    }
    Move_Right();
    
    if ( plus==2){
    Box_Location[0]=j;
    Box_Location[1]=i;
    Buzzer_Block();
    Serial.print("hhhhhhhhhhhhhhhhhhhhhhhhhhh");
    Serial.print(j);
    Serial.print(i);
    plus=3;
    }
    if (flag==0){
      Buzzer_Node();
    }
    OneZeros[j][i]=flag;
   // Serial.print(OneZeros[j][i]);
    flag=1;
    True=0;

}



void Scan_Left(int j , int i){
     if(plus==1){
      plus=2;
      Serial.println("Raise Up");
     Raise_Block_Scan();
     tue=1;
    }
    Move_Left();
    
    if ( plus==2){
    Box_Location[0]=j;
    Box_Location[1]=i;
    Buzzer_Block();
    Serial.print("hhhhhhhhhhhhhhhhhhhhhhhhhhh");
    Serial.print(j);
    Serial.print(i);
    plus=3;
    }
    if (flag==0){
      Buzzer_Node();
    }
    OneZeros[j][i]=flag;
   // Serial.print(OneZeros[j][i]);
    flag=1;
    True=0;


  

  
}
