int pulsador = 5; // defino un nobre para el pin del pulsador
int led = 13;      // defino un nombre para el pin del led

void setup(){  // se ejecuta cuando inicia el programa
  pinMode(pulsador, INPUT_PULLUP);    // configuro pulsador como input
  pinMode(led, OUTPUT);        // configuro led como output
}


   // defino estadoLed como una variable booleana

void loop(){

  boolean estadoPulsador = !digitalRead(pulsador);   // digital read, me devuelve el estado del pulsador y guardo en esa var
  digitalWrite(led, estadoPulsador);    // digitalWrite escribe un valor DIGITAL en un pin.
}


