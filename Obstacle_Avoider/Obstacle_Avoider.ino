// Motor Pins
#define MOTOR1_A 8  // Motor 1 pin A
#define MOTOR1_B 9  // Motor 1 pin B
#define MOTOR2_A 10 // Motor 2 pin A
#define MOTOR2_B 11 // Motor 2 pin B

// Ultrasonic Sensor Pins
#define TRIG_PIN 6
#define ECHO_PIN 7

void setup() {
  // Set ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Set motor pins as output
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);
}

// Function to measure distance using ultrasonic sensor
long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH) / 58; // Convert to centimeters
}

void loop() {
  long distance = measureDistance();

  if (distance > 20) {
    // No obstacle: Move forward
    digitalWrite(MOTOR1_A, HIGH); 
    digitalWrite(MOTOR1_B, LOW);  // Motor 1 Forward
    digitalWrite(MOTOR2_A, HIGH); 
    digitalWrite(MOTOR2_B, LOW);  // Motor 2 Forward
  } 
  else 
  {
    // Obstacle detected: Stop
    digitalWrite(MOTOR1_A, LOW); 
    digitalWrite(MOTOR1_B, LOW);  // Stop Motor 1
    digitalWrite(MOTOR2_A, LOW); 
    digitalWrite(MOTOR2_B, LOW);  // Stop Motor 2
    delay(500); // Pause briefly

    // Move backward
    digitalWrite(MOTOR1_A, LOW); 
    digitalWrite(MOTOR1_B, HIGH); // Motor 1 Backward
    digitalWrite(MOTOR2_A, LOW); 
    digitalWrite(MOTOR2_B, HIGH); // Motor 2 Backward
    delay(500); // Move backward for a short distance

    // Turn right 
    digitalWrite(MOTOR1_A, LOW); 
    digitalWrite(MOTOR1_B, HIGH); // Motor 1 Backward
    digitalWrite(MOTOR2_A, HIGH); 
    digitalWrite(MOTOR2_B, LOW);  // Motor 2 Forward
    delay(700); // Turn duration

    // Resume moving forward
    digitalWrite(MOTOR1_A, HIGH); 
    digitalWrite(MOTOR1_B, LOW);  // Motor 1 Forward
    digitalWrite(MOTOR2_A, HIGH); 
    digitalWrite(MOTOR2_B, LOW);  // Motor 2 Forward
  }
}
