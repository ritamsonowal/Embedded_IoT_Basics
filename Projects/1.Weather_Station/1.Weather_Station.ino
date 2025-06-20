#include<ESP8266WiFi.h>
//DHT11 
#include<DHT.h>
#include<DHT_u.h>
#define Type DHT11
#define DHTpin D7
DHT HT(DHTpin, Type);

//BMP180
#include<Adafruit_BMP085.h>

//OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_WIDTH 128 // OLED width,  in pixels
#define OLED_HEIGHT 64 // OLED height, in pixels

Adafruit_BMP085 bmp; //Adafruit_BMP085 class as bmp
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);// create an OLED display object connected to I2C
float humidity, tempDH, tempBMP, temp, pressure;

String apiKey = "U9126TNM4GLW9VD4";  // Enter your Write API key from ThingSpeak

const char *ssid = "Galaxy F23 5G FB28";  // Replace with your Wi-Fi SSID
const char *pass = "qwertyuiop";          // Replace with your Wi-Fi password (leave empty if open network)
const char *server = "api.thingspeak.com";
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  delay(10);
  HT.begin();
  bmp.begin();

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) //OLED
  {
    Serial.println(F("Failed to start SSD1306 OLED"));
    while (1);
  }
  oled.display(); //Display logo
  delay(1000); 

 

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("WIFI not connected");
  }
  Serial.println("WiFi connected");
}

void loop()
{
  oled.clearDisplay();
  temperatureRead();
  oledDisplay();
  connect();
}

void temperatureRead()
{
  humidity = HT.readHumidity();
  tempDH = HT.readTemperature();
  if (!bmp.begin()) {
    Serial.println("BMP180 not detected!");
    tempBMP = 0; // Avoid using uninitialized value
  } else {
    tempBMP = bmp.readTemperature();
    pressure = bmp.readPressure();
  }
  temp = (tempDH + tempBMP) / 2;
}

void connect()
{
  if (client.connect(server, 80)) 
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(humidity);
    postStr += "&field2=";
    postStr += String(temp);
    postStr += "&field3=";
    postStr += String(pressure);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.println("Humidity: "+String(humidity)+"%");
    delay(1000);
    Serial.println("Temperature: "+String(temp)+"C");
    delay(1000);
    Serial.println("Pressure: "+String(pressure)+"Pa");
    delay(1000);
    Serial.println("%. Sent to ThingSpeak.");
  }
  client.stop();
  Serial.println("Waiting...");
  Serial.println("-------------------");
  // ThingSpeak requires a minimum 15-second delay between updates
  delay(15000);
}

void oledDisplay()
{
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);
  oled.print("Humidity: ");
  oled.print(humidity);
  oled.print("%");
  oled.setCursor(0, 10);
  oled.print("Temperature: ");
  oled.print(temp);
  oled.print("C");
  oled.setCursor(0, 20);
  oled.print("Pressure: ");
  oled.print(pressure);
  oled.print("Pa");
  oled.display();
}
