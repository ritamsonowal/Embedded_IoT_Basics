void setup()
{
  pinMode(A2, OUTPUT);
}
void loop()
{
  for(int i=0; i<=255; i++)
  {
    analogWrite(A2, i);
    delay(10);
  }
  for(int j=255; j>=0; j--)
  {
    analogWrite(A2, j);
    delay(10);
  }
}