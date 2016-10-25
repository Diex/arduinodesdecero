/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

long uno = 0xFF6897;
long dos = 0xFFB04F;
long tres = 0xFFB04F;
long arriba = 0x2DD37549;
long abajo = 0xB4A116F2;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  
  if ( irrecv.decode(&results) ) {
    if(results.value == arriba) Serial.println("arriba");
    if(results.value == abajo) Serial.println("abajo");
    irrecv.resume(); // Receive the next value
  }
  
  delay(100);
}
