#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
#include <PCA9685.h>

namespace constants
{
extern const PCA9685::DeviceAddress device_address;
extern const PCA9685::Pin output_enable_pin;

extern const size_t loop_delay;

extern const PCA9685::Channel chLeft1;
extern const PCA9685::Channel chLeft2;
extern const PCA9685::Channel chLeft3;

extern const PCA9685::Channel chRight1;
extern const PCA9685::Channel chRight2;
extern const PCA9685::Channel chRight3;

extern const PCA9685::DurationMicroseconds servo_pulse_duration_min;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_max;
extern const PCA9685::DurationMicroseconds servo_pulse_duration_increment;
}
#endif
