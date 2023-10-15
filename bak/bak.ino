/******************************************************************************
ISL29125_basics.ino
Simple example for using the ISL29125 RGB sensor library.
Jordan McConnell @ SparkFun Electronics
11 Apr 2014
https://github.com/sparkfun/SparkFun_ISL29125_Breakout_Arduino_Library
This example declares an SFE_ISL29125 object called RGB_sensor. The 
object/sensor is initialized with a basic configuration so that it continuously
samples the light intensity of red, green and blue spectrums. These values are
read from the sensor every 2 seconds and printed to the Serial monitor.
Developed/Tested with:
Arduino Uno
Arduino IDE 1.0.5
Requires:
SparkFun_ISL29125_Arduino_Library
This code is beerware.
Distributed as-is; no warranty is given. 
******************************************************************************/

#include "Melanin_Index.h"

int red = 0;
int blue = 0;
int green = 0;

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.println("Sensor Initialization Successful\n\r");
  }
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3D for 128x64
//    Serial.println(("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.clearDisplay();
  display.setCursor(0, 0);     // Start at top-left corner
  display.setTextSize(3);
  display.write("Melanin\nIndex");
//  display.setCursor(0, 15);
//  display.setTextSize(2);
//  display.write("Index");
  display.display();
  delay(3000);
  display.clearDisplay();
}
int melIdx = 0;

// Read sensor values for each color and print them to serial monitor
void loop()
{
  // Read sensor values (16 bit integers)
  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();
  
  // Print out readings, change HEX to DEC if you prefer decimal output
 // Serial.print("R:"); Serial.print(red);
 // Serial.print(" G:"); Serial.print(green);
//  Serial.print(" B:"); Serial.println(blue);
  Serial.println();

  // convert to rgb values 
// red = map (red,0,255);
// green = map (green,0,255);
// blue = map (blue,0,255);

  // constrain to values of 255 
//red = constrain(red,0,255);
//green = constrain(green,0,255);
//blue = constrain(blue,0,255);

  display.clearDisplay();
  display.setCursor(0, 0);     // Start at top-left corner
  display.setTextSize(2);
  display.write("R: ");display.print(red);
  display.write("\nG: ");display.print(green);
  display.write("\nB: ");display.print(blue);

  if((red > 27 && red < 47) && (green > 28 && green < 36) && (blue > 46 && blue < 41))
  {
    melIdx = 36;
  }
  else if((red > 49&& red < 64) && (green > 37 && green < 32) && (blue > 41 && blue < 21))
  {
    melIdx = 35;
  }
  else if((red > 64 && red < 87) && (green > 32 && green < 50) && (blue > 21 && blue < 41))
  {
    melIdx = 34;
  }
  else if((red > 87 && red < 96) && (green > 49 && green < 77) && (blue > 32 && blue < 48))
  {
    melIdx = 33;
  }
  else if((red >96  && red < 100) && (green > 49 && green < 77) && (blue > 22 && blue < 33))
  {
    melIdx = 32;
  }
  else if((red > 101 && red < 120) && (green > 48 && green < 78) && (blue > 32 && blue < 48))
  {
    melIdx = 31;
  }
  else if((red > 121 && red < 141) && (green > 77 && green < 88) && (blue > 48 && blue < 62))
  {
    melIdx = 30;
  }
    else if((red > 125 && red < 135) && (green > 88 && green < 98) && (blue > 48 && blue < 60))
  {
    melIdx = 29;
  }
    else if((red > 135 && red < 142) && (green > 80 && green < 95) && (blue > 48 && blue < 64))
  {
    melIdx = 28;
  }
    else if((red > 141 && red < 156) && (green > 77 && green < 107) && (blue > 48 && blue < 67))
  {
    melIdx = 27;
  }
    else if((red > 156 && red < 188) && (green > 107 && green < 151) && (blue > 48 && blue < 96))
  {
    melIdx = 26;
  }
    else if((red > 188 && red < 199) && (green > 151 && green < 164) && (blue > 48 && blue < 100))
  {
    melIdx = 25;
  }
    else if((red > 199 && red < 222) && (green > 164 && green < 184) && (blue > 100 && blue < 119))
  {
    melIdx = 24;
  }
    else if((red > 210 && red < 223) && (green > 184 && green < 193) && (blue > 90 && blue < 123 ))
    {
    melIdx = 23;
  }
    else if((red > 215 && red < 225) && (green > 151 && green < 193) && (blue > 48 && blue < 106))
  {
    melIdx = 22;
  }
   else if((red > 225 && red < 235) && (green > 170 && green < 227) && (blue > 55 && blue < 106))
  {
    melIdx = 21;
  }
   else if((red > 225 && red < 240) && (green > 190 && green < 227) && (blue > 60 && blue < 133))
  {
    melIdx = 20;
  }
   else if((red > 235 && red < 242) && (green > 214 && green < 226) && (blue > 133 && blue < 160))
  {
    melIdx = 19;
  }
   else if((red > 236 && red < 245) && (green > 220 && green < 230) && (blue > 145 && blue < 170))
  {
    melIdx = 18;
  }
  else
  {
    melIdx = 0;
  }
  Serial.print("Melanin Index:");
  Serial.println(melIdx);
  //if(!digitalRead(4))
  {
    display.write("\nMel Idx:");display.print(melIdx);
  }
    display.display();

  delay(2000);
}
