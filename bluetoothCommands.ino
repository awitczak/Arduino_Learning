#include <SoftwareSerial.h>
#define ledPin 6 

int inA1 = 7;
int inA2 = 8;
int pwmA = 9;

int inB1 = 10;
int inB2 = 11;
int pwmB = 12;

char data;
String appendSerialData;

void setup()
{
  digitalWrite(inA1,LOW);
  digitalWrite(inA2,LOW);
  analogWrite(pwmA,0);
  
  digitalWrite(inB1,LOW);
  digitalWrite(inB2,LOW);
  analogWrite(pwmB,0);
  
  pinMode(ledPin,OUTPUT);
  pinMode(inA1,OUTPUT);
  pinMode(inA2,OUTPUT);
  pinMode(pwmA,OUTPUT);
  pinMode(inB1,OUTPUT);
  pinMode(inB2,OUTPUT);
  pinMode(pwmB,OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0)
  {
      data = Serial.read();
      appendSerialData += data;
  }
  if (data == '#')
  {
    Serial.print("Arduino says: ");
    Serial.println(appendSerialData);
    appendSerialData = "";
    data = 0;
  }

  if (appendSerialData == "on") {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    appendSerialData = "";
  }
  if (appendSerialData == "/") {
    digitalWrite(inA1,LOW);
    digitalWrite(inA2,LOW);
    analogWrite(pwmA,0);

    digitalWrite(inB1,LOW);
    digitalWrite(inB2,LOW);
    analogWrite(pwmB,0);
    appendSerialData = "";
  }
  else if (appendSerialData == "off") {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    appendSerialData = "";
  }
  else if (appendSerialData == "speedAOn") {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,100);
    Serial.println("ENGINE A: ON");
    appendSerialData = "";
  }
  else if (appendSerialData == "speedAOff") {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    analogWrite(9,0);
    Serial.println("ENGINE A: OFF");
    appendSerialData = "";
  }
  else if (appendSerialData == "W") {
    digitalWrite(inA1,HIGH);
    digitalWrite(inA2,LOW);
    analogWrite(pwmA,255);

    digitalWrite(inB1,HIGH);
    digitalWrite(inB2,LOW);
    analogWrite(pwmB,255);
    
    Serial.println("FORWARDS");
    appendSerialData = "";
  }
  else if (appendSerialData == "S") {
    digitalWrite(inA1,LOW);
    digitalWrite(inA2,HIGH);
    analogWrite(pwmA,255);

    digitalWrite(inB1,LOW);
    digitalWrite(inB2,HIGH);
    analogWrite(pwmB,255);
    Serial.println("BACKWARDS");
    appendSerialData = "";
  }
  else if (appendSerialData == "D") {
    digitalWrite(inA1,HIGH);
    digitalWrite(inA2,LOW);
    analogWrite(pwmA,255);

    digitalWrite(inB1,LOW);
    digitalWrite(inB2,HIGH);
    analogWrite(pwmB,255);
    
    Serial.println("LEFT");
    appendSerialData = "";
  }
  else if (appendSerialData == "A") {
    digitalWrite(inB1,HIGH);
    digitalWrite(inB2,LOW);
    analogWrite(pwmB,255);

    digitalWrite(inA1,LOW);
    digitalWrite(inA2,HIGH);
    analogWrite(pwmA,255);
    
    Serial.println("RIGHT");
    appendSerialData = "";
  }
  else if (appendSerialData == "P") {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    appendSerialData = "";
  }
  else if (appendSerialData == "L") {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    appendSerialData = "";
  }
}
