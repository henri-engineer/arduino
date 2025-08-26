#define STEP 9
#define DIR 8
#define EN  7

//Definições
// MicroStep = 16
// Correia 20 dentes
// Pitch 2mm
// mm / passos = nº dentes * pitch / passos motor * microstep

#define POLIA 20
#define PITCH 2
#define PASSOS_MOTOR 200
#define MICROSTEP 16

void setup(){
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(STEP, LOW);
  digitalWrite(DIR, HIGH);
  digitalWrite(EN, LOW);

  Serial.begin(9600);
}

void loop(){
  //const float MILIMETROS_STEP = POLIA*PITCH/PASSOS_MOTOR*MICROSTEP;
  const double MILIMETROS_STEP = 0.0125;
  Serial.println(MILIMETROS_STEP);
  float distancia = 400;
  int passos = distancia/MILIMETROS_STEP;
  Serial.println("Quantidade de Passos: ");
  Serial.println(passos);
  int delayTime = 20000/passos;
  for(int i=0; i<=passos; i++){
    step();
    delay(delayTime);
  }
  while(1){}
}

void step(){
  //1 passo
  digitalWrite(STEP, HIGH);
  delayMicroseconds(4);
  digitalWrite(STEP, LOW);
}
