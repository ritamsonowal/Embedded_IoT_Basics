#define BUTTON_PIN D1
#define LED_PIN D7

int button_state;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  button_state=digitalRead(BUTTON_PIN);
  if(button_state==LOW)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
    digitalWrite(LED_PIN, LOW);
}