#include <ESP8266WiFi.h>
#include<DHT.h>
#include<DHT_U.h>
#define Type DHT11
int sensePin=D7;
DHT HT(sensePin,Type);
float humidity, tempC, tempF, tempK;
void setup() {
  Serial.begin(9600);
  HT.begin();

}

void loop() {
  humidity=HT.readHumidity();
  Serial.print("Humidity reading: ");
  Serial.println(humidity);
  delay(1000);
  tempC=HT.readTemperature();
  Serial.println("Temperature in Celsius: "+String(tempC));
  delay(1000);
  tempF=(tempC*9.0/5.0)+32;
  Serial.println("Temperature in Farhenheit: "+String(tempF));
  delay(1000);
  tempK=tempC+273.0;
  Serial.println("Temperature in Kelvin: "+String(tempK));
  delay(1000);
  Serial.println("====================================");
}
