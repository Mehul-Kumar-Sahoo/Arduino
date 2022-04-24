#include <LiquidCrystal.h>
LiquidCrystal  LCD(11,10,9,2,3,4,5);
//LiquidCrystal  LCD(2,3,4,5,9,10,11);

#define trigPin 13
#define echoPin 12

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Target Distance:");
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

  LCD.setCursor(0,1);
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);
  LCD.print(distance);
  LCD.print(" cm");
  delay(250);
}
