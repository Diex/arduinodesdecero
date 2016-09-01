int pote = A0;
int rele = 6;

void setup(){
  Serial.begin(9600);
  pinMode(rele, OUTPUT);  
}

int valor;
int limiteUp = 600;
int limiteLow = 400;
void loop(){
  valor = analogRead(A0);  

  Serial.print(millis());
  Serial.print(" -> ");
  Serial.println(valor);

  
    
  if(valor > limiteLow && valor < limiteUp ) { // si valor es mayor que limite
    digitalWrite(rele, HIGH); // hago esto
  }else{
    digitalWrite(rele, LOW);  // hago esto otro.
  }
}
