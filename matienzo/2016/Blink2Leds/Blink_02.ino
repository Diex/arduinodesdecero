
// variables...
int led = 9;
int otroLed;


void setup() {                
  // todo esto se ejecuta una sola vez y al iniciar el arduino
  pinMode(led, OUTPUT);
  otroLed = 8;
  pinMode(otroLed, OUTPUT);  
}

void loop() {
    // se queda ejecutandose por siempre...  
    // cada letra e  s 1 byte que ocupo...  
    digitalWrite(led, HIGH);
    digitalWrite(otroLed,HIGH);
   delay(500);
   digitalWrite(otroLed, LOW);   
    delay(500);
    digitalWrite(led, LOW);
    delay(1000);
    
}
