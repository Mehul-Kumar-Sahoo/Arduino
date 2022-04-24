#include <Servo.h>

Servo servo;

#define trigPin 9
#define echoPin 10

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo.attach(8);
  servo.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;

  if(distance<=3){
    servo.write(180);
    delay(2000);
  }
  else{
    servo.write(0);
    delay(2000);
  }
}
