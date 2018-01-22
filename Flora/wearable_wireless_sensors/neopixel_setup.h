#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
#define NUM_LEDS 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


void neopixelRED(){
   strip.setPixelColor(0, 255, 0, 0);
   strip.show();
}


void neopixelBLUE(){
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
}


void neopixelOFF(){
   strip.setPixelColor(0, 0, 0, 0);
   strip.show();
}

