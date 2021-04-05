#define TRIG 2
#define ECHO 3
#define BUZZ 7

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600); // to use Serial library we have to initiate serial communication, so this command is necessary
}

float measurement(){
  unsigned long time; // unsigned allows to exceed the maximal limit, as it only stores positive numbers ( no sign bit ) which increases the max value we can store
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10); // sending high signal for a defined time interval
  digitalWrite(TRIG,LOW); // measuring time in which on pin ECHO is HIGH
  time = pulseIn(ECHO,HIGH);
  return time/58.00; // .00 because if there are no decimal places, there won't be a float returned, so we would get an integer as an answer, which decreases resolution
}

void buzzer(){
  float distance = measurement();
  if ((distance < 12) && (distance >= 8)) {
      digitalWrite(BUZZ, HIGH);
      delay(500);
      digitalWrite(BUZZ, LOW);
      delay(500);
    }
  else digitalWrite(BUZZ,LOW);
  if ((distance < 8) && (distance >= 4)) {
      digitalWrite(BUZZ, HIGH);
      delay(150);
      digitalWrite(BUZZ, LOW);
      delay(150);
    }
  else digitalWrite(BUZZ,LOW);
  if (distance < 4) {
      digitalWrite(BUZZ, HIGH);
      delay(50);
      digitalWrite(BUZZ, LOW);
      delay(50);
    }
  else digitalWrite(BUZZ,LOW);
}

void loop() {
  buzzer();
  Serial.print("Distance: ");
  Serial.print(measurement());
  Serial.println("cm");
}
