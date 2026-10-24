// Based on the arduinobot code from Antonio Brandi's course "Robotics and ROS 2 - Learn by Doing!
// Manipulators": https://github.com/AntoBrandi/Robotics-and-ROS-2-Learn-by-Doing-Manipulators
// Licensed under the Apache License 2.0 (LICENSE-APACHE). Changed for ConveySort-Arm: the names,
// and in some files the arm's joints and servos.

int x = 0;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  Serial.println(x);
  x++;
  delay(0.1);
}
