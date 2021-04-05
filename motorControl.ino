void setup(){
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  analogWrite(9,0);
}

void loop(){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,64);
  delay(250);

  analogWrite(9,128);
  delay(250);

  analogWrite(9,192);
  delay(250);

  analogWrite(9,255);
  delay(250);

  analogWrite(9,192);
  delay(250);

  analogWrite(9,128);
  delay(250);

  analogWrite(9,64);
  delay(250);

  analogWrite(9,0);
  delay(250);


  // change of direction
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);

  analogWrite(9,64);
  delay(250);

  analogWrite(9,128);
  delay(250);

  analogWrite(9,192);
  delay(250);

  analogWrite(9,255);
  delay(250);

  analogWrite(9,192);
  delay(250);

  analogWrite(9,128);
  delay(250);

  analogWrite(9,64);
  delay(250);

  analogWrite(9,0);
  delay(250);
}
