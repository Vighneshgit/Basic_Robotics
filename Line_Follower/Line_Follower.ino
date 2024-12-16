// Motor Pins
#define MOTOR1_A 8  // Motor 1 pin A
#define MOTOR1_B 9  // Motor 1 pin B
#define MOTOR2_A 10 // Motor 2 pin A
#define MOTOR2_B 11 // Motor 2 pin B

// Sensor Pins
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

void setup() {
  // Set motor pins as output
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);

  // Set sensor pins as input
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
}

void loop() {
  // Read sensors
  int leftSensor = digitalRead(LEFT_SENSOR);
  int rightSensor = digitalRead(RIGHT_SENSOR);

  // Conditions for line following
  if (leftSensor == HIGH && rightSensor == HIGH) {
    // Both sensors on the line: Move both motors
    digitalWrite(MOTOR1_A, HIGH);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, HIGH);
    digitalWrite(MOTOR2_B, LOW);
  } 
  else if (leftSensor == LOW && rightSensor == HIGH) {
    // Left sensor off the line: Turn right
    digitalWrite(MOTOR1_A, LOW);  // Stop left motor
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, HIGH); // Move right motor
    digitalWrite(MOTOR2_B, LOW);
  } 
  else if (leftSensor == HIGH && rightSensor == LOW) {
    // Right sensor off the line: Turn left
    digitalWrite(MOTOR1_A, HIGH); // Move left motor
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, LOW);  // Stop right motor
    digitalWrite(MOTOR2_B, LOW);
  } 
  else {
    // Both sensors off the line: Stop both motors
    digitalWrite(MOTOR1_A, LOW);
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, LOW);
    digitalWrite(MOTOR2_B, LOW);
  }
}
