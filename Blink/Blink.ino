/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly. 
 This example code is in the public domain.
 autor: diex
 fecha : 11 de mayo  
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop(){
    blink(1000);
    blink(2000);
    blink(3000);    
}

void blink(int pepe){
  digitalWrite(led, HIGH);
  delay(pepe);
  digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(pepe);               // wait for a second
}








