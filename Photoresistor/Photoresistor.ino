#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

const int sensorPin = A0;
int sensorValue = 0;
float Vin=5;
float Vout=0;
float ref=220;
float r=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
//  lcd.print("Resistance=");
}

void loop() {
//   put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
  lcd.print(sensorValue);
  Vout=(Vin*sensorValue)/1023;
  r=ref*(1/((Vin/Vout)-1));
  lcd.setCursor(0,1);
  lcd.print(r);
  if(r>=10000){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}
