const int stepPin1 = 3;
const int dirPin1 = 2;

const int stepPin2 = 8;
const int dirPin2 = 7;



void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);

  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  
  Serial.begin(57600);
}

void loop() {
  Serial.print('*');
  
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);

  for (int i = 0; i < 2001; i++)
  {
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,HIGH);
    delay(50);
    Serial.print('/');
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin2,LOW);
    delay(50);  
    Serial.print('.');  
  }

  Serial.print('*');
  
  delay(1000);

  Serial.print('*');
  
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  for (int i = 0; i < 2001; i++)
  {
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,HIGH);
    delay(50);
    Serial.print('/');
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin2,LOW);
    delay(50);
    Serial.print('.');
  }

  Serial.print('*');
  
  delay(1000);
}
