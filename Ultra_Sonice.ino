



void Buzzer_Node()
{

    unsigned long currentMillis = millis();
  unsigned long previousMillis = millis();
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis(); 
      digitalWrite(22,1);
      Stable();
  }
  digitalWrite(22,0);



}





void Buzzer_Block()
{
 unsigned long currentMillis = millis();
  unsigned long previousMillis = millis();
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis(); 
      digitalWrite(22,1);
      Stable();
  }
  


 previousMillis = currentMillis;
  currentMillis = millis();
  previousMillis = millis();

  
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis(); 
      digitalWrite(22,0);
      Stable();
  }
  
  previousMillis = currentMillis;
  digitalWrite(22,0);
  Stable();




  
  previousMillis = currentMillis;
  currentMillis = millis();
  previousMillis = millis();

  
  while (currentMillis - previousMillis <= 300) {
      currentMillis = millis(); 
      digitalWrite(22,1);
      Stable();
  }
  
  previousMillis = currentMillis;
  digitalWrite(22,0);
  Stable();
}











void Beep(){
  unsigned long currentMillis = millis();
  unsigned long previousMillis = millis();
  while (currentMillis - previousMillis <= 300) {
    currentMillis = millis(); 
    Stable();
  }
  delay(200);
  digitalWrite(22,1);
  delay(200);
  digitalWrite(22,0);
  delay(200);
}

void Beep1(){
 

  digitalWrite(22,1);
  delay(100);
  digitalWrite(22,0);
  delay(100);
}


void Long_Beep(){
  digitalWrite(22,1);
  delay(800);
  digitalWrite(22,0);
  
}





