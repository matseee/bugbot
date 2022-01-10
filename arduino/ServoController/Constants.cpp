// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "Constants.h"

namespace constants
{
  const PCA9685::DeviceAddress device_address = 0x40;
  const PCA9685::Pin output_enable_pin = 2;
  
  const size_t loop_delay = 1000;
  
  const PCA9685::Channel channel0 = 0;
  const PCA9685::Channel channel1 = 1;
  const PCA9685::Channel channel2 = 2;
  const PCA9685::Channel channel4 = 4;
  const PCA9685::Channel channel5 = 5;
  const PCA9685::Channel channel6 = 6;
  
  const PCA9685::DurationMicroseconds servo_pulse_duration_min = 900; // 900 Original
  const PCA9685::DurationMicroseconds servo_pulse_duration_max = 2100; // 2100 Original
  const PCA9685::DurationMicroseconds servo_pulse_duration_increment = 100;
}
