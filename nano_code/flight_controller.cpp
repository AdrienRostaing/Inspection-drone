#include <Arduino.h>
#include "flight_controller.h"
#include "imu.h"



int m1_pwm = 255;
int m2_pwm = 255;
int m3_pwm = 0;
int m4_pwm = 0;

int baseThrottle = 20;  // adjust depending on your motors (0–255)

// ===== Motor pins (TB6612 / DRV8833 control) =====
// Example setup: 4 motors, each has a PWM pin
const int motor1_A = 5;
const int motor1_B = 6;
const int motor2_A = 9;
const int motor2_B = 10;
//const int motor3_A = 23;
//const int motor3_B = 24;
//const int motor4_A = 25;
//const int motor4_B = 26;

// ===== Base throttle =====


byte speed = 255;




// ===== Setup =====
void setupFlightController() {
   // Setup motor pins
   pinMode(motor1_A, OUTPUT);
   pinMode(motor2_A, OUTPUT);
//   pinMode(motor3_A, OUTPUT);
//   pinMode(motor4_A, OUTPUT);
   pinMode(motor1_B, OUTPUT);
   pinMode(motor2_B, OUTPUT);
//   pinMode(motor3_B, OUTPUT);
//   pinMode(motor4_B, OUTPUT);

}

// ===== Helper: Set motor speeds =====
void setMotorSpeeds(int m1_pwm, int m2_pwm) { // add , int m3_pwm, int m4_pwm
    if (m1_pwm >= 0){
      analogWrite(motor1_A, m1_pwm);
      analogWrite(motor1_B, 0);
    } else {
      analogWrite(motor1_A, 0);
      analogWrite(motor1_B, -m1_pwm);
    }
    if (m2_pwm >= 0){
      analogWrite(motor2_A, m2_pwm);
      analogWrite(motor2_B, 0);
    } else {
      analogWrite(motor2_A, 0);
      analogWrite(motor2_B, -m2_pwm);
    }
//    if (m3_pwm >= 0){
//      analogWrite(motor3_A, m3_pwm);
//      analogWrite(motor3_B, 0);
//    } else {
//      analogWrite(motor3_A, 0);
//      analogWrite(motor3_B, -m3_pwm);
//    }
//    if (m4_pwm >= 0){
//      analogWrite(motor4_A, m4_pwm);
//      analogWrite(motor4_B, 0);
//    } else {
//      analogWrite(motor4_A, 0);
//      analogWrite(motor4_B, -m4_pwm);
//    }
   
}


// ===== Main Update Loop =====
void updateFlightController() {

//   if(m1, m2, m3, m4 > baseThrottle || m1, m2, m3, m4 < baseThrottle || m1, m2, m3, m4 == baseThrottle){ //case key up or key down, all throttle up/down --> want stabalisation (flat)
//      if (ax > 0.2) {  // tilt forward
//          m3_pwm += 10*ax; m4_pwm += 10*ax;
//      } else if (ax < -0.2) {  // tilt backward
//          m1_pwm += 10*ax; m2_pwm += 10*ax;
//      }
//  
//      if (ay > 0.2) {  // tilt right
//          m1_pwm += 10*ay; m3_pwm += 10*ay;
//      } else if (ay < -0.2) {  // tilt left
//          m2_pwm += 10*ay; m4_pwm += 10*ay;
//      }     
//   } else if (m1, m2 > baseThrottle && m3, m4 < baseThrottle ){ //case forward, all throttle up --> want stabalisation (forward tilt proportional to motor_inputs m1 m2 etc)
//      if (ax > 0.2*m1) {  // tilt forward
//          m3_pwm += 10*ax; m4_pwm += 10*ax;
//      } else if (ax < 0.2*m1) {  // tilt backward
//          m1_pwm += 10*ax; m2_pwm += 10*ax;
//      }
//      if (ay > 0.2) {  // tilt right
//          m1_pwm += 10*ay; m3_pwm += 10*ay;
//      } else if (ay < -0.2) {  // tilt left
//          m2_pwm += 10*ay; m4_pwm += 10*ay;
//      }
//
//   } else if (m1, m2 < baseThrottle && m3, m4 > baseThrottle ){ //case forward, all throttle up --> want stabalisation (forward tilt proportional to motor_inputs m1 m2 etc)
//      if (ax > -0.2*m3) {  // tilt forward
//          m3_pwm += 10*ax; m4_pwm += 10*ax;
//      } else if (ax < -0.2*m3) {  // tilt backward
//          m1_pwm += 10*ax; m2_pwm += 10*ax;
//      }
//      if (ay > 0.2) {  // tilt right
//          m1_pwm += 10*ay; m3_pwm += 10*ay;
//      } else if (ay < -0.2) {  // tilt left
//          m2_pwm += 10*ay; m4_pwm += 10*ay;
//      }
//
//    } else if (m1, m3 > baseThrottle && m2, m4 < baseThrottle ){ //case forward, all throttle up --> want stabalisation (forward tilt proportional to motor_inputs m1 m2 etc)
//      if (ax > 0.2) {  // tilt forward
//          m3_pwm += 10*ax; m4_pwm += 10*ax;
//      } else if (ax < 0.2) {  // tilt backward
//          m1_pwm += 10*ax; m2_pwm += 10*ax;
//      }
//      if (ay > 0.2*m1) {  // tilt right
//          m1_pwm += 10*ay; m3_pwm += 10*ay;
//      } else if (ay < -0.2*m1) {  // tilt left
//          m2_pwm += 10*ay; m4_pwm += 10*ay;
//      } 
//    } else if (m2, m4 > baseThrottle && m1, m3 < baseThrottle ){ //case forward, all throttle up --> want stabalisation (forward tilt proportional to motor_inputs m1 m2 etc)
//      if (ax > 0.2) {  // tilt forward
//          m3_pwm += 10*ax; m4_pwm += 10*ax;
//      } else if (ax < 0.2) {  // tilt backward
//          m1_pwm += 10*ax; m2_pwm += 10*ax;
//      }
//      if (ay > -0.2*m2) {  // tilt right
//          m1_pwm += 10*ay; m3_pwm += 10*ay;
//      } else if (ay < -0.2*m2) {  // tilt left
//          m2_pwm += 10*ay; m4_pwm += 10*ay;
//      } 
//      }
      
    // ===== Apply speeds =====
//    setMotorSpeeds(m1_pwm, m2_pwm, m3_pwm, m4_pwm);
    
    // Assume: m1 = left motor, m2 = right motor
// ax = forward/back tilt, ay = left/right tilt

    // Assume: m1 = left motor, m2 = right motor
// ax = forward/back tilt, ay = left/right tilt
    
        
//    // Forward / backward stabilization
//    if (ax > 0.2) {         // tilt forward
//        m1_pwm += 10 * ax;
//        m2_pwm += 10 * ax;
//    } else if (ax < -0.2) { // tilt backward
//        m1_pwm += 10 * ax;
//        m2_pwm += 10 * ax;
//    }
//
//    // Left / right stabilization
//    if (ay > 0.2) {         // tilt right
//        m1_pwm += 10 * ay;  // push left motor
//    } else if (ay < -0.2) { // tilt left
//        m2_pwm += 10 * ay;  // push right motor
//    }
   

    setMotorSpeeds(m1_pwm, m2_pwm);
    Serial.print("M1: ");
    Serial.print(m1_pwm);
    Serial.print(" M2: ");
    Serial.print(m2_pwm);
    Serial.print(" Ax: ");
    Serial.print(ax);
    Serial.print(" Ay: ");
    Serial.print(ay);
    Serial.print(" Az: ");
    Serial.println(az);
}
