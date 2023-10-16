#include <stdlib.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// const int Mot1A = A0, Mot1B = A1, Mot2A = A2, Mot2B = A3;

// const int sw1 = 2, sw2 = 3, sw3 = 4;
// const int BUZZ = 7, IR_Obst = 6;
// const int LED = LED_BUILTIN;

// Define PWM pins
// for Arduino Nano

#define S0 3 //D3
#define S1 5 //D5
#define S2 6 //D6
#define S3 9 //D9
#define sensorOut 10 //D10

#define RED_COLOR 1
#define GREEN_COLOR 2
#define BLUE_COLOR 3
#define WHITE_COLOR 4

#define SCREEN_WIDTH 128 // OLED display width, in pixels

#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

#define OLED_RESET LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin

Adafruit_SSD1306 display(SCREEN_WIDTH,
 SCREEN_HEIGHT, &Wire, OLED_RESET);
