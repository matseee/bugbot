#include "Constants.h"

namespace constants
{
  const PCA9685::DeviceAddress device_address = 0x40;
  const PCA9685::Pin output_enable_pin = 2;
  
  const size_t loop_delay = 1000;
  
  const PCA9685::Channel chLeft1 = 0;
  const PCA9685::Channel chLeft2 = 1;
  const PCA9685::Channel chLeft3 = 2;

  const PCA9685::Channel chRight1 = 4;
  const PCA9685::Channel chRight2 = 5;
  const PCA9685::Channel chRight3 = 6;
  
  const PCA9685::DurationMicroseconds servo_pulse_duration_min = 900;
  const PCA9685::DurationMicroseconds servo_pulse_duration_max = 2100;
  const PCA9685::DurationMicroseconds servo_pulse_duration_increment = 100;
}
