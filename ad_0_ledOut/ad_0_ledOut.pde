int pote = A0;
int ledPWM = 6;

void setup(){
  Serial.begin(9600);
  pinMode(ledPWM, OUTPUT);  
}

int valor;

void loop(){
  valor = analogRead(A0);  
  valor = valor / 4;
  
  Serial.print(millis());
  Serial.print(" -> ");
  Serial.println(valor);

  analogWrite(ledPWM, valor);  
    
}
