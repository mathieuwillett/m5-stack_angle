#include <Arduino.h> 

#define MA_BROCHE_ANGLE 32

#include <FastLED.h>

CRGB pixelAtom;

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1); 
}

void loop() {
  int maLectureAngle = analogRead(MA_BROCHE_ANGLE);

  Serial.println(maLectureAngle); 

  if (maLectureAngle > 2050) {
    pixelAtom = CRGB(255,0,0); 
  } else {
    pixelAtom = CRGB(0,255,0);
  }

  FastLED.show();
  delay(200);
}
