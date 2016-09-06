
// una varible te tipo entero...
/// que se llama "motor"
// inicialaizada con el valor 9
// int motor = 9;

#define motor 9
#define ON LOW
#define OFF HIGH

void setup(){
  pinMode(motor, OUTPUT);
}

void loop()
{
  digitalWrite(motor, ON);
  delay(5000);
  digitalWrite(motor, OFF);
  delay(5000);
}

