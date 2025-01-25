int myVariable = 7; 
void setup() 
{
  serial.begin(9600);
  serial.println(myVariable);
  myVariable=myVariable+3;
  serial.print(myVariable);
}

void loop() 
{
 
}
