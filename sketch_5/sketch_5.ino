#define LED_PIN 13
#define LDR_PIN A0
#define POT_PIN A1

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightness = analogRead(LDR_PIN);
  
  int threshold = analogRead(POT_PIN);
  
  boolean tooDark = (lightness < threshold);
  
  if(tooDark){
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
