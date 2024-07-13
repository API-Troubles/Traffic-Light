//Phase 1 lights and buttons
#define RED1 4
#define YELLOW1 3
#define GREEN1 2
#define SENSOR1 10
#define OUT1 9

//Phase 2 lights and buttons
#define RED2 5
#define YELLOW2 6
#define GREEN2 7
#define SENSOR2 12
#define OUT2 11

//Traffic light timing
#define RED_CLEAR 2000
#define YELLOW_LENGTH 2000
#define GREEN_MIN_LENGTH 5000

int phase_1 = 0;
int phase_2 = 0;

boolean sensor_1 = LOW;
boolean sensor_2 = LOW;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return 0.01723 * pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(SENSOR1, INPUT);
  pinMode(OUT1, OUTPUT);

  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(OUT2, OUTPUT);

  digitalWrite(RED2, HIGH);
  digitalWrite(RED1, HIGH);
  delay(1000); // Delay on start to fix bug
}


void loop() {
  // Phase 1 GREEN
  // Phase 2 RED
  digitalWrite(OUT1, HIGH);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN1, HIGH);
  Serial.println("phase 2 GREEN");
  
  // Wait until call to change phase
  delay(GREEN_MIN_LENGTH);
  sensor_2 = digitalRead(SENSOR2);
  while (sensor_2 == LOW) {
    sensor_2 = digitalRead(SENSOR2);
  }
  digitalWrite(OUT1, LOW); 
  // BUGFIX: Wait until our ped timer over
  // micro:bit timer is delayed?
  delay(5000); // Give the micro:bit a change to reset its call
  sensor_1 = digitalRead(SENSOR1);
  while (sensor_1 == LOW) {
    sensor_1 = digitalRead(SENSOR1);
  }

  // Phase 1 green to YELLOW
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, HIGH);
  Serial.println("Phase 1 YELLOW");
  delay(YELLOW_LENGTH);

  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, HIGH);
  delay(RED_CLEAR); // Clear phase
  Serial.println("CLEAR 1");

  // Phase 1 RED
  // Phase 2 GREEN
  digitalWrite(OUT2, HIGH);
  digitalWrite(RED2, LOW);
  digitalWrite(GREEN2, HIGH);
  Serial.println("phase 1 GREEN");
  
  // Wait untill call to change phase
  delay(GREEN_MIN_LENGTH);
  sensor_1 = digitalRead(SENSOR1);
  while (sensor_1 == LOW) {
    sensor_1 = digitalRead(SENSOR1);
  }
  digitalWrite(OUT2, LOW); 
  // BUGFIX: Wait until ped timer over
  // micro:bit timer is delayed?
  delay(5000); // Give the micro:bit a change to reset its call
  sensor_2 = digitalRead(SENSOR2);
  while (sensor_2 == LOW) {
    sensor_2 = digitalRead(SENSOR2);
  }

  // Phase 2 green to YELLOW
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, HIGH);
  delay(YELLOW_LENGTH);
  Serial.println("Phase 2 YELLOW");

  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, HIGH);
  delay(RED_CLEAR); // Clear phase
  Serial.println("CLEAR 2");
}

