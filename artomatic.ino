#include <Servo.h>
#define GREEN 3
Servo myservo;

int servo_pos;

int closed = 170;
int vend = 90;
void setup() {
  //led outs
  pinMode( 3, OUTPUT);
  pinMode( 5, OUTPUT);
  pinMode( 6, OUTPUT);
  pinMode (11,INPUT_PULLUP);
  pinMode (12,INPUT_PULLUP);
  myservo.attach(10);
  myservo.write(closed);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i=0; i<255; i++){
//    analogWrite(3,i);
//    myservo.write(i%180);
//    delay(20);
//  }


  if (digitalRead(11) == 0){
    
    while ( digitalRead(12) == 1) {
      myservo.write(vend);
      analogWrite(GREEN,250);
      analogWrite(5,0);
      analogWrite(6,0);}
      
    myservo.write(closed);
    analogWrite(GREEN,0);
    analogWrite(5,255);
    analogWrite(6,255);
  }
  
}
