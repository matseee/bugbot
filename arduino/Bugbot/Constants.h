#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <Arduino.h>
#include <PCA9685.h>

namespace constants {
extern const PCA9685::DeviceAddress device_address;
extern const PCA9685::Pin output_enable_pin;

extern const PCA9685::Channel channelUpperLeft1;
extern const PCA9685::Channel channelUpperLeft2;
extern const PCA9685::Channel channelUpperLeft3;

extern const PCA9685::Channel channelUpperRight1;
extern const PCA9685::Channel channelUpperRight2;
extern const PCA9685::Channel channelUpperRight3;

extern const PCA9685::Channel channelLowerLeft1;
extern const PCA9685::Channel channelLowerLeft2;
extern const PCA9685::Channel channelLowerLeft3;

extern const PCA9685::Channel channelLowerRight1;
extern const PCA9685::Channel channelLowerRight2;
extern const PCA9685::Channel channelLowerRight3;
} // namespace constants
#endif
