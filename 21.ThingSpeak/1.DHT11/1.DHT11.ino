#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
#define DHTpin D7

DHT HT(DHTpin, Type);
float humidity, tempC;
// 8W9A3O52K32UZZL1
String apiKey = "8W9A3O52K32UZZL1";  // Enter your Write API key from ThingSpeak

const char *ssid = "student";  // Replace with your Wi-Fi SSID
const char *pass = "";          // Replace with your Wi-Fi password (leave empty if open network)
const char *server = "api.thingspeak.com";
// &field1=0
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);
  HT.begin();

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("WIFI not connected");
  }
  Serial.println("WiFi connected");
}

void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
 
  if (client.connect(server, 80)) 
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(tempC);
    postStr += "&field2=";
    postStr += String(humidity);
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

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print(" degrees Celsius, Humidity: ");
    Serial.print(humidity);
    Serial.println("%. Sent to ThingSpeak.");
  }

  client.stop();

  Serial.println("Waiting...");

  // ThingSpeak requires a minimum 15-second delay between updates
  delay(1000);
}
