// Define pin numbers for motors and LDR sensors
int RMotor_1 = 2;
int RMotor_2 = 3;
int LMotor_1 = 4;
int LMotor_2 = 5;
int LDR_Back_Left = 9;    // Connect to the left back LDR sensor
int LDR_Back_Right = 10;  // Connect to the right back LDR sensor


// Setup function - runs once at the beginning
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  // Print a message to indicate the start of the program
  Serial.println("GPIO test!");


  // Set pin modes for motors and LDR sensors
  pinMode(RMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
  pinMode(LMotor_1, OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(LDR_Back_Left, INPUT);
  pinMode(LDR_Back_Right, INPUT);
}


// Loop function - runs repeatedly
void loop() {
  // Read values from sensors and store them in variables
  int ldrright = digitalRead(7);
  int ldrleft = digitalRead(8);
  int ldrBackLeft = digitalRead(LDR_Back_Left);
  int ldrBackRight = digitalRead(LDR_Back_Right);


  // Check conditions based on sensor readings
  if (ldrBackLeft == LOW && ldrBackRight == LOW) {
    // Both back sensors detect light - move backward
    Serial.println("Moving Backward");
    move_backward();


  } else if (ldrBackRight == LOW) {
    // Right back sensor detects light - move backward to the right
    Serial.println("Moving Backward Right");
    move_backward_right();


  } else if (ldrBackLeft == LOW) {
    // Left back sensor detects light - move backward to the left
    Serial.println("Moving Backward Left");
    move_backward_left();


  } else if (ldrright == 0 && ldrleft == 0) {
    // Both front sensors detect light - move forward
    Serial.println("Moving Forward");
    move_forward();


  } else if (ldrright == 0 && ldrleft == 1) {
    // Right front sensor detects no light and left front sensor detects no light - turn right
    Serial.println("Turning Right");
    turn_right();


  } else if (ldrright == 1 && ldrleft == 0) {
    // Left front sensor detects light and right front sensor detects light - turn left
    Serial.println("Turning Left");
    turn_left();


  } else {
    // Stop if none of the above conditions are met
    Serial.println("Stopping");
    move_stop();
  }
  // Introduce a delay to control the loop rate
  delay(100);
}


// Movement functions for different directions
void move_forward() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}


void move_backward() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}


void move_backward_right() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}


void move_backward_left() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}


void turn_right() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, HIGH);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, HIGH);
}


void turn_left() {
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
}


// Stop all motors
void move_stop() {
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
}
