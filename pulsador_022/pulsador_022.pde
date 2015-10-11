int pulsador = 4;
int led = 6;
int estado = 0;

void setup(){
  pinMode(pulsador, INPUT); 
  pinMode(led, OUTPUT);
  Serial.begin(9600); // inicio la comunicacion serial
}



void loop(){
  estado = !digitalRead(pulsador);  
  digitalWrite(led, estado);
  Serial.println(estado);  // imprimo el estado de la variable "estado";
}
