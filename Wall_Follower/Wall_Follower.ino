#define TRIG_PIN 6
#define ECHO_PIN 7

#define MOTOR1_A 8 // Motor 1 control pins
#define MOTOR1_B 9
#define MOTOR2_A 10 // Motor 2 control pins
#define MOTOR2_B 11

void setup() 
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);
}

long measureDistance() 
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH) / 58; // Convert to cm
}

void moveForward() {
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
}

void turnLeft() 
{
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
}

void turnRight() 
{
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
}

void stopMotors() 
{
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
}

void loop() {
  long distance = measureDistance();

  if (distance < 15) {        // Too close to wall
    turnRight();
  } 
  else if (distance > 25) { // Too far from wall
    turnLeft();
  } 
  else {                    // Correct distance
    moveForward();
  }
}
