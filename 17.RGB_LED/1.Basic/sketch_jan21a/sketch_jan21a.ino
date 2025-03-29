int pinRed=D5;
int pinGreen=D6;
int pinBlue=D7;

void setup()
{
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop()
{
  analogWrite(pinRed, 255-255);
  analogWrite(pinBlue, 255-0);
  analogWrite(pinGreen, 255-0);
  delay(1000);

  analogWrite(pinRed, 255-0);
  analogWrite(pinBlue, 255-255);
  analogWrite(pinGreen, 255-0);
  delay(1000);

  analogWrite(pinRed, 255-0);
  analogWrite(pinBlue, 255-0);
  analogWrite(pinGreen, 255-255);
  delay(1000);
}
