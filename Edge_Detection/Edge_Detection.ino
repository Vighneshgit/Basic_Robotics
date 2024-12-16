// Motor Pins
#define MOTOR1_A 8  // Motor 1 pin A
#define MOTOR1_B 9  // Motor 1 pin B
#define MOTOR2_A 10 // Motor 2 pin A
#define MOTOR2_B 11 // Motor 2 pin B

// Edge Sensor Pin
#define EDGE_SENSOR A0

void setup() {
  // Set motor pins as output
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);

  // Set edge sensor pin as input
  pinMode(EDGE_SENSOR, INPUT);
}

void loop() {
  // Read edge sensor
  int edgeDetected = digitalRead(EDGE_SENSOR);

  if (edgeDetected == LOW) {
 
    digitalWrite(MOTOR1_A, LOW); // Stop Motor 1
    digitalWrite(MOTOR1_B, LOW);
    digitalWrite(MOTOR2_A, LOW); // Stop Motor 2
    digitalWrite(MOTOR2_B, LOW);
    delay(500); 

    digitalWrite(MOTOR1_A, LOW); 
    digitalWrite(MOTOR1_B, HIGH); // Motor 1 Backward
    digitalWrite(MOTOR2_A, LOW); 
    digitalWrite(MOTOR2_B, HIGH); // Motor 2 Backward
    delay(500); 

    digitalWrite(MOTOR1_A, LOW); 
    digitalWrite(MOTOR1_B, HIGH); // Motor 1 Backward
    digitalWrite(MOTOR2_A, HIGH); 
    digitalWrite(MOTOR2_B, LOW);  // Motor 2 Forward
    delay(700); 
  } 
  else 
  {
    digitalWrite(MOTOR1_A, HIGH); 
    digitalWrite(MOTOR1_B, LOW); // Motor 1 Forward
    digitalWrite(MOTOR2_A, HIGH); 
    digitalWrite(MOTOR2_B, LOW); // Motor 2 Forward
  }
}
