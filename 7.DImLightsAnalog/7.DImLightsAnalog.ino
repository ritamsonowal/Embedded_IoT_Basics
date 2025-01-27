int redPin = 10; //analogs pin also can be used such as A0 
void setup() 
{
 pinMode(redPin, OUTPUT);

}

void loop() 
{
  analogWrite(redPin, 255); //means fully on 
  delay(3000);
  analogWrite(redPin, 128); //half on(led)
  delay(2000);
  analogWrite(redPin, 40); //led is dim
  delay(1000);
}
