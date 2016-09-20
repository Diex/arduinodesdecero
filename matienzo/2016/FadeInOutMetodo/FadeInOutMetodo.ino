int ledPin = 9;    // LED connected to digital pin 9

void setup()  { 
  // nothing happens in setup 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
} 
// definicion
void fadeIn(int inc, int del){  
  for(pwm_value; pwm_value >= 0; pwm_value += inc ){  // pwm_value = pwm_value + 5;
    analogWrite(ledPin, pwm_value);
    delay(del);
  }
  
int pwm_value = 0; 
  
void loop()  { 

//  ..llamada
  fadeIn(5, 100);

  // en este punto pwm_value deberia valer 255
}



}












