//Some testing I did to make a pedrestrian push button
//Work in progress

#define buzzer 7
#define sensor_1 3

boolean ped_call = false;
boolean call_adk = false;


void setup(){
  pinMode(buzzer, OUTPUT);
}

int unsigned quiet_timer = 0;
int unsigned tone_timer = 0;

void loop_locator_tone() {
  ped_call = digitalRead(sensor_1);
  tone(buzzer, 880);
  
  // How long the tone lasts
  while (tone_timer < 150) {
    if (ped_call && call_adk == false) {
      noTone(buzzer);
      tone(buzzer, 900);
      delay(100);
      noTone(buzzer);
      call_adk = true;
    }
    ped_call = digitalRead(sensor_1);
    delay(1);
    tone_timer++;
  }
  
  // Repeat interval
  noTone(buzzer);
  while (quiet_timer < 1300) {
    if (ped_call && call_adk == false) {
      noTone(buzzer);
      tone(buzzer, 900);
      delay(100);
      noTone(buzzer);
      call_adk = true;
    }
    ped_call = digitalRead(sensor_1);
    delay(1);
    quiet_timer++;
  }
  tone_timer = 0;
  quiet_timer = 0;
}

void loop(){
  loop_locator_tone();
}
