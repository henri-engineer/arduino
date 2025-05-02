const byte motor1_A = 5;
const byte motor1_B = 6;
const byte reedSwitchTop = 2; // Pino do sensor reed switch do topo
const byte reedSwitchBottom = 3; // Pino do sensor reed switch da base
const byte reedSwitchMiddle1 = 4; // Pino do sensor reed switch intermediário 1

void setup() {
  pinMode(motor1_A, OUTPUT);
  pinMode(motor1_B, OUTPUT);
  pinMode(reedSwitchTop, INPUT_PULLUP);
  pinMode(reedSwitchBottom, INPUT_PULLUP);
  pinMode(reedSwitchMiddle1, INPUT_PULLUP);

  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, LOW);
  Serial.begin(9600);
}

void loop() {
  acc(0);
  delay(2000);
  des(0);
  delay(2000);
}

void acc(byte sentido) {
  byte pin = 0;
  if (sentido == 0) {
    pin = motor1_A;
    digitalWrite(motor1_B, LOW);
  } else {
    pin = motor1_B;
    digitalWrite(motor1_A, LOW);
  }
  for (byte i = 0; i < 255; i++) {
    analogWrite(pin, i);
    delay(20);
    checkSensors();
  }
}

void des(byte sentido) {
  byte pin = 0;
  if (sentido == 0) {
    pin = motor1_A;
    digitalWrite(motor1_A, LOW);
  } else {
    pin = motor1_B;
    digitalWrite(motor1_A, LOW);
  }
  for (byte i = 255; i > 0; i--) {
    analogWrite(pin, i);
    delay(20);
    checkSensors();
  }
}

void checkSensors() {
  bool topSwitchState = digitalRead(reedSwitchTop);
  bool bottomSwitchState = digitalRead(reedSwitchBottom);
  bool middle1SwitchState = digitalRead(reedSwitchMiddle1);

  if (topSwitchState == LOW || bottomSwitchState == LOW || middle1SwitchState == LOW) {
    stopMotor();
    Serial.println("Elevador parado no sensor");
    delay(5000); // Espera 5 segundos
    acc(0); // Continua a se movimentar
  }
}

void stopMotor() {
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, LOW);
}
