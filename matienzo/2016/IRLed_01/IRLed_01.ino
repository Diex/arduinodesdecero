/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRLib.h>
#include <Adafruit_NeoPixel.h>

// ------
#define PIN            6
#define NUMPIXELS      36
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int RECV_PIN = 11;
IRrecv My_Receiver(RECV_PIN);//receiver on pin 11
IRdecode My_Decoder;//Decoder object


long arriba = 0x2DD37549;
long abajo = 0xB4A116F2;



void setup()
{
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  My_Receiver.enableIRIn(); // Start the receiver

}

int cual = 0;

void loop() {  
  if (My_Receiver.GetResults(&My_Decoder)) {    
    My_Decoder.decode();
      Serial.println(My_Decoder.value, HEX);
   if(My_Decoder.value == arriba) { 
      Serial.println("arriba");
      cual = (cual + 1) % NUMPIXELS;
    }
    if(My_Decoder.value == abajo){
      Serial.println("abajo");
      cual = (cual - 1) < 0 ? NUMPIXELS : cual - 1;
    }
    My_Receiver.resume(); //Restart the receiver
   }


    for(int px = 0; px <= NUMPIXELS; px ++){
      pixels.setPixelColor(px, pixels.Color(0, 0, 0));
      if(px == cual) pixels.setPixelColor(px, pixels.Color(127, 127, 127));
    }
      pixels.show();
//    
  
//  delay(100);
}
