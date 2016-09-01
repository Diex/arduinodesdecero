 ////////////////////////////////////////////////////////
// configuracion de los perifericos
////////////////////////////////////////////////////////
uint8_t on = 1;
uint8_t off = 0;  

// como voy a usar analogWrite() los leds tienen que estar en los pines que tienen PWM
// en mi caso voy a usar un arduino uno. pero creo que esto deberia funcionar con cualquier version de arduino
// defino estas variables como "unsigned" porque no tiene sentido un pin que tenga un valor menor a uno : pinMode(-1, INPUT); ???
unsigned int led1 = 5;
unsigned int led2 = 6;
unsigned int led3 = 10;
unsigned int led4 = 11;



// los sensores son LM35 o sea que necesito una entrada analogica para cada uno
// esto es otra forma de escribir unsigned int
// http://www.badprog.com/c-type-what-are-uint8-t-uint16-t-uint32-t-and-uint64-t

uint8_t sensor1 = A0;
uint8_t sensor2 = A1;
uint8_t sensor3 = A2;
uint8_t sensor4 = A3;

// y unas variables para guardarme los valores de los sensores
// para ello uso el sufijo ('_v'), esto es una convencion personal y que seguramente solo respetare en este codigo
// uso uint16 porque voy a convertir valores desde el AD que son en 10 bits

uint16_t sensor1_v = 0;
uint16_t sensor2_v = 0;
uint16_t sensor3_v = 0;
uint16_t sensor4_v = 0;
// el estado logico del sensor (si prendido o apagado). la _s es por "state"
// arrancan todos apagados
uint8_t sensor1_s = 0;
uint8_t sensor2_s = 0;
uint8_t sensor3_s = 0;
uint8_t sensor4_s = 0;

// este valor hay que ensayarlo, probarlo, ver como funciona y si es verdadero.
// con mi sensor anda ok.
uint16_t tempInicial = 20;          // esta es la temperatura a la cual esta el sensor sin que nadie lo toque
uint16_t tempFinal = 30;          // esta es la temperatura a la cual esta el sensor sin que nadie lo toque
uint16_t tempMinVariacion = 4;      // esta es la diferencia que se produce cuando alguien pone la mano


float temp1 = 0.0;
float temp2 = 0.0;
float temp3 = 0.0;
float temp4 = 0.0;

// para que sea mas facil luego el codigo hago unas estructuras que guardan esas variables
uint8_t sensores[] = {sensor1, sensor2, sensor3, sensor4};
uint16_t sensores_v[] = {sensor1_v, sensor2_v, sensor3_v, sensor4_v};
uint8_t sensores_s[] = {sensor1_s, sensor2_s, sensor3_s, sensor4_s};
float sensores_t[] = {temp1, temp2, temp3, temp4};

uint8_t leds[] = {led1, led2, led3, led4};

uint8_t qty = 4; // cantidad de estaciones

void setup() {
  // put your setup code here, to run once:
  for (int i = 0 ; i < qty; i++) {
    pinMode(sensores[i], INPUT);   // los sensores como input (aunque no hace falta)
    pinMode(leds[i], OUTPUT);      // los leds como salida (y por default, tampoco hace falta) pero le da mejor lectura a lo que hace mi programa
  }
  Serial.begin(9600);
//    analogReference(INTERNAL);
}

long lastSend = 0;
long nextSendDelay = 50;
long now = 0;

void loop() {
  
  readSensors();
  checkSensorsState();
  updateTemperatures();
  turnLeds();
  
  now = millis();
  if(now - lastSend > nextSendDelay){
    sendData();
    lastSend = millis();
  }
}


//    cambia el estado de los leds en funcion del estado de los sensores
void turnLeds() {
  for (int i = 0 ; i < qty; i++) {
    digitalWrite(leds[i], sensores_s[i]); // leo el el sensor y me guardo el valor.
  }
}

//  ejecuta las lecturas en los 4 sensores
void readSensors() {
  // tiro una lectura para estabilizar el AD (?)
  analogRead(0); delay(2);
  for (int i = 0 ; i < qty; i++) {
    // leo el el sensor y me guardo el valor.
    sensores_v[i] = analogRead(sensores[i]);
    // entre sensor y sensor dejo un tiempito para que se restablezca el AD
    delay(2);
  }
}

// actualiza el estado actual de referencia de cada uno (si esta prendido o apagado)
void checkSensorsState(){
  
    for (unsigned int i = 0 ; i < qty; i++) {
    // si el sensor estaba prendido y la temperatura bajo del limite `
    if (sensores_s[(char) i] == on && sensores_t[i] < tempInicial + tempMinVariacion) { 
      // lo apago
      sensores_s[i] = off;      
    }
    // el caso opuesto y la temperatura supero el umbral
    if (sensores_s[(char) i] == off && sensores_t[i] > tempFinal - tempMinVariacion ) { 
      sensores_s[i] = on; // lo prendo
    }
  }
}

void updateTemperatures(){
  for (int i = 0 ; i < qty; i++) {
      sensores_t[i] = ease(sensores_t[i], getTemperature(sensores_v[i]), 0.95);
  }
}

void sendData() {
  for (int i = 0 ; i < qty; i++) {
    Serial.print(sensores_t[i]);
    Serial.print(" : ");
  }
  Serial.println();

}

float getMVolts(uint16_t value) {
  return  5000.0  * (value * 1.00000 / 1023.0); //mv (son 1024 valores incluidos el 0)
}
float getTemperature(uint16_t value) {
  return  getMVolts(value) / 10; //oC
}

float ease(float current, float nxt, float factor){
  return (current * factor) + (nxt * (1 - factor));
}

