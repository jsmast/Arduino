#define BUZZER_PIN     13
#define FIRST_KEY_PIN  7
#define KEY_COUNT      3
#define FREQ_MIN  500
#define FREQ_MUL 500

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  /*for(int i = 0; i < KEY_COUNT; ++i){
    int keyPin = i + FIRST_KEY_PIN;
    
    boolean keyUp = digitalRead(keyPin);
    
    if(!keyUp){
      int frequency = 500 + i * 500;
      
      tone(BUZZER_PIN, frequency, 20);
    }
  }*/
  int frequency = 0;
  boolean keyUp = digitalRead(FIRST_KEY_PIN);
  if(!keyUp){
    // 1 ****************************
    buzzer(0,400,600);
    buzzer(0,400,600);
    buzzer(0,400,600);
   
    // 2 ****************************
    buzzer(0,400,400);
    buzzer(1,200,200);
    buzzer(0,400,600);
    buzzer(0,400,400);
    buzzer(1,200,200);
    buzzer(0,400,800);
    
    // 3 ****************************
    buzzer(2,400,600);
    buzzer(2,400,600);
    buzzer(2,400,600);
    
    // 4 ****************************
    buzzer(2,400,400);
    buzzer(1,200,200);
    buzzer(2,400,600);
    buzzer(2,400,400);
    buzzer(1,200,200);
    buzzer(2,400,800);
    
  }
}

void buzzer(int tn, int len, int pause){
  int frequency = FREQ_MIN + tn * FREQ_MUL;
  tone(BUZZER_PIN, frequency, len);
  delay(pause);
}
