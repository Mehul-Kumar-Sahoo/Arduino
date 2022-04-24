#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
Servo servo;
const int sensorPin=A0;
int sensorValue;
unsigned long time=0;
long int seconds=0; 
int minutes=0; 
int hours=0; 
int reset=0;
float Vin=5;
float Vout=0;
float ref=220;
float r=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Time:");
  servo.attach(8);
  servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(5,0);
  sensorValue=analogRead(sensorPin);
  Vout=(Vin*sensorValue)/1023;
  r=ref*(1/((Vin/Vout)-1));
//  Serial.println(r);
  delay(1000);
  if(r<3000){
    setClock();
    lcd.print(seconds);
    delay(1000);
    servo.write(0);
    delay(50);
    servo.write(180);
  }
  else{
    seconds=0;
    lcd.print(seconds);
    servo.write(0);
  }
}

void setClock() 
{ 
  seconds++;       //counts seconds from 0 
  delay(1000);     //a delay of 1000 milliseconds is given for each second count 
  if (seconds>59){ 
      seconds=0;      //whenever second is greater than 59 than second is made equal to 
      minutes++;     // zero and a minute is counted for it 
  } 
  if (minutes>59){
    hours++; 
    minutes=0; 
  } 
  if(hours>23){ 
    hours=0; 
  } 
}
