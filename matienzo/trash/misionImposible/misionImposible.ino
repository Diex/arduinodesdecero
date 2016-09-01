int sensor1 = 4;
int sensor1_estado = 0;
int sensor2 = 5;
int sensor2_estado = 0;
int sensor3 = 6;
int sensor3_estado = 0;
int sensor4 = 7;
int sensor4_estado = 0;

int baliza = 8;
int estadoBaliza = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  
  pinMode(baliza, OUTPUT);
}

void loop() {
  
  leerEstado();

  if (sensor1_estado || sensor2_estado || sensor3_estado || sensor4_estado) {    
    digitalWrite(baliza, LOW); // logica invertida...
    delay(5000);
  }
  
  digitalWrite(baliza, HIGH);
}

void leerEstado() {
  sensor1_estado = digitalRead(sensor1);
  sensor2_estado = digitalRead(sensor2);
  sensor3_estado = digitalRead(sensor3);
  sensor4_estado = digitalRead(sensor4);
}

