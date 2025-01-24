int myDelayVal = 1000;
void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(myDelayVal);                      // wait for a second
  digitalWrite(13, LOW);   // turn the LED off by making the voltage LOW
  delay(myDelayVal);                      // wait for a second
}
