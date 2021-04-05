
int sensorX = A0; // arduino pin assignment 
int sensorY = A1; 

int inA1 = 7;
int inA2 = 8;
int pwmA = 9;

int valueX = 0;
int valueY = 0;
int valueButton = 0;
int buttonJoystick = 2;  
float a,b; // constants for normalisation


void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  analogWrite(9,0);
  
  pinMode(buttonJoystick, INPUT);
  digitalWrite(buttonJoystick, HIGH) ;
  Serial.begin(9600);
  
  a = (255.0-(-255.0))/(1023.0);
  b = 255.0-a*1023.0;
}



void loop() {
  
  valueX = a*(analogRead(sensorY))+b;
  Serial.print("X:");
  Serial.print(valueX);

  valueY = a*(analogRead(sensorY))+b;
  Serial.print(" | Y:");
  Serial.print(valueY);

  valueButton = digitalRead(buttonJoystick);
  Serial.print(" | Button: ");
  Serial.println(valueButton, DEC);

  if (abs(valueX) < 70){
    valueX = 0;
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
    
  if (valueX >= 0) {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,valueX);
  }
  if (valueX < 0) {
    valueX = abs(valueX);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,valueX);
  } 


  delay(50);
}
