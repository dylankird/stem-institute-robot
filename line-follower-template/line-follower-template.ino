//The pins for the motor driver
#define left_forwards 5
#define left_backwards 3
#define right_forwards 6
#define right_backwards 9

//The pins for the IR sensors
#define ir_left 4
#define ir_middle 7
#define ir_right 8

//The speed the motors will drive at. Max speed is 255, 0 turns motors off:
#define drive_speed 255

/*
TIPS:
-We are using "analogWrite" instead of "digitalWrite" so that we can control the motor speed
-Make sure your motor driver is plugged into PWM capable pins such as pins 3, 5, 6, and 9
-In order to make the robot do a specific action in each case, copy and paste the four lines of code from the first if statement, and then modify them accordingly. You need to update all four motor driver pins each time you want to change how the robot moves.
-If you leave the inside of an 'if' statement blank, the robot will continue moving the way it was before when it encounters that specific case
-Try to adjust the drive_speed variable so that your robot drives at the right speed. Note that there is a certain point below which the motors will not turn on
-Setting a pin to "drive_speed" makes it go at whatever speed you have specified in the above define statement, and setting it to 0 turns off the motor
-You can manually set a speed (for example, 200) inside an analogWrite statement, or set some variant of drive_speed (such as drive_speed/2)
*/


//The variables that store whether or not each sensor detected the line:
bool line_detected_left = 0;
bool line_detected_middle = 0;
bool line_detected_right = 0;

void setup() {
  //Set the IR sensor pins as inputs
  pinMode(ir_left, INPUT);
  pinMode(ir_middle, INPUT);
  pinMode(ir_right, INPUT);
  
  //Set the motor driver pins as outputs
  pinMode(left_forwards, OUTPUT);
  pinMode(left_backwards, OUTPUT);
  pinMode(right_forwards, OUTPUT);
  pinMode(right_backwards, OUTPUT);

}

void loop() {
  //First, we read the IR sensors and store the values in the line_detected variables
  line_detected_left = digitalRead(ir_left);
  line_detected_middle = digitalRead(ir_middle);
  line_detected_right = digitalRead(ir_right);  

  if(!line_detected_left && line_detected_middle && !line_detected_right) //If just the middle sensor detects the line
  {
    analogWrite(left_forwards, drive_speed);
    analogWrite(left_backwards, 0);
    analogWrite(right_forwards, drive_speed);
    analogWrite(right_backwards, 0);
  }

  else if(line_detected_left && !line_detected_middle && !line_detected_right) //If just the left sensor detects the line
  {
    //Code goes here
  }

  else if(!line_detected_left && !line_detected_middle && line_detected_right) //If just the right sensor detects the line
  {
    //Code goes here
  }

  else if(line_detected_left && line_detected_middle && !line_detected_right) //If the left sensor and the middle sensor detect the line
  {
    //Code goes here
  }

  else if(!line_detected_left && line_detected_middle && line_detected_right) //If the right sensor and the middle sensor detect the line
  {
    //Code goes here
  }

  else if(line_detected_left && line_detected_middle && line_detected_right) //If all three sensors detect the line
  {
    //Code goes here
  }

  else //If none of the sensors detect the line
  {
    //Code goes here
  }
}
