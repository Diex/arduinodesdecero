#include <IRremote.h>
int RECV_PIN = 11;
int rele1 = 10;
int rele2 = 9;
int rele3 = 8;
int rele4 = 7;

const long bot1 = 0xFF6897;
const long bot2 = 0xFF9867;
const long bot3 = 0xFFB04F;
const long bot4 = 0xFF30CF;

// CLASES y OBJETOS
// definir un objeto que se llam "irrecv" , de tipo IRecv
// definido por la libreria...
IRrecv irrecv(RECV_PIN); // constructor
// int , float, boolea, char, string....
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {

    if (irrecv.decode(&results)) {
      Serial.println(results.value, HEX);
    }

    irrecv.resume(); // Receive the next value

  
}

