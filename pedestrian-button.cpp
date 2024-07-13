// Code for Arduino located most uo

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

void press_chirp_1() {
  noTone(BUZZER1);
  tone(BUZZER1, 1500);
  delay(100);
  noTone(BUZZER1);
}

void press_chirp_2() {
  noTone(BUZZER2);
  tone(BUZZER2, 1500);
  delay(100);
  noTone(BUZZER2);
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


void buzzer_phase_1() {
  tone(BUZZER2, 880);
  
  // How long the tone lasts
  while (tone_timer < 60) {
    if (call_adk) {
      press_chirp_2();
    }
    delay(10);
    call_adk = digitalRead(ADK);
    tone_timer += 10;
  }
  
  // Repeat interval
  noTone(BUZZER2);
  while (quiet_timer < 1000) {
    if (call_adk) {
      press_chirp_2();
    }
    delay(10);
    call_adk = digitalRead(ADK);
    quiet_timer += 10;
  }
  tone_timer = 0;
  quiet_timer = 0;
}

void buzzer_phase_2() {
  tone(BUZZER1, 880);
  
  // How long the tone lasts
  while (tone_timer < 60) {
    if (call_adk) {
      press_chirp_1();
    }
    delay(10);
    call_adk = digitalRead(ADK);
    tone_timer += 10;
  }
  
  // Repeat interval
  noTone(BUZZER1);
  while (quiet_timer < 1000) {
    if (call_adk) {
      press_chirp_1();
    }
    delay(10);
    call_adk = digitalRead(ADK);
    quiet_timer += 10;
  }
  tone_timer = 0;
  quiet_timer = 0;
}

void loop() {
  ped_call = digitalRead(MAIN);
  if (ped_call) {
    buzzer_phase_1();
  } else {
    buzzer_phase_2();
  }
}
