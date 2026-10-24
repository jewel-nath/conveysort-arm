# Experiments

The tests from 2024, written while the sorter in
[`firmware/conveyor-sorter/`](../firmware/conveyor-sorter) was worked out.
They are kept as they were, as a record of how the belt, the sensor and the
arm were worked out, apart from the licence notices and the ESP32 password,
now in `secrets.h`. Each is an Arduino sketch in a folder of its own name
(`ros2-course/` holds three).

| Folder | What it tried |
|---|---|
| [`conveyor-belt-test/`](conveyor-belt-test) | The belt's stepper motor through the TB6600 driver, at 6,400 steps a turn, with serial commands to run, stop and reverse it |
| [`distance-sensor-test/`](distance-sensor-test) | The HC-SR04 ultrasonic sensor, printing the distance every half second |
| [`conveyor-with-distance-sensor/`](conveyor-with-distance-sensor) | The two together: the belt runs while the sensor sees a block 7 to 45 cm away, and stops when it is 7 cm or closer |
| [`arm-servo-test/`](arm-servo-test) | The arm's six servos on the PCA9685 board, from a serial menu: one servo at a time, home, the gripper, a first pick motion (grip, lift, home) and a sweep of every joint |
| [`esp32-phone-control/`](esp32-phone-control) | Driving the arm from a phone: an ESP32 opens its own Wi-Fi access point and serves a page with a slider for each servo, and it records moves and plays them back. Copy `secrets.example.h` to `secrets.h` first |
| [`ros2-course/`](ros2-course) | The serial and servo exercises from Antonio Brandi's ROS 2 course, to flash and pair with the matching nodes in [`conveysort_firmware`](../src/conveysort_firmware), at 115200 baud |

The ESP32 test needs the AsyncTCP, ESPAsyncWebServer and Adafruit PWM Servo
Driver libraries. It started from Ujwal Nandanwar's
[RobotArm](https://github.com/un0038998/RobotArm) sketch, and the course
sketches are under the Apache License 2.0 ([LICENSE-APACHE](../LICENSE-APACHE));
each file's notice is at its top.
