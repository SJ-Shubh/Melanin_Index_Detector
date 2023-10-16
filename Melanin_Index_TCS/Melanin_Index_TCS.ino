#include "Melanin_Index.h"

int redval = 0;
int blueval = 0;
int greenval = 0;
int PW;

// Calibration values

unsigned int redlow = 32;
unsigned int redhigh = 279;
unsigned int greenlow = 35;
unsigned int greenhigh = 275;
unsigned int bluelow = 29;
unsigned int bluehigh = 248;
void setup()
{

  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Setup Serial Monitor
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3D for 128x64
    Serial.println(("SSD1306 allocation failed"));
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
  display.write("Melanin\n Index");
  display.display();
  delay(3000);
  display.clearDisplay();
  delay(666);
}
int melIdx = 0;

// Read sensor values for each color and print them to serial monitor
void loop()
{
  // Read sensor values (16 bit integers)
  unsigned int red = getRedPW();
  delay(333);
  unsigned int green = getGreenPW();
  delay(333);
  unsigned int blue = getBluePW();
  delay(333);

serial.print(x);

//this shit is mine 
int red2,green2,blue2;

red2=red*red;
blue2=blue*blue;
green2=green*green;

int x;
x*x=red2+green2+blue2;
 

//this shit is mine


  // Print out readings
  Serial.print("Raw Readings\n");
  Serial.print("Red: ");
  Serial.print(red, DEC);
  Serial.print(" - Green: ");
  Serial.print(green, DEC);
  Serial.print(" - Blue: ");
  Serial.print(blue, DEC);
  Serial.println("\n");
  delay(333);

  // Convert to RGB values
  int redV = map(red, redlow, redhigh, 255, 0);
  int greenV = map(green, greenlow, greenhigh, 255, 0);
  int blueV = map(blue, bluelow, bluehigh, 255, 0);

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
  Serial.println();

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
  delay(666);

  if ((redval > 26 && redval < 47) && (greenval > 27 && greenval < 37) && (blueval > 46 && blueval < 41)) // R: 27-48 : G: 28-36 B: 46-40
  {
    melIdx = 36;
  }
  else if ((redval > 48 && redval < 64) && (greenval > 36 && greenval < 32) && (blueval > 41 && blueval < 21)) // R: 49-64 : G: 37-31 B: 41-20
  {
    melIdx = 35;
  }
  else if ((redval > 63 && redval < 87) && (greenval > 32 && greenval < 50) && (blueval > 21 && blueval < 41))
  {
    melIdx = 34;
  }
  else if ((redval > 86 && redval < 96) && (greenval > 49 && greenval < 77) && (blueval > 32 && blueval < 48))
  {
    melIdx = 33;
  }
  else if ((redval > 95 && redval < 100) && (greenval > 49 && greenval < 77) && (blueval > 22 && blueval < 33))
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
  Serial.println();
  // if(!digitalRead(4))
  {
    display.write("\nMel Idx: ");
    display.print(melIdx);
  }
  display.display();

  delay(2000);
}

int getRedPW()
{

  // Set sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW()
{

  // Set sensor to read Green only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Blue Pulse Widths
int getBluePW()
{

  // Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}