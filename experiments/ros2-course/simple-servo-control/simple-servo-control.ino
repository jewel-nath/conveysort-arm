// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

#include <Servo.h>

// Register a servo motor
Servo motor;

void setup() {
  // Attach and Initialize each Servo to the Arduino pin where it is connected
  motor.attach(8); 

  // Set a known starting point for the motor
  motor.write(90);

  // Start the Serial communication with ROS
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  if (Serial.available())
  {
    int angle = Serial.readString().toInt();
    motor.write(angle);
  }
  delay(0.1);
}
