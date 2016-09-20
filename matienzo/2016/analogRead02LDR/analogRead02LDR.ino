#define joyx A0
#define joyy A1
#define ldr A2
//int joyx = A0;

int valx;
int valy;
int valldr;

void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);

}

int normx;
int normy;


void loop() {
  valx = analogRead(joyx);
  valy = analogRead(joyy);


  normx = map(valx, 0, 1023, -100, 100);
  normy = map(valy, 0, 1023, -100, 100);


  Serial.print("X: ");
  Serial.print(valx);
  Serial.print(" : ");
  Serial.println(normx);

  if(normx > 0) {
    Serial.println("voy a la derecha");
  }
  else{
    Serial.println("voy a la izquierda");
  }

  Serial.print("Y: ");
  Serial.print(valy);
  Serial.print(" : ");
  Serial.println(normy);

  if(
 
 
 
  > 0) {
    Serial.println("voy arriba");
  }
  else{
    Serial.println("voy abajo");
  }


  Serial.println("-----------------");

  valldr = analogRead(ldr);
  Serial.println(valldr);
  Serial.println("-----------------");

  delay(1000);
}

