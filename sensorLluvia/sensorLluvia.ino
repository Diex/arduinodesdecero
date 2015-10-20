// KISS
// keep
// it
// simple
// stupid...

int sensor = 3; // conecto el sensor en el pin 3
int rele = 6;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  boolean hayAgua = digitalRead(sensor);
  // si tengo agua lo apago
//  digitalWrite(rele, !hayAgua);
    if(hayAgua){
      digitalWrite(rele, LOW); // logica inversa en el rele
    }else{
      digitalWrite(rele,HIGH);
    }
    
    Serial.println(analogRead(A0));
    
}
