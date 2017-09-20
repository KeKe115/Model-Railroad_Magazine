void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for ( i = 0; i <= 200; i++ ) {
    analogWrite(3, i);
    digitalWrite(4, LOW);
    delay(100);
  }
  delay(5000);
  for ( i = 200; i >= 0; i-- ) {
    analogWrite(3, i);
    digitalWrite(4, LOW);
    delay(100);
  }
  delay(2000);
}
