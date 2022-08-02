//Code for testing the ultrasonic sensor from the robot kit for the STEM Institute summer 2022 engineering class
//Written by Dylan Kirdahy

#include "SR04.h"
#define TRIG_PIN 10
#define ECHO_PIN 11

SR04 ultrasonic = SR04(ECHO_PIN,TRIG_PIN);

long ultrasonic_distance;

//The pins for the motor driver
#define left_forwards 5
#define left_backwards 3
#define right_forwards 6
#define right_backwards 9


void setup(){
  //Set the pins as outputs
  pinMode(left_forwards, OUTPUT);
  pinMode(left_backwards, OUTPUT);
  pinMode(right_forwards, OUTPUT);
  pinMode(right_backwards, OUTPUT);

  //Set the pinmode for the ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  ultrasonic_distance = ultrasonic.Distance();

  if(ultrasonic_distance < 10){
    digitalWrite(left_forwards, LOW);
	digitalWrite(left_backwards, HIGH);
	digitalWrite(right_forwards, LOW);
	digitalWrite(right_backwards, HIGH);
	delay(100);
	digitalWrite(left_backwards, LOW);
	digitalWrite(left_forwards, HIGH);
	delay(100);
	}
  else{
    digitalWrite(left_forwards, HIGH);
	digitalWrite(left_backwards, LOW);
	digitalWrite(right_forwards, HIGH);
	digitalWrite(right_backwards, LOW);
  }
}
