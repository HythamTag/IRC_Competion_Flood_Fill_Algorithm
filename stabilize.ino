void stabilize(int x){

    unsigned long currentMillis = millis();
    unsigned long previousMillis = millis();
    while (currentMillis - previousMillis <= x) {
    currentMillis = millis(); 
    Stable();
    
  }

Stop();


  
}


void Line_Follow(int y){
    unsigned long currentMillis = millis();
    unsigned long previousMillis = millis();
    while (currentMillis - previousMillis <= y) {
    currentMillis = millis(); 
    Line_Following();
  }
}

void Line_Follow_Block(int y){
    unsigned long currentMillis = millis();
    unsigned long previousMillis = millis();
    while (currentMillis - previousMillis <= y) {
    currentMillis = millis(); 
    Line_Following_Block();
  }
}

