#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128 // OLED width,  in pixels
#define OLED_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000); // wait two seconds for initializing
  oled.setCursor(0, 0);
}

void loop() {
  // draw a circle
  oled.clearDisplay();
  oled.drawCircle(20, 35, 20, WHITE);
  oled.display();
  delay(1000);

  // fill a circle
  oled.clearDisplay();
  oled.fillCircle(20, 35, 20, WHITE);
  oled.display();
  delay(1000);

  // draw a triangle
  oled.clearDisplay();
  oled.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
  oled.display();
  delay(1000);

  // fill a triangle
  oled.clearDisplay();
  oled.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
  oled.display();
  delay(1000);

  // draw a rectangle
  oled.clearDisplay();
  oled.drawRect(0, 15, 60, 40, WHITE);
  oled.display();
  delay(1000);

  // fill a rectangle
  oled.clearDisplay();
  oled.fillRect(0, 15, 60, 40, WHITE);
  oled.display();
  delay(1000);

  // draw a round rectangle
  oled.clearDisplay();
  oled.drawRoundRect(0, 15, 60, 40, 8, WHITE);
  oled.display();
  delay(1000);

  // fill a round rectangle
  oled.clearDisplay();
  oled.fillRoundRect(0, 15, 60, 40, 8, WHITE);
  oled.display();
  delay(1000);
}
