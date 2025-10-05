#include <Arduino.h>
#include "flight_controller.h"
#include "imu.h"





int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;

int baseThrottle = 120;  // adjust depending on your motors (0–255)

// ===== Motor pins (TB6612 / DRV8833 control) =====
// Example setup: 4 motors, each has a PWM pin
//const int motor1Pin = 25;
//const int motor2Pin = 26;
//const int motor3Pin = 27;
//const int motor4Pin = 14;

// ===== Base throttle =====


// ===== Setup =====
//void setupFlightController() {
//    // Setup motor pins
//    pinMode(motor1Pin, OUTPUT);
//    pinMode(motor2Pin, OUTPUT);
//    pinMode(motor3Pin, OUTPUT);
//    pinMode(motor4Pin, OUTPUT);
//
//}

// ===== Helper: Set motor speeds =====
//void setMotorSpeeds(int m1, int m2, int m3, int m4) {


//    analogWrite(motor1Pin, m1);
//    analogWrite(motor2Pin, m2);
//    analogWrite(motor3Pin, m3);
//    analogWrite(motor4Pin, m4);
//}


// ===== Main Update Loop =====
void updateFlightController() {


    // ===== Simple stabilization using IMU =====
    // Example: if the drone tilts forward (positive ax), boost rear motors
//    if (ax > 0.2 && !move_forward) {  // tilt forward
//        m3 = 10*ax; m4 = 10*ax;
//    } else if (ax < -0.2 && !move_backward) {  // tilt backward
//        m1 = 10*ax; m2 = 10*ax;
//    }
//
//    if (ay > 0.2 && !move_right) {  // tilt right
//        m1 = 10*ay; m3 = 10*ay;
//    } else if (ay < -0.2 && !move_left) {  // tilt left
//        m2 = 10*ay; m4 = 10*ay;
//    }

    // ===== Apply speeds =====
    //setMotorSpeeds(m1, m2, m3, m4);

    // Debug output

    Serial.print(m1); Serial.print(", ");
    Serial.print(m2); Serial.print(", ");
    Serial.print(m3); Serial.print(", ");
    Serial.println(m4); 
}
