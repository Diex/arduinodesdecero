#include <MIDI.h>


MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, midiBench);



int trigPin = 13;
// directivas del compilador
#define trigPin 2
#define echoPin 3

#define velSonido 58
#define minDist 15
long duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  MIDI.begin(0);          // Launch MIDI and listen to channel 4
}

void loop() {

  // leerSensor();
  distance = 63;
  // distancia representa el valor de la nota (0/127)
  MIDI.sendNoteOn(distance,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
  
  delay(500);
  MIDI.sendNoteOff(distance,0,1);  // Send a Note (pitch 42, velo 127 on channel 1)
  delay(500);
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
