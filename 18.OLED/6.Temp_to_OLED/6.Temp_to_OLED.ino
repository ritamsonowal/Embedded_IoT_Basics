//DHT11
#include <ESP8266WiFi.h>
#include<DHT.h>
#include<DHT_U.h>
#define Type DHT11
int sensePin=D6;
DHT HT(sensePin,Type);
float humidity, tempC, tempF;

//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128 // OLED width,  in pixels
#define OLED_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(9600);
  //For DHT11
  HT.begin();
  //For OLED
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  oled.display(); //Display logo
  delay(1000); 
}

void loop()
{
  oled.clearDisplay();
  temperature();
  oledDisplayHeader();
  oledDisplay(3, 5, 28, humidity, "%");
  oledDisplay(2, 70, 16, tempC, "C");
  oledDisplay(2, 70, 44, tempF, "F");
  oled.display();
  Serial.println("----------------------------------");
}

void temperature()
{
  humidity=HT.readHumidity();
  Serial.println("Humidity: "+String(humidity)+"%");
  delay(1000);

  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);
  delay(1000);
  Serial.println("Temperature:");

  Serial.print(tempC,1);
  Serial.print(" ~ ");
  Serial.print(tempF,1);
  Serial.println("F");
  delay(1000);
}
void oledDisplayHeader() {
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);
  oled.print("Humidity");
  oled.setCursor(60, 0);
  oled.print("Temperature");
}

void oledDisplay(int size, int x, int y, float value, const char* unit) {
  int charLen = 12;
  int xo = x + charLen * 3.2;
  int xunit = x + charLen * 3.6;
  int xval = x;
  if (unit == "%") 
  {
    oled.setCursor(x, y);
    oled.print(value, 0);
    oled.print(unit);
  } 
  else 
  {
    if (value > 99) 
    {
      xval = x;
    } 
    else 
    {
      xval = x + charLen;
    }
    oled.setCursor(xval, y);
    oled.print(value, 0);
    oled.drawCircle(xo, y + 2, 2, WHITE); // Degree symbol
    oled.setCursor(xunit, y);
    oled.print(unit);
  }
}