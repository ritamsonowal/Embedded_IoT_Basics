#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String message = "rendi ritam";

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Display initialization failed"));
    while (1); // Halt
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();
}

void loop() {
  // Read serial input
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c != '\n' && c != '\r') {
      message += c;
    }
    delay(30);
  }

  Serial.println("Message: "+message);

  // Update display based on message length
  display.clearDisplay();
  display.setCursor(0, 0);

  if (message.length() > 0) {
    // Dynamically adjust text size
    if (message.length() <= 5) {
      display.setTextSize(3);
    } else if (message.length() <= 20) {
      display.setTextSize(2);
    } else {
      display.setTextSize(1);
    }

    display.println(message);
    display.display();
  }

  // Optional: Print to serial for debugging
  Serial.println("Displayed: " + message);

  // Reset message after display
  message = "";
}