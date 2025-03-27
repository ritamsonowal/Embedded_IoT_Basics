#define BUTTON_PIN D1
#define LED_PIN D7

int led_state=LOW;
int last_button_state;
int button_state;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  button_state=digitalRead(BUTTON_PIN);  // Read the initial button state
}
void loop()
{
  last_button_state=button_state; // Save the previous button state
  button_state=digitalRead(BUTTON_PIN); // Read the current button state
  
  if(last_button_state==HIGH && button_state==LOW)
  {
    Serial.println("The button is pressed");

    led_state=!led_state;
    digitalWrite(LED_PIN, led_state);

    if(led_state==HIGH)
      Serial.println("The button is pressed to turn on the LED");
    else
      Serial.println("The button is pressed to turn off the LED");
  }
}