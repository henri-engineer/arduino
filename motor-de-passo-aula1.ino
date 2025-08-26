#define STEP 9
#define DIR 8
#define EN  7

#define POLIA 20
#define PI 3.1415
#define MM_REV POLIA*PI
#define STP_REV 200
const float MM_STP = MM_REV/STP_REV;

void setup(){
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(STEP, LOW);
  digitalWrite(DIR, HIGH);
  digitalWrite(EN, LOW);

  Serial.begin(9600);
  Serial.println(MM_STP);
}

void loop(){
  int passos = 150/MM_STP; //150 é a distancia que se quer percorrer
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
