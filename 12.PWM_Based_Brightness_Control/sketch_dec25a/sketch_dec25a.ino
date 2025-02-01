int volt, pinValue;
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}
void loop()
{
  volt=analogRead(A2);
  pinValue=map(volt,0,1023,0,255);//map(x, in_min, in_max, out_min, out_max)
  analogWrite(11,pinValue);
  Serial.println(volt); //or pinValue if you want to see betweem 0 and 255
  delay(500);
}