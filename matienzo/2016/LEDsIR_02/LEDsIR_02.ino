#include <Adafruit_NeoPixel.h>
#include <IRLib.h>
 
IRrecv My_Receiver(11);//receiver on pin 11
IRdecode My_Decoder;//Decoder object
 
//One NeoPixel connected to pin six
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36,6,NEO_GRB + NEO_KHZ800);
 
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  My_Receiver.enableIRIn(); // Start the receiver
}
 
void loop() {
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Decoder.decode();
    Serial.println(My_Decoder.value);
    if (My_Decoder.decode_type== NEC) {
      switch(My_Decoder.value) {
        case 0x2DD37549:  //Volume Down
          strip.setPixelColor(0,255,0,0);//Red
          break;
        case 0xB4A116F2:  //Play/Pause
          strip.setPixelColor(0,0,255,0);//Green
          break;
        case 0xfd40bf:  //Volume Up
          strip.setPixelColor(0,0,0,255);//Blue
          break;
      }
    strip.show();
    My_Receiver.resume(); //Restart the receiver
    }
  }
}
