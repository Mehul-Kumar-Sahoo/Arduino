#define echoPin 8
#define trigPin 9
const int buzzer=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  Serial.println(distance);

  if(distance<=5){
    tone(buzzer,100);
    Serial.println("yes");
  }
  else{
    noTone(buzzer);
  }
}
