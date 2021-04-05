int sensorX = A0; // arduino pin assignment 
int sensorY = A1; 

int valueX = 0;
int valueY = 0;
int valueButton = 0;
int buttonJoystick = 2;  

void setup() {
  pinMode(buttonJoystick, INPUT);
  digitalWrite(buttonJoystick, HIGH) ;
  Serial.begin(9600);
}



void loop() {
  valueX = analogRead(sensorX);
  Serial.print("X:");
  Serial.print(valueX);

  valueY = analogRead(sensorY);
  Serial.print(" | Y:");
  Serial.print(valueY);

  valueButton = digitalRead(buttonJoystick);
  Serial.print(" | Button: ");
  Serial.println(valueButton, DEC);

  delay(100);
}
