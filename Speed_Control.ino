
void Forwards(int speed){
  analogWrite(7,speed);
  analogWrite(3,0);
  analogWrite(4,speed);
  analogWrite(6,0);
}

void Backwards(int speed){
  analogWrite(7,0);
  analogWrite(3,speed);
  analogWrite(4,0);
  analogWrite(6,speed);
}

void Lefts(int speed){
  analogWrite(7,speed);
  analogWrite(3,0);
  analogWrite(4,0);
  analogWrite(6,speed);
}

void Rights(int speed){
  analogWrite(7,0);
  analogWrite(3,speed);
  analogWrite(4,speed);
  analogWrite(6,0);
}



void Forward_Moves(int speed){
  analogWrite(7,speed);
  analogWrite(3,0);
  analogWrite(4,speed);
  analogWrite(6,0);
}

void Backward_Moves(int speed){
  analogWrite(7,0);
  analogWrite(3,speed);
  analogWrite(4,0);
  analogWrite(6,speed);
}

void Left_Moves(int speed,int x){
  analogWrite(7,speed);
  analogWrite(3,0);
  analogWrite(4,speed-x);
  analogWrite(6,0);
}

void Right_Moves(int speed,int x){
  analogWrite(7,speed-x);
  analogWrite(3,0);
  analogWrite(4,speed);
  analogWrite(6,0);
}
