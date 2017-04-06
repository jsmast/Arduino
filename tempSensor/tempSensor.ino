/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

float calibrate = 5.0 / 1024.0;
float voltage = 0;
float tempC = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  voltage = sensorValue * calibrate;
  // print out the value you read:
  Serial.print("Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Calibrate: ");
  //Serial.print(calibrate, 3);
  Serial.print( calibrate, 3);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print(" | Temp, C: ");
  Serial.print(voltage * 10);
  Serial.print("\n");
  delay(500);        // delay in between reads for stability
}
