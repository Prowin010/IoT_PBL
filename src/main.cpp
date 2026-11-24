#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   23
#define OLED_CLK   18
#define OLED_DC    16
#define OLED_CS    17
#define OLED_RST   4

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  OLED_MOSI,
  OLED_CLK,
  OLED_DC,
  OLED_RST,
  OLED_CS 
);

Adafruit_BMP280 bmp;
float temperature;


void setup(){

  Wire.begin();
  Serial.println("I2 Started");
  Serial.begin(9600);
  Serial.println("Program Started");

  if (bmp.begin(0x76)) {
    Serial.println("BMP280 Found at 0x76");
  } else if (bmp.begin(0x77)) {
    Serial.println("BMP280 Found at 0x77");
  } else {
    Serial.println("BMP280  Not Found");
  }

  display.begin(
  SSD1306_SWITCHCAPVCC
  );
  // Clear Display
  display.clearDisplay();
  // Set Text Size
  display.setTextSize(1);
  // Set Text Color
  display.setTextColor(SSD1306_WHITE);
  // Update Display
  display.display();
}

void loop(){
  temperature= bmp.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  delay(1000);

  // Clear the display
  display.clearDisplay();
  // Move the cursor to the top-left corner
  display.setCursor(0, 0);
  // Display the label "Temp: "
  display.print("Temp: ");
  // Display the temperature value
  display.print(temperature, 1);
  // Display the temperature unit
  display.println(" *C");
  // Update the display
  display.display();
  // Wait one second
  delay(1000);
}