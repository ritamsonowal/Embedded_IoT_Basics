int PIN_RED   = D5;
int PIN_GREEN = D6;
int PIN_BLUE  = D7;

void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}
void loop() {
  // color code #00C9CC (R = 0,   G = 201, B = 204)
  analogWrite(PIN_RED,   255-158); //because common anode so 255- whatever value
  analogWrite(PIN_GREEN, 255-201);
  analogWrite(PIN_BLUE,  255-204);
  delay(1000); // keep the color 1 second

  // color code #F7788A (R = 247, G = 120, B = 138)
  analogWrite(PIN_RED,   255-247);
  analogWrite(PIN_GREEN, 255-120);
  analogWrite(PIN_BLUE,  255-138);
  delay(1000); // keep the color 1 second

  // color code #34A853 (R = 52,  G = 168, B = 83)
  analogWrite(PIN_RED,   255-52);
  analogWrite(PIN_GREEN, 255-168);
  analogWrite(PIN_BLUE,  255-83);
  delay(1000); // keep the color 1 second
}
