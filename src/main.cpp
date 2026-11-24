#include <Arduino.h>

//Pin assignment
#define HELP_BUTTON 14
#define GREEN_LED 32
#define RED_LED 33

void setup() {
  pinMode(HELP_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED);
  
}

void loop() {
  
}

