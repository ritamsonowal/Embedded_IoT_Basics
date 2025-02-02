int volt, pwmValue;
void setup()
{
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  volt=analogRead(A5);
  pwmValue=map(volt,0,1023,255,0);//ulta because less light at photoresistor, more the led will glow 
  analogWrite(3, pwmValue);
  Serial.println(pwmValue);
  delay(500);
}