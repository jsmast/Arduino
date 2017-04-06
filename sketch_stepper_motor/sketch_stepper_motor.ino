// 20 steps per laps
#define phase_A_IA 8
#define phase_A_IB 9
#define phase_B_IA 10
#define phase_B_IB 11
#define BT_FWD 3
#define BT_BWD 4
#define sleep 2
//#define steps 4
//#define phases 4
int phases[4][4] = {
  {1,0,0,0},
  {0,0,0,1},
  {0,1,0,0},
  {0,0,1,0},
};
void setup()
{
  Serial.begin(9600);
  pinMode(phase_A_IA, OUTPUT);
  pinMode(phase_A_IB, OUTPUT);
  pinMode(phase_B_IA, OUTPUT);
  pinMode(phase_B_IB, OUTPUT);
  pinMode(BT_FWD, INPUT_PULLUP);
  pinMode(BT_BWD, INPUT_PULLUP);
}

void loop()
{
  int p = 0;
    while(1)
    {
      bool fwd = !digitalRead(BT_FWD);
      bool bwd = !digitalRead(BT_BWD);
      if(fwd || bwd){
        //Serial.println("BT FWD PUSHED:");
        for(int i = 0; i < 20; i++){
          digitalWrite(phase_A_IA, phases[p][0]);
          digitalWrite(phase_A_IB, phases[p][1]);
          digitalWrite(phase_B_IA, phases[p][2]);
          digitalWrite(phase_B_IB, phases[p][3]);
          if(fwd){
            p++;
            if(p == 4){ p = 0; }
          } else {
            p--;
            if(p == -1) {p = 3;}
          }
          delay(sleep);
        }

/*        digitalWrite(phase_A_IA, HIGH);
        digitalWrite(phase_A_IB, LOW);
        digitalWrite(phase_B_IA, LOW);
        digitalWrite(phase_B_IB, LOW);
        delay(sleep);
        digitalWrite(phase_A_IA, LOW);
        digitalWrite(phase_A_IB, LOW);
        digitalWrite(phase_B_IA, LOW);
        digitalWrite(phase_B_IB, HIGH);
        delay(sleep);
        digitalWrite(phase_A_IA, LOW);
        digitalWrite(phase_A_IB, HIGH);
        digitalWrite(phase_B_IA, LOW);
        digitalWrite(phase_B_IB, LOW);
        delay(sleep);
        digitalWrite(phase_A_IA, LOW);
        digitalWrite(phase_A_IB, LOW);
        digitalWrite(phase_B_IA, HIGH);
        digitalWrite(phase_B_IB, LOW);
        delay(sleep);
        break;*/
      }
    }
}
