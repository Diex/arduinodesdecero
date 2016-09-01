

// directivas del compilador
#define trigPin 2
#define echoPin 3

#define velSonido 58
#define minDist 15
long duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}


void loop() {

  leerSensor();
  Serial.print(distance);
  delay(50);
}


void leerSensor(){
  // genera el pulso
  digitalWrite(trigPin, LOW); //apaga el triger
  delayMicroseconds(2); // espera 2us
  digitalWrite(trigPin, HIGH); // prende el trigger
  delayMicroseconds(10); // 10 us dato del fabricante.
  digitalWrite(trigPin, LOW); // apaga

  // calaculo
  duration = pulseIn(echoPin, HIGH); //codigo colgado aca...

  distance = duration / velSonido;  // unidad de medida
}

