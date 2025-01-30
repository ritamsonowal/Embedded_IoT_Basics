int readPin=A5;
float voltage;
void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage=(5.0/1023.0)*analogRead(readPin);
  Serial.println(voltage);
  delay(500);
}
