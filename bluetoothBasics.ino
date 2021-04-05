#include <SoftwareSerial.h>
#define ledPin 6

char data;
String appendSerialData;

void setup()
{
  pinMode(ledPin, OUTPUT);
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
  else if (appendSerialData == "off") {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    appendSerialData = "";
  }
}
