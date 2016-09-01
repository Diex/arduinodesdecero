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

#define trigPin 13
#define echoPin 12

int distances[] = {20, 40, 60, 80, 100, 120, 150, 3000};
int interval = 30;

int redPin = 6;
int greenPin = 7;
int bluePin = 5;

int rgbPins[] = {redPin, greenPin, bluePin};


int red[] = {1, 0, 0};
int green[] = {0, 1, 0};
int blue[] = {0, 0, 1};

int yellow[] = {1, 1, 0};
int magenta[] = {1, 0, 1};
int cyan[] = {0, 1, 1};

int white[] = {1, 1, 1};
int black[] = {0, 0, 0};


void setup() {
  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  delay(100);
  int position = measureDistance(true);

  for(int i = 0; i < 8; i++){
    
    if (position > distances[i] - interval && position < distances[i]) {
      
      switch (i){
          case 0:
            selectColor(red);
          break;
          
          case 1:
            selectColor(green);
          break;
          
          case 2:
            selectColor(blue);
          break;
          
          case 3:
            selectColor(magenta);
          break;
          
          case 4:
            selectColor(yellow);
          break;
          
          case 5:
            selectColor(cyan);
          break;
          
          case 6:
            selectColor(black);
          break;
          
          
          
          
          
          
          
          
        }
    }
  }
  
}


  void selectColor(int colorDef[]) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(rgbPins[i], colorDef[i]);
    }
  }

  long measureDistance(boolean withPrint) {
    long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    if (withPrint) {
      if (distance >= 200 || distance <= 0) {
        Serial.println("Out of range");
      }
      else {
        Serial.print(distance);
        Serial.println(" cm");
      }

    }

    return distance;

  }
