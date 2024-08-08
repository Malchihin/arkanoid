void motors(int speed_left, int speed_right) {
  speed_left = constrain(speed_left, -255, 255);
  speed_right = constrain(speed_right, -255, 255);

  if (speed_left >= 0) {
    digitalWrite(Motor1_1, LOW);
    analogWrite(Motor1_2, speed_left);
  } 
  else {
    digitalWrite(Motor1_1, HIGH);
    analogWrite(Motor1_2, abs(speed_left));
  }

  if (speed_right >= 0) {
    digitalWrite(Motor2_1, LOW);
    analogWrite(Motor2_2, speed_right);
  } else {
    digitalWrite(Motor2_1, HIGH);
    analogWrite(Motor2_2, abs(speed_right));
  }
}

void punch() {
  digitalWrite(8, 0);
  delay(50);
  digitalWrite(9, 1);
  delay(50);
  digitalWrite(9, 0);
  upr[1]=0;
}

void left(){
  motors(0,0);
  sleep(100);
  motors(-100, -100);
}

void right(){
  // motors(0,0);
  sleep(1000);
  motors(100, 100);
}



void punchWarn(){
  kick = 1;
}

void servoR() {
  for(pos;pos<125;pos++)
  myservo.write(pos);
}

void servoL() {
  for(pos;pos>75;pos--)
  myservo.write(pos);
}

void sleep(int i){
  delay(i);
}

// void err(){
//   sleep(2000);
//   motors(100,100);
//   sleep(2000);
//   motors(-100,-100);
//   sleep(1000);
//   motors(0,0);
//   sleep(1000);
  
//   kick=0;
// }
