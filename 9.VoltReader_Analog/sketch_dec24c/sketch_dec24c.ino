int readPin=A5;
void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(readPin)); // ln after print means that it will be printed ina new line 
  delay(500); //optional b 
}
