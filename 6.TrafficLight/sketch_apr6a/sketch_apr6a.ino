void setup()
{
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop()
{
  //GREEN
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(7, LOW);

  //YELLOW
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(4, LOW);

  //RED
  digitalWrite(9, HIGH);
  delay(3000);
  digitalWrite(9, LOW);
}


