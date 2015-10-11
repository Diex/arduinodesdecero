////////////////////////////////////////////////////////
// configuracion de los perifericos
////////////////////////////////////////////////////////

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
uint16_t tempInicial = 58;          // esta es la temperatura a la cual esta el sensor sin que nadie lo toque
uint16_t tempMinVariacion = 4;      // esta es la diferencia que se produce cuando alguien pone la mano


// para que sea mas facil luego el codigo hago unas estructuras que guardan esas variables
uint8_t sensores[] = {sensor1, sensor2, sensor3, sensor4};
uint16_t sensores_v[] = {sensor1_v, sensor2_v, sensor3_v, sensor4_v};
uint8_t sensores_s[] = {sensor1_s, sensor2_s, sensor3_s, sensor4_s};

uint8_t leds[] = {led1, led2, led3, led4};

uint8_t qty = 4; // cantidad de estaciones

void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ; i < qty; i++){   
        pinMode(sensores[i], INPUT);   // los sensores como input (aunque no hace falta)
        pinMode(leds[i], OUTPUT);      // los leds como salida (y por default, tampoco hace falta) pero le da mejor lectura a lo que hace mi programa
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSensors();
  compareStates();
  turnLeds();

}


void turnLeds(){
  for(int i = 0 ; i < qty; i++){   
        digitalWrite(leds[i], sensores_s[i]); // leo el el sensor y me guardo el valor.
  }  
}


void compareStates(){
  
  uint8_t on = 1;
  uint8_t off = 0;
  
  for(unsigned int i = 0 ; i < qty; i++){   
     if(sensores_s[(char) i] == 1 && sensores_v[i] < tempInicial) { // si el sensor estaba prendido y la temperatura bajo del limite
         sensores_s[i] = off;      // lo apago
     }
     
     if(sensores_s[(char) i] == 0 && sensores_v[i] > tempInicial + tempMinVariacion ){ // el caso opuesto y la temperatura supero el umbral
         sensores_s[i] = on; // lo prendo
     }       
  }  
}

void readSensors(){
  for(int i = 0 ; i < qty; i++){   
        sensores_v[i] = analogRead(sensores[i]); // leo el el sensor y me guardo el valor.
        delayMicroseconds(1000); // entre sensor y sensor dejo un tiempito para que se restablezca el AD
                                 // uso delayMicroseconds que no depende del timer0
  }  
  
  for(int i = 0 ; i < qty; i++){   
        Serial.print(getTemperature(sensores_v[i]));
        Serial.print(" : ");
  }  
  Serial.println();
  
    for(int i = 0 ; i < qty; i++){   
        Serial.print(sensores_v[i]);
        Serial.print(" : ");
  }  
  Serial.println();

}

float getTemperature(uint16_t value){
  return (value / 1024.0) * 5000 / 10; //grados celcius
}

