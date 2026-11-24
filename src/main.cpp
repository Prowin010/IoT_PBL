#include <Arduino.h>

#define HELP_BUTTON 14

//buttonHelpFlag: raised (true) by the ISR when button help is pressed. [LAB 10]
volatile bool buttonHelpFlag = false;

//the time of last accepted press [Lab 10]
volatile unsigned long lastInterrupt = 0;


// A Callback is a variable that holds a function (no inputs, returns nothing). [LAB 10]
typedef void (*Callback)();
Callback buttonHelpCallback;   // what button A does

//Event handler for help button [LAB 10]
void onHelpButtonPressed()
{
  Serial.print("Help");   // print the text...

}

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

  // Callbacks [LAB 10]
  // Under // Callbacks: choose which function each event calls.
  // No brackets here – you store the function, you do not run it.
  buttonHelpCallback = onHelpButtonPressed;     // button A arms and disarms
}

void loop() {
  
  // Button Help (interrupt) [LAB 10]
  // Flag pattern: did the ISR raise the flag?
  if (buttonHelpFlag == true)
  {
    buttonHelpFlag = false;   // lower the flag first, so the press is handled once
    //onButtonBPressed();    // then call the handler
    buttonHelpCallback();     // call the callback instead
  }


}

