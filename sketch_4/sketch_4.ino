#define BUZZER_PIN 3
#define LDR_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val, frequency;
  
  val = analogRead(LDR_PIN);
  frequency = map(val, 0, 1023, 4500, 3500);
  
  tone(BUZZER_PIN, frequency,20);
}
