/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND / alimentacion del sensor
Echo to Arduino pin 13 Trig to Arduino pin 12 // 
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

int trigPin = 13;
// directivas del compilador
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
#define velSonido 58
#define minDist 15

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  long duration, distance;

  // genera el pulso
  digitalWrite(trigPin, LOW); //apaga el triger
  delayMicroseconds(2); // espera 2us
  digitalWrite(trigPin, HIGH); // prende el trigger
  delayMicroseconds(10); // 10 us dato del fabricante.
  digitalWrite(trigPin, LOW); // apaga
  
  // calaculo
  duration = pulseIn(echoPin, HIGH); //codigo colgado aca...

  distance = duration / velSonido;  // unidad de medida
  
  if (distance < minDist) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2,LOW);
  }  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  
  if(distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
    
  delay(500);
}

