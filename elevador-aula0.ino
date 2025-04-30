const byte motor1_A = 5;
const byte motor1_B = 6;

void setup() {
  pinMode(motor1_A, OUTPUT);
  pinMode(motor1_B, OUTPUT);

  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, LOW);
}

void loop() {
  acc(0);
  delay(2000);
  des(0);
  delay(2000);
}

void acc(byte sentido) {
  byte pin = 0;
  if (sentido==0){
    pin = motor1_A;
    digitalWrite(motor1_B, LOW);
  }
   else{
    pin = motor1_B;
    digitalWrite(motor1_A, LOW);
  }
  for (byte i=0;i<255;i++){
    analogWrite(pin, i);
    delay(20);
  }
}

  void des(byte sentido) {
  byte pin = 0;
  if (sentido==0){
    pin = motor1_A;
    digitalWrite(motor1_A, LOW);
  }
  else{
    pin = motor1_B;
    digitalWrite(motor1_A, LOW);
  }
  for (byte i=255;i>0;i--){
    analogWrite(pin, i);
    delay(20);
  }
}
