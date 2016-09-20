#define joyx A0
#define joyy A1

//int joyx = A0;

int valx;
int valy;

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
 
 
 Serial.print("Y: ");
 Serial.print(valy);
 Serial.print(" : ");
 Serial.println(normy);
 
 Serial.println("-----------------");
 delay(200);
}
