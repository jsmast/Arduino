#define CONTROL_PIN 9

int brightness = 0;

void setup() {
  pinMode(CONTROL_PIN, OUTPUT);
}

void loop() {
  brightness = (brightness + 1) % 256;
  
  analogWrite(CONTROL_PIN, brightness);
  //analogWrite(CONTROL_PIN, 255);
  delay(10);
}
