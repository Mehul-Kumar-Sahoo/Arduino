int count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=digitalRead(2);
  if(val==LOW){
    count++;
  }
  switch(count){
    case 1:
      digitalWrite(3,HIGH);
      break;
    case 2:
      digitalWrite(4,HIGH);
      break;
    case 3:
      digitalWrite(5,HIGH);
      break;
    default:
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      count=0;
      break;
  }
  delay(200);
}
