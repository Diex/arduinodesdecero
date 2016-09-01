int left = 5;
int right = 6;

void setup(){
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  Serial.begin(9600);   //inicializo la comunicacion serial
}

void loop(){
  delay(250);
  boolean estadol = !digitalRead(left);
  boolean estador = !digitalRead(right);
 
  /*
  if( talCosa ){
    hago esto;
  }else{
    hago esto otro;
  }
    
   */
  if(estadol == HIGH){  // == operador de comparacion (= asignacion)
    Serial.print("left: ON");
  }else{
    Serial.print("left: OFF");
  }

  Serial.print(" --- ");

  if(estador){
    Serial.print("right: ON");
  }else{
    Serial.print("right: OFF");
  }

  Serial.println();

}

