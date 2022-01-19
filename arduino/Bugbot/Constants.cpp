#include "Constants.h"

namespace constants {
const PCA9685::DeviceAddress device_address = 0x40;
const PCA9685::Pin output_enable_pin = 2;

const PCA9685::Channel channelUpperLeft1 = 6;
const PCA9685::Channel channelUpperLeft2 = 5;
const PCA9685::Channel channelUpperLeft3 = 4;

const PCA9685::Channel channelUpperRight1 = 2;
const PCA9685::Channel channelUpperRight2 = 1;
const PCA9685::Channel channelUpperRight3 = 0;

const PCA9685::Channel channelLowerLeft1 = 8;
const PCA9685::Channel channelLowerLeft2 = 9;
const PCA9685::Channel channelLowerLeft3 = 10;

const PCA9685::Channel channelLowerRight1 = 12;
const PCA9685::Channel channelLowerRight2 = 13;
const PCA9685::Channel channelLowerRight3 = 14;
} // namespace constants
