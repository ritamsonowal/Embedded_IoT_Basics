int analogReading; 
float volt, celsius, farhen;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read analog input
  analogReading = analogRead(A0);
  Serial.println("Analog reading: " + String(analogReading));
  
  // Convert analog reading to voltage
  volt = (5.0 / 1023.0) * analogReading;
  Serial.print("Voltage Reading: ");
  Serial.println(volt, 2); // Print voltage with 2 decimal places
  
  // Convert voltage to Celsius
  celsius = 100 * (volt - 0.5);
  Serial.println("Celsius reading: " + String(celsius, 2)); // 2 decimal places
  
  // Convert Celsius to Fahrenheit
  farhen = (celsius * 9.0 / 5.0) + 32.0;
  Serial.println("Fahrenheit reading: " + String(farhen, 2)); // 2 decimal places
  
  delay(3000); // Wait for 3 seconds before repeating
}