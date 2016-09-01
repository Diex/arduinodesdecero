/*
HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */
// #include <ardumidi.h>

#define echo3 12
#define trig3 4

#define echo2 11
#define trig2 5

#define echo1 10
#define trig1 6

void setup() {
   Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);

  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  
}



void loop() {
  
  Serial.print(readDistance(echo1, trig1));
  Serial.println();

  // Serial.print("one   :"); Serial.println();
  // delay(10);
  // Serial.print("two   :"); Serial.println(readDistance(echo2, trig2));
  // delay(101;
  // Serial.print("three :"); Serial.println(readDistance(echo3, trig3));
  // delay(10);

  delay(100);

  // midi();
}


long readDistance(int sensor, int trigPin){
  long duration, distance;
  
  digitalWrite(trigPin, LOW);        // apago el pin trigger
  delay(1);                          // just in case
  digitalWrite(trigPin, HIGH);       // enciendo el pin 
  delayMicroseconds(10);             // aguanta un cacho
  digitalWrite(trigPin, LOW);        // lo vuelve a apagar

  duration = pulseIn(sensor, HIGH);  
  distance = (duration / 2) * 343 / 1E4 ;


  return distance;
}

int note_on = 0;
#define MIDI_NOTE_OFF          0x80
#define MIDI_NOTE_ON           0x90


void midi()
{
  
  if (!note_on)
  {
  // play a Cminor chord on channel 0, at maximum volume (127)
    midi_command(MIDI_NOTE_ON, 0, 61, 127);
    // midi_note_on(0, MIDI_E + MIDI_FLAT + MIDI_OCTAVE, 127);
    // midi_note_on(0, MIDI_G + MIDI_OCTAVE, 127);

  // The MIDI_* macros were created to make your life easier, but you
  // don't have to use them. You may enter numbers instead if you know
  // what you're doing.

    note_on = 1;
    // digitalWrite(ledPin, HIGH);
  }

  else
  {
  // stop the Cminor chord
    midi_command(MIDI_NOTE_OFF, 0, 61, 127);
    // midi_note_off(0, MIDI_E + MIDI_FLAT + MIDI_OCTAVE, 127);
    // midi_note_off(0, MIDI_G + MIDI_OCTAVE, 127);

    note_on = 0;
    // digitalWrite(ledPin, LOW);
  }
  
  delay(500);
}


void midi_command(byte command, byte channel, byte param1, byte param2)
{
  Serial.write(command | (channel & 0x0F));
  Serial.write(param1 & 0x7F);
  Serial.write(param2 & 0x7F);
}


// Available commands:
//
// Start/stop playing a certain note:
//   midi_note_on(byte channel, byte key, byte velocity);
//   midi_note_off(byte channel, byte key, byte velocity);
//
// Change pressure of specific keys:
//   midi_key_pressure(byte channel, byte key, byte value);
//
// Change controller value (used for knobs, etc):
//   midi_controller_change(byte channel, byte controller, byte value);
//
// Change "program" (change the instrument):
//   midi_program_change(byte channel, byte program);
//
// Change key pressure of entire channels:
//   midi_channel_pressure(byte channel, byte value);
//
// Change pitch-bend wheel:
//   midi_pitch_bend(byte channel, int value);
//
// Send a comment:
//   midi_comment(char* str);
//
// Send a series of bytes (to be interpreted by another program):
//   midi_printbytes(char* bytes, int len);
//
// Parameters:
//   channel             an integer from 0 to 15
//   pitch-bend value    an integer from 0 to 16383
//   all other values    an integer from 0 to 127
//

