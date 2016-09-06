
// una varible te tipo entero...
/// que se llama "motor"
// inicialaizada con el valor 9
// int motor = 9;

#define motor 9
#define boton 5
#define ON LOW
#define OFF HIGH

int tiempo = 1000;
  
void setup(){
  pinMode(motor, OUTPUT);
  pinMode(boton, INPUT);

}

int secuencia;

void loop()
{
  int estado; 
  estado  =  digitalRead(boton); 
  
 if(estado == ON){
   secuencia = ON;
 }
 
 if(secuencia == ON){
   digitalWrite(motor, ON);
   delay(tiempo);
   digitalWrite(motor, OFF); 
   delay(tiempo);
 } 
}

