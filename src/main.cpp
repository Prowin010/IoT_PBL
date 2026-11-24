#include <Arduino.h>

#define HELP_BUTTON 14

//buttonHelpFlag: raised (true) by the ISR when button help is pressed. [LAB 10]
volatile bool buttonHelpFlag = false;

//the time of last accepted press [Lab 10]
volatile unsigned long lastInterrupt = 0;

void IRAM_ATTR helpbutton_ISR() {
  //Ignore presses les than 200 ms apart (debounce inside the ISR) [Lab 10]
  if (millis() - lastInterrupt > 200)
  {
    lastInterrupt = millis(); //remember when press happened
    buttonHelpFlag = true; // raise the flag for loop(): true or false?

  }
}

void setup() {
  pinMode(HELP_BUTTON, INPUT_PULLUP);

  //Interrupt [8]
  attachInterrupt(
    digitalPinToInterrupt(HELP_BUTTON), 
    helpbutton_ISR, FALLING);

}

void loop() {
  
}

