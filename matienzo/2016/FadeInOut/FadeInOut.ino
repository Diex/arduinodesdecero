int ledPin = 9;    // LED connected to digital pin 9

void setup()  { 
  // nothing happens in setup 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
} 

void loop()  { 
  
  Serial.println("hola loop");
  int pwm_value = 0; 
  int pausa = 127;

  for(pwm_value; pwm_value <= 255; pwm_value += 5 ){  // pwm_value = pwm_value + 5;
    analogWrite(ledPin, pwm_value);
    delay(30);
    if( pwm_value < pausa + 3 && pwm_value > pausa - 3) {
      analogWrite(ledPin, 0);
      
      delay(3000);
      Serial.println("pwm subiendo pausa:");
                  Serial.println(pwm_value);
    }
  }

  // en este punto pwm_value deberia valer 255 

  for(pwm_value; pwm_value >= 0; pwm_value -= 5 ){  // pwm_value = pwm_value + 5;
    analogWrite(ledPin, pwm_value);
    delay(30);
    if( pwm_value < pausa + 3 && pwm_value > pausa - 3) {
      analogWrite(ledPin, 0);

      delay(1000);
            Serial.println("pwm bajando pausa:");
            Serial.println(pwm_value);
    }

  }


}



