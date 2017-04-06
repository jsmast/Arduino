#define pinPlus 2
#define pinMinus 4
#define BUTTON_SLEEP 15000
#define controlSignal 10
#define multiple 1
static int value = 0;
//static unsigned long milTime = 0;

void setup() {
  pinMode(pinPlus, INPUT_PULLUP);
  pinMode(pinMinus, INPUT_PULLUP);
  pinMode(controlSignal, OUTPUT);

  Serial.begin(9600);
  Serial.println("Run\n");

}

void loop(){
  //milTime = millis();
  onPlus();
  onMinus();
  analogWrite(controlSignal, value * 10);
}

// PUSH PLUS
void onPlus(){
  static unsigned int sleepTime;
  if(digitalRead(pinPlus) == LOW){
    sleepTime++;
    if(sleepTime > BUTTON_SLEEP){
      value++; 
      sleepTime = 0;
      Serial.println(value);
    }
  }
}

// PUSH MINUS
void onMinus()
{
  static unsigned int sleepTime;
  if(digitalRead(pinMinus) == LOW){
    sleepTime++;
    if(sleepTime > BUTTON_SLEEP){
      if(value > 0){
        value--;
      }
      sleepTime = 0;
      Serial.println(value);
    }
  }
}

