enum states {IDLE, WARNING, DANGER};
states currentState = IDLE;
#define TRIGGER_FL 2
#define ECHO_FL 3
#define TRIGGER_FR 4
#define ECHO_FR 5
#define TRIGGER_BL 12
#define ECHO_BL 13
#define TRIGGER_BR 10
#define ECHO_BR 11
#define LED_FL 7
#define LED_FR 6
#define LED_BL 9
#define LED_BR 8
#define BUZZER 1  

unsigned long lastBuzzer = 0;
bool buzzerState = false;
unsigned long cur_time;

void output(int FL, int FR, int BL, int BR, int B){
  digitalWrite(LED_FL, FL);
  digitalWrite(LED_FR, FR);
  digitalWrite(LED_BL, BL);
  digitalWrite(LED_BR, BR);
  digitalWrite(BUZZER, B);
}

float calculatedistance(int T, int E){
  digitalWrite(T, LOW);
  delayMicroseconds(2);
  digitalWrite(T, HIGH);
  delayMicroseconds(10);
  digitalWrite(T, LOW);
  unsigned long duration = pulseIn(E, HIGH);
  float distance = duration * 0.034 / 2.0;
  return distance;
}

void setup(){
  pinMode(TRIGGER_FL, OUTPUT);  
  pinMode(ECHO_FL, INPUT);
  pinMode(TRIGGER_FR, OUTPUT);  
  pinMode(ECHO_FR, INPUT);
  pinMode(TRIGGER_BL, OUTPUT);  
  pinMode(ECHO_BL, INPUT);
  pinMode(TRIGGER_BR, OUTPUT);  
  pinMode(ECHO_BR, INPUT);
  pinMode(LED_FL, OUTPUT);
  pinMode(LED_FR, OUTPUT);
  pinMode(LED_BL, OUTPUT);
  pinMode(LED_BR, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop(){
  float distance_FL = calculatedistance(TRIGGER_FL, ECHO_FL);
  float distance_FR = calculatedistance(TRIGGER_FR, ECHO_FR);
  float distance_BL = calculatedistance(TRIGGER_BL, ECHO_BL);
  float distance_BR = calculatedistance(TRIGGER_BR, ECHO_BR);
  int FL = (distance_FL < 80);
  int FR = (distance_FR < 80);
  int BL = (distance_BL < 80);
  int BR = (distance_BR < 80);
  bool obstacleUnder80 = FL || FR || BL || BR;
  bool obstacleUnder30 = (distance_FL < 30) || (distance_FR < 30) || (distance_BL < 30) || (distance_BR < 30);
  
  if (!obstacleUnder80) currentState = IDLE;
  else if (obstacleUnder30) currentState = DANGER;
  else currentState = WARNING;
    
  cur_time = millis();

  switch(currentState){
    case IDLE:
      output(0,0,0,0,0);
      buzzerState = false;
      break;
    case WARNING:
      output(FL, FR, BL, BR, buzzerState);
      if (cur_time - lastBuzzer >= 500){
        lastBuzzer = cur_time;
        buzzerState = !buzzerState;
      }     
      break;
    case DANGER:
     output(FL, FR, BL, BR, buzzerState);
      if (cur_time - lastBuzzer >= 200){
        lastBuzzer = cur_time;
        buzzerState = !buzzerState;
      }     
      break;
  }
}
