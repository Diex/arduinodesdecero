
//int pinA = 2;
//int pinB = 3;
//int pinC = 4;
//int pinD = 5;
//int pinE = 6;
//int pinF = 7;
//int pinG = 8;

int segmentos[7] = {2, 3, 4, 5, 6, 7, 8};

void setup(){

//  for(var desde, hasta (condicion), incremento){
//    hago algo...
//  }

  for(int i = 0; i < 7  ;  i++){
    pinMode(segmentos[i], OUTPUT);    
  }
  
}

void loop(){
  cero();
  delay(500);
  uno();
  delay(500);
  tres();
  delay(500);
}


void cero(){
  reset();    
  for(int i = 0; i < 7  ;  i++){
    if(i == 6)  continue; // corta la iteracion
    digitalWrite(segmentos[i], HIGH);    
  }    
}

void uno(){
  reset();
  digitalWrite(segmentos[1], HIGH);
  digitalWrite(segmentos[2], HIGH);
//  for(int i = 0; i < 7  ;  i++){
//    if(i == 6)  continue; // corta la iteracion
//    digitalWrite(segmentos[i], HIGH);    
//  }     
}

void tres(){
  reset();
  for(int i = 0; i < 7  ;  i++){
    if(i == 4 || i == 5)  continue; // corta la iteracion
    digitalWrite(segmentos[i], HIGH);    
  }    
}

void reset(){
  for(int i = 0; i < 7  ;  i++){
    digitalWrite(segmentos[i], LOW);    
  }    

}
