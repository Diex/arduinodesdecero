/*
  Example of how to drive a seven segment display using HCF4511 or similar
 
 This sketch drive the display in order to show a number from 0 to 9 everytime a button connected to A0 is pressed.
  
author: Arturo Guadalupi <a.guadalupi@arduino.cc>
 */
 
//Declaration of Arduino pins used as HCF4511 inputs
const int A=6;
const int B=5;
const int C=4;
const int D=3;

const int dsp1 = 7;
const int dsp2 = 8;
const int dsp3 = 9;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A, OUTPUT); //LSB
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT); //MSB
 
  pinMode(dsp1, OUTPUT);
  pinMode(dsp2, OUTPUT);
  pinMode(dsp3, OUTPUT); //MSB

  Serial.begin(9600);

  
}
 
int count = 123; //the variable used to show the number
int col = 0;

void loop() {       
  
      int unidad = 3;
      int decena = 2;
      int centena = 1;

     //multiplexado
      for(int disp = 0 ; disp < 3; disp++){
        
        if( disp == 0) to_BCD(centena); //convert to binary  
        if( disp == 1) to_BCD(decena); //convert to binary  
        if( disp == 2) to_BCD(unidad); //convert to binary  
        // ----------
        mux(disp);

        delay(10);
                 
      }
      
        
}

// defino la funcion
// void = no devuelve ningun valor.
// tipo de dato, nombre, parentesis (parametros), llaves.
void mux(int parametro){
  if(parametro == 0){
    digitalWrite(dsp1, HIGH);
    digitalWrite(dsp2, LOW);
    digitalWrite(dsp3, LOW); //MSB
  }

  if(parametro == 1){
    digitalWrite(dsp1, LOW);
    digitalWrite(dsp2, HIGH);
    digitalWrite(dsp3, LOW); //MSB
  }
  if(parametro == 2){
    digitalWrite(dsp1, LOW);
    digitalWrite(dsp2, LOW);
    digitalWrite(dsp3, HIGH); //MSB
  }
  
  
  
  
}

 
void to_BCD(int count)
{
    if (count == 0) //write 0000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 1) //write 0001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 2) //write 0010
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 3) //write 0011
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
    }
     
    if (count == 4) //write 0100
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 5) //write 0101
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 6) //write 0110
    {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 7) //write 0111
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
     
    if (count == 8) //write 1000
    {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    }
     
    if (count == 9) //write 1001
    {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    } 
}
