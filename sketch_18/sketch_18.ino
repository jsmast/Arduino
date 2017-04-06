#include <LiquidCrystal.h>
#define DIODE_DROP 0.7
#define NOISE 0.48
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Battery voltage");

}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage = (analogRead(A0) / 1024.0 * 10.0);
  float v = 0;
  lcd.setCursor(0,1);
  //lcd.print("HELLO");
  //voltage -= NOISE;
  if(voltage > 1){
    //voltage += DIODE_DROP;
    v = voltage + DIODE_DROP - NOISE;
    //v -= 0.90;
  }
  lcd.print(v, 2);
  lcd.print(" Volts");

}
