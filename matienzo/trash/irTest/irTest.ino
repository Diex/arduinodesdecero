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
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  digitalWrite(rele1, HIGH); // inicio el rele apagado
  digitalWrite(rele2, HIGH); // inicio el rele apagado
  digitalWrite(rele3, HIGH); // inicio el rele apagado
  digitalWrite(rele4, HIGH); // inicio el rele apagado
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    switch(results.value){

    case bot1:

      digitalWrite(rele1, !digitalRead(rele1));
//        //hago algo
//      if(digitalRead(rele1) == HIGH) {
//        digitalWrite(rele1, LOW);
//      }
//      else{
//        digitalWrite(rele1, HIGH);
//      }
      break; // importante el brake

    case bot2:
      digitalWrite(rele2, !digitalRead(rele2));
      break;

    case bot3:
      digitalWrite(rele3, !digitalRead(rele3));
      break;

    case bot4:
      digitalWrite(rele4, !digitalRead(rele4)); 
      break;

    }
    //
    //    if(results.value == bot1){
    //      if(digitalRead(rele1) == HIGH) {
    //        digitalWrite(rele1, LOW);
    //      }
    //      else{
    //        digitalWrite(rele1, HIGH);
    //      }
    //    }

    irrecv.resume(); // Receive the next value

  }


}




