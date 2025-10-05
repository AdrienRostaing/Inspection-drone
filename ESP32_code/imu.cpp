#include "imu.h"

// Apply same rename for Adafruit_Sensor.h
#define sensor_t adafruit_sensor_t
#include <Adafruit_Sensor.h>
#undef sensor_t

Adafruit_MPU6050 imu;


// IMU values
float gx = 0, gy = 0, gz = 0;
float ax = 0, ay = 0, az = 0;
float tempC = 0;

bool imu_init() {
    // Force I²C on GPIO13 (SDA), GPIO14 (SCL)
    Wire.begin(14, 13);

    if (!imu.begin()) {
        Serial.println("Failed to find MPU6050");
        return false;
    }
    imu.setAccelerometerRange(MPU6050_RANGE_8_G);
    imu.setGyroRange(MPU6050_RANGE_500_DEG);
    imu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    return true;
}

void imu_update() {
    sensors_event_t a, g, temp;
    imu.getEvent(&a, &g, &temp);

    ax = a.acceleration.x;
    ay = a.acceleration.y;
    az = a.acceleration.z;

    gx = g.gyro.x;
    gy = g.gyro.y;
    gz = g.gyro.z;

    tempC = temp.temperature;
}
