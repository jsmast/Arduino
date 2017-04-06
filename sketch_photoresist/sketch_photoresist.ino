#define photo_sensor A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float Vin = 5;
  float Vout = analogRead(photo_sensor)*5/1024.0;
  float R1 = 10;
  float R2 = (Vout * R1)/(Vin - Vout);
  float I = Vout/R2;
  Serial.print("Vout: ");
  Serial.print(Vout);
  Serial.print("\t R2: ");
  Serial.print(R2);
  Serial.print(" kOm");
  Serial.print("\t I: ");
  Serial.print(I);
  Serial.println(" A");
      
  delay(500);
}
