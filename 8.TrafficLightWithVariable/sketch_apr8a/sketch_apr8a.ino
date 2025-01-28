int DELAY= 2000;
void setup()
{
  
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop()
{
  //gREEN
  digitalWrite(7, HIGH);
  delay(DELAY);
  digitalWrite(7, LOW);

  //YELLOW
  digitalWrite(4, HIGH);
  delay(DELAY);
  digitalWrite(4, LOW);

  //RED
  digitalWrite(9, HIGH);
  delay(DELAY);
  digitalWrite(9, LOW);
}


