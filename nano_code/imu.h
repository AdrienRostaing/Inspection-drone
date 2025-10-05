// imu.h
#pragma once

// Rename sensor_t before Adafruit_MPU6050 pulls it in
#define sensor_t adafruit_sensor_t
#include <Adafruit_MPU6050.h>
#undef sensor_t

#include <Wire.h>

// Global IMU instance
extern Adafruit_MPU6050 imu;

// Latest sensor readings
extern float gx, gy, gz;
extern float ax, ay, az;
extern float tempC;

// Initialize IMU
bool imu_init();

// Update readings
void imu_update();
