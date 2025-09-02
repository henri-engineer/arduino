#define STEP 8
#define DIR 9
#define EN  10

#define POLIA 20
#define PITCH 2
#define PASSOS_MOTOR 200
#define MICROSTEP 16

//const double MILIMETROS_STEP = (POLIA * PITCH) / (PASSOS_MOTOR * MICROSTEP); // 0.0125 mm por passo
const double MILIMETROS_STEP = 0.0125;

float posicao_atual = 0.0;

void setup() {
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(STEP, LOW);
  digitalWrite(EN, LOW); // Ativa o driver

  Serial.begin(9600);
  Serial.println("Digite a distância em mm (use negativo para inverter a direção):");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    float distancia = input.toFloat();
    float andar = 0;
    Serial.println(distancia);

    if (distancia > posicao_atual) {
        digitalWrite(DIR, HIGH); // Sentido horário
        andar = distancia - posicao_atual;

      } else {
        digitalWrite(DIR, LOW);  // Sentido anti-horário
        andar = posicao_atual - distancia;
      }

      posicao_atual = distancia;
      Serial.println(andar);
      int passos = andar * 80.0;

      Serial.print("Quantidade de passos: ");
      Serial.println(passos);

      for (int i = 0; i < passos; i++) {
        step();
        delayMicroseconds(500); // Ajuste conforme necessário
      }
      Serial.println("Digite a próxima distância em mm:");
    }
  }

void step() {
  digitalWrite(STEP, HIGH);
  delayMicroseconds(4);
  digitalWrite(STEP, LOW);
}
