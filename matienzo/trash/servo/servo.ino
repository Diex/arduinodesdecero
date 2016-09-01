
int servo = 3;           // the pin that the LED is attached to
int sensor = A0;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(servo, OUTPUT);
  
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  int pote = analogRead(sensor);
  int dutyCycle = map(pote, 0, 1024, 0, 255);

  analogWrite(servo, dutyCycle);    

  delay(30);                            
}

