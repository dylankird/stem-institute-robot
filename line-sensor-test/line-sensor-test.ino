//The pins for the IR sensors
#define ir_left 4
#define ir_middle 7
#define ir_right 8


//Make sure you open the serial monitor under "Tools" To make sure your sensors are connected properly and working!

void setup() {
  //Set the IR sensor pins as inputs
  pinMode(ir_left, INPUT);
  pinMode(ir_middle, INPUT);
  pinMode(ir_right, INPUT);

  Serial.begin(9600); //Start serial communication
}

void loop() {
  //Print the status of the sensors
  Serial.print("Left: ");
  Serial.print(digitalRead(ir_left));
  Serial.print(" Middle: ");
  Serial.print(digitalRead(ir_middle));
  Serial.print(" Right: ");
  Serial.println(digitalRead(ir_right));  
  delay(100);
}
