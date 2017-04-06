#include <math.h>

#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7
#define DOT_PIN 9

byte numberSegments[10] = {
  0b00111111, 0b00001010, 0b01011101, 0b01011110, 0b01101010,
  0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110,
};

int minute = 1;

void setup() {
  for(int i = 0; i < SEGMENT_COUNT; ++i){
    pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
  }
  pinMode(DOT_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Minute\tTemperature\tdT");
}

void loop() {
  int second = (millis() / 1000);
  int number = second % 10;
  int minute = second / 60;
  
  if((second % 60) == 0){
     temp(minute);
  }
  
  int mask = numberSegments[number];
  
  for(int i = 0; i < SEGMENT_COUNT; ++i){
    boolean enableSegment = bitRead(mask,i);
    digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
    //digitalWrite(i + FIRST_SEGMENT_PIN, HIGH);
  }
  
  digitalWrite(DOT_PIN, HIGH);
  delay(500);
  digitalWrite(DOT_PIN, LOW);
  delay(500);
}

void temp(int time){
  float v = analogRead(A0) * 5.0 / 1024.0;
  float temperature = -14.46 * log((10000.0 * v) / (5.0 - v) / (27074.0));
  
  Serial.print(time);
  Serial.print("\t");
  Serial.print(temperature);
  Serial.print("\t");
  Serial.println(5.0 - v);
}
