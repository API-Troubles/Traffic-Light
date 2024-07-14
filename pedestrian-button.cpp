// Why is this a separate controller?
// I couldn't figure out how to loop this forever in the
// "background" so the simplest solution is to run another board.

//Define buzzer pins
#define BUZZER1 10
#define BUZZER2 11

//Receive data from the main board
#define MAIN 2
#define ADK 5

//Misc variables
boolean ped_call = false; //Call by to say switch phases
                          //True = first phase, false = second
boolean call_adk = false; //Call by to say ped pushed button
                          //True = button pushed, make that noise  


int unsigned quiet_timer = 0;
int unsigned tone_timer = 0;

void chirp(int buzzer) {
  noTone(buzzer);
  tone(buzzer, 1500);
  delay(100);
  noTone(buzzer);
}

void loop_locator(int buzzer) {
  tone(buzzer, 880);
  
  // How long the tone lasts
  delay(60);
  
  // Repeat interval
  noTone(buzzer);
  delay(1000);
}

void setup(){
  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);
  pinMode(MAIN, INPUT);
  pinMode(ADK, INPUT);
   
  // Wait until phase 1 is GREEN
  ped_call = digitalRead(MAIN);
  while (ped_call == false) {
    ped_call = digitalRead(MAIN);
  }
}

void loop() {
  if 
  ped_call = digitalRead(MAIN);
  call_adk = digitalRead(ADK);
  if (ped_call) {
    loop_locator(BUZZER2);
    chirp(BUZZER2);
  } else {
    loop_locator(BUZZER1);
  }
  if (call_adk && ped_call == true) {
    chirp(BUZZER2);
  } else if (call_adk && ped_call == false) {
    chirp(BUZZER1);
  }
}
