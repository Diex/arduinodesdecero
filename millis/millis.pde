
void setup(){

}

long tiempoAnterior; 

void loop(){

  long tiempo =  millis();
 
 if(tiempo - tiempoAnterior > 1000){
     haceAlgo();
     tiempoAnterior = tiempo;
 }
 
}
