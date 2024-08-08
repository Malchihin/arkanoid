#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
int pos = 100;

long timer = 0;
byte i_per = 2;
int upr[3] = { 0 };


int err = 0;
byte napr = 1;
byte kick = 0;
byte serv = 0;


#define Motor1_1 4
#define Motor1_2 5

#define Motor2_1 7
#define Motor2_2 6

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  SoftwareSerial Serial1 (0, 1);
  Serial.begin(57600);
  Serial1.begin(57600);
  pinMode(Motor1_1, OUTPUT);
  pinMode(Motor1_2, OUTPUT);
  pinMode(Motor2_1, OUTPUT);
  pinMode(Motor2_2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  timer = millis();
}

void loop() {
  if (Serial1.available() > 0) {
    right();
    String data = Serial1.readStringUntil('\n');
    i_per = 0;
    int k = data.length() - 1;
    upr[0] = 0; upr[1] = 0;upr[2]=0;
    int power = 1;

    for (int i = k; i >= 0; i--) {
      if (data[i] == ' ') {
        i_per--;
      power = 1;
      
        
      }
      else if(data[i] == '-'){
        upr[i_per]= -upr[i_per];
      }
      else {
        int val = int(data[i]) - 48;
        upr[i_per] += val * power;
        power *= 10;
      }
      
    }
    //print
    for (int j = 0; j < 3; j++) {
      Serial.print(upr[j]);
      Serial.print(" ");
      Serial.println(data);
    }
    Serial.println(" ");
  }



  //test kick:
  if(millis()==4000)kick=1;

  if (upr[1]) {
    if (millis() - timer >= 950) punch();
    else
      digitalWrite(8, 1);

  } else timer = millis();
}
