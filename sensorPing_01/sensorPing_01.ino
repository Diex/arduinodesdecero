/*
HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}



void loop() {
  // primero mido...
  long duration, distance;
  
  digitalWrite(trigPin, LOW);        // apago el pin trigger
  delayMicroseconds(2);              // aguanto 2 micro segundos
  digitalWrite(trigPin, HIGH);       // enciendo el pin 
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10);             // aguanta un cacho
  digitalWrite(trigPin, LOW);        // lo vuelve a apagar

  duration = pulseIn(echoPin, HIGH, 20E6L);  
  distance = (duration / 2) * 343 / 1E4 ;
  
//  Serial.println(duration);
  Serial.println(distance);
  // hasta aca... miro el sensor...
  delay(100);
}


