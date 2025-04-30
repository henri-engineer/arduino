// Definição dos pinos
const int motorPin1 = 9; // Pino de controle do motor
const int motorPin2 = 10; // Pino de controle do motor
const int reedSwitchTop = 2; // Pino do sensor reed switch do topo
const int reedSwitchBottom = 3; // Pino do sensor reed switch da base
const int reedSwitchMiddle1 = 4; // Pino do sensor reed switch intermediário 1
const int reedSwitchMiddle2 = 5; // Pino do sensor reed switch intermediário 2

void setup() {
  // Configuração dos pinos
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(reedSwitchTop, INPUT_PULLUP);
  pinMode(reedSwitchBottom, INPUT_PULLUP);
  pinMode(reedSwitchMiddle1, INPUT_PULLUP);
  pinMode(reedSwitchMiddle2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Verifica o estado dos sensores reed switch
  bool topSwitchState = digitalRead(reedSwitchTop);
  bool bottomSwitchState = digitalRead(reedSwitchBottom);
  bool middle1SwitchState = digitalRead(reedSwitchMiddle1);
  bool middle2SwitchState = digitalRead(reedSwitchMiddle2);

  if (topSwitchState == LOW) {
    // Elevador chegou ao topo, parar o motor
    stopMotor();
    Serial.println("Elevador no topo");
  } else if (bottomSwitchState == LOW) {
    // Elevador chegou à base, parar o motor
    stopMotor();
    Serial.println("Elevador na base");
  } else if (middle1SwitchState == LOW) {
    // Elevador chegou ao nível intermediário 1, parar o motor
    stopMotor();
    Serial.println("Elevador no nível intermediário 1");
  } else if (middle2SwitchState == LOW) {
    // Elevador chegou ao nível intermediário 2, parar o motor
    stopMotor();
    Serial.println("Elevador no nível intermediário 2");
  } else {
    // Movimentar o elevador
    moveElevatorUp();
  }
}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void moveElevatorUp() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void moveElevatorDown() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

