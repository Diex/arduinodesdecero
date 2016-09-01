int pote = A0;
int rele = 6;

void setup(){
  Serial.begin(9600);
  pinMode(rele, OUTPUT);  
}

int valor;
int limite = 512;

void loop(){
  valor = analogRead(A0);  

  Serial.print(millis());
  Serial.print(" -> ");
  Serial.println(valor);

  if(valor > limite) {
    digitalWrite(rele, HIGH);
  }else{
    digitalWrite(rele, LOW);  
  }
}
