int pinSensor = A0;
int pinServo = 9;


int valSensor = 0;
int valServo = 0;

int minValor = 0;
int maxValor = 255;


void setup() {
   Serial.begin(9600);
   pinMode(pinSensor, INPUT);
   pinMode(pinServo, OUTPUT);

   valServo = minValor;
   analogWrite(pinServo, valServo);

   pinMode(2, INPUT_PULLUP);
   
   attachInterrupt(digitalPinToInterrupt(2), interrupcion, FALLING);
}


void interrupcion(){
   Serial.println("paso algo...");
   delay(1000);
}

int minInput = 1024;
int maxInput = 0;

void loop() {
  
  valSensor = analogRead(pinSensor);
  //  minInput = minInput < valSensor ? valSensor : minInput;
  minInput = min(valSensor, minInput);
  maxInput = max(valSensor, maxInput);
  
  valServo = map(valSensor, minInput, maxInput, 0, 255); // valor, minIN, maxIN, minOUT, maxOUT
  valServo = constrain(valServo, 0, 255);
  
  analogWrite(pinServo, valServo); 
  
  
  Serial.print("sensor: \t");
  Serial.print(valSensor);
  Serial.print(" servo: \t");
  Serial.print(valServo);
  Serial.println("");
  
  delay(50);
  
 
}








