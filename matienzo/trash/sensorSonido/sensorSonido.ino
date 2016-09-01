int sensor = 3;
int rele = 6;
volatile boolean estado = false;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);
  attachInterrupt(1, sensorActivo, RISING);
  digitalWrite(rele, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rele, estado);

  if(estado == HIGH){
    delay(1000);
    estado = LOW;
  }

}

// definir una funcion
void sensorActivo(){  
   estado = HIGH;
}


