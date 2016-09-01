int pulsador = 4;
int estado; 

int led1 = 9;
int led2 = 8;

void setup(){
  pinMode(pulsador, INPUT);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  estado = digitalRead(pulsador);
  
  digitalWrite(led1, estado);
  digitalWrite(led2, !estado);
  Serial.println(estado);
  
  if(estado == HIGH){
    Serial.println("apagado");
  }else{
    Serial.println("prendido");
  }
  /*
  estado = digitalRead(pulsador);
  if(estado == HIGH){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }else{
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);    
  }
  */
}
