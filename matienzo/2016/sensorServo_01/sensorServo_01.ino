int sensor = A0;
int servo = 9;

void setup() {
   Serial.begin(9600);
}

void loop() {

  Serial.println("subiendo");
  int maximoRecorrido = 255;
  int incremento = 1;
//  for(int indice = 0 ; indice < maximoRecorrido; indice = indice + incremento) . // indice ++ ; indice += 1;
//  {
//  
//  }
//  
  for (int i = 0; i < maximoRecorrido ; i += incremento){
    analogWrite(servo, i);
    delay(10);
    Serial.println(i);
  }

  
  Serial.println("bajando");
  for (int i = maximoRecorrido; i > 0 ; i -= incremento){
    analogWrite(servo, i);
    delay(10);
    Serial.println(i);
  }
 
}
