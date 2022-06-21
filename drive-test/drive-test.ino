//Code for testing the driving capabilities of the robot kit for the STEM Institute summer 2022 engineering class
//Written by Dylan Kirdahy


//The pins for the motor driver
#define left_forwards 5
#define left_backwards 3
#define right_forwards 6
#define right_backwards 9


void setup() {
  //Set the pins as outputs
  pinMode(left_forwards, OUTPUT);
  pinMode(left_backwards, OUTPUT);
  pinMode(right_forwards, OUTPUT);
  pinMode(right_backwards, OUTPUT);
}

//The main loop makes the robot drive, turn roughly 90 degrees, and drive again
void loop() {
  //Make the robot move forwards for 1 second
  digitalWrite(right_forwards, HIGH);
  digitalWrite(left_forwards, HIGH);
  delay(1000);
  //Make the robot turn right for half a second
  digitalWrite(left_forwards, LOW);
  digitalWrite(left_backwards, HIGH);
  delay(500);
  digitalWrite(left_backwards, LOW);
}
