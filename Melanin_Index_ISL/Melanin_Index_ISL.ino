#include "Melanin_Index.h"

int redval = 0;
int blueval = 0;
int greenval = 0;

// Calibration values

unsigned int redlow = 0;
unsigned int redhigh = 65535;
unsigned int greenlow = 0;
unsigned int greenhigh = 65535;
unsigned int bluelow = 0;
unsigned int bluehigh = 65535;

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
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3D for 128x64
    //    Serial.println(("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setCursor(0, 0);             // Start at top-left corner
  display.cp437(true);                 // Use full 256 char 'Code Page 437' font

  display.clearDisplay();
  display.setCursor(0, 0); // Start at top-left corner
  display.setTextSize(3);
  display.write("Melanin\n   Index");
  display.display();
  delay(3000);
  display.clearDisplay();
  delay(360);
}
int melIdx = 0;

// Read sensor values for each color and print them to serial monitor
void loop()
{
  // Read sensor values (16 bit integers)
  unsigned int red = RGB_sensor.readRed();
  unsigned int green = RGB_sensor.readGreen();
  unsigned int blue = RGB_sensor.readBlue();

  // Print out readings
  Serial.print("Raw Readings\n");
  Serial.print("Red: ");
  Serial.print(red, DEC);
  Serial.print(" - Green: ");
  Serial.print(green, DEC);
  Serial.print(" - Blue: ");
  Serial.print(blue, DEC);
  Serial.println();
  delay(2000);

  // Convert to RGB values
  int redV = map(red, redlow, redhigh, 0, 255);
  int greenV = map(green, greenlow, greenhigh, 0, 255);
  int blueV = map(blue, bluelow, bluehigh, 0, 255);

  // Constrain to values of 0-255
  redval = constrain(redV, 0, 255);
  greenval = constrain(greenV, 0, 255);
  blueval = constrain(blueV, 0, 255);

  // redval=36;
  // greenval=30;
  // blueval=42;

  Serial.print("Mapped Readings\n");
  Serial.print("R: ");
  Serial.print(redval);
  Serial.print(" - G: ");
  Serial.print(greenval);
  Serial.print(" - B: ");
  Serial.println(blueval);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.write("R: ");
  display.print(redval);
  display.write("\nG: ");
  display.print(greenval);
  display.write("\nB: ");
  display.print(blueval);

  // Delay for sensor to stabilize
  delay(2000);

  if ((redval > 27 && redval < 47) && (greenval > 28 && greenval < 36) && (blueval > 46 && blueval < 41))
  {
    melIdx = 36;
  }
  else if ((redval > 49 && redval < 64) && (greenval > 37 && greenval < 32) && (blueval > 41 && blueval < 21))
  {
    melIdx = 35;
  }
  else if ((redval > 64 && redval < 87) && (greenval > 32 && greenval < 50) && (blueval > 21 && blueval < 41))
  {
    melIdx = 34;
  }
  else if ((redval > 87 && redval < 96) && (greenval > 49 && greenval < 77) && (blueval > 32 && blueval < 48))
  {
    melIdx = 33;
  }
  else if ((redval > 96 && redval < 100) && (greenval > 49 && greenval < 77) && (blueval > 22 && blueval < 33))
  {
    melIdx = 32;
  }
  else if ((redval > 101 && redval < 120) && (greenval > 48 && greenval < 78) && (blueval > 32 && blueval < 48))
  {
    melIdx = 31;
  }
  else if ((redval > 121 && redval < 141) && (greenval > 77 && greenval < 88) && (blueval > 48 && blueval < 62))
  {
    melIdx = 30;
  }
  else if ((redval > 125 && redval < 135) && (greenval > 88 && greenval < 98) && (blueval > 48 && blueval < 60))
  {
    melIdx = 29;
  }
  else if ((redval > 135 && redval < 142) && (greenval > 80 && greenval < 95) && (blueval > 48 && blueval < 64))
  {
    melIdx = 28;
  }
  else if ((redval > 141 && redval < 156) && (greenval > 77 && greenval < 107) && (blueval > 48 && blueval < 67))
  {
    melIdx = 27;
  }
  else if ((redval > 156 && redval < 188) && (greenval > 107 && greenval < 151) && (blueval > 48 && blueval < 96))
  {
    melIdx = 26;
  }
  else if ((redval > 188 && redval < 199) && (greenval > 151 && greenval < 164) && (blueval > 48 && blueval < 100))
  {
    melIdx = 25;
  }
  else if ((redval > 199 && redval < 222) && (greenval > 164 && greenval < 184) && (blueval > 100 && blueval < 119))
  {
    melIdx = 24;
  }
  else if ((redval > 210 && redval < 223) && (greenval > 184 && greenval < 193) && (blueval > 90 && blueval < 123))
  {
    melIdx = 23;
  }
  else if ((redval > 215 && redval < 225) && (greenval > 151 && greenval < 193) && (blueval > 48 && blueval < 106))
  {
    melIdx = 22;
  }
  else if ((redval > 225 && redval < 235) && (greenval > 170 && greenval < 227) && (blueval > 55 && blueval < 106))
  {
    melIdx = 21;
  }
  else if ((redval > 225 && redval < 240) && (greenval > 190 && greenval < 227) && (blueval > 60 && blueval < 133))
  {
    melIdx = 20;
  }
  else if ((redval > 235 && redval < 242) && (greenval > 214 && greenval < 226) && (blueval > 133 && blueval < 160))
  {
    melIdx = 19;
  }
  else if ((redval > 236 && redval < 245) && (greenval > 220 && greenval < 230) && (blueval > 145 && blueval < 170))
  {
    melIdx = 18;
  }
  else
  {
    melIdx = 0;
  }
  Serial.print("Melanin Index: ");
  Serial.println(melIdx);
  // if(!digitalRead(4))
  {
    display.write("\nMel Idx: ");
    display.print(melIdx);
  }
  display.display();

  delay(2000);
}
