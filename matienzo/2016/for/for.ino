void setup(){
  Serial.begin(9600);
}

void loop(){

  String texto = "i vale ";
  
  int i = 0;
  Serial.println("arranca el for... ");
  Serial.println( texto + i);  
  for( i ; i < 10 ; i = i + 1 ){  // contador, condicion, incremento...
      // ejecuto esto...
    Serial.println(i);
  }
  Serial.println("termino el for... ");
  Serial.println("-----------");
  delay(2000);

}
