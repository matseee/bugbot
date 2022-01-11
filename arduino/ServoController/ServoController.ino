#include <Arduino.h>
#include <PCA9685.h>

#include "Constants.h"


PCA9685 pca9685;

PCA9685::DurationMicroseconds servo_pulse_durationLeft;
PCA9685::DurationMicroseconds servo_pulse_durationRight;

void setup() {
  pca9685.setupSingleDevice(Wire,constants::device_address);

  pca9685.setupOutputEnablePin(constants::output_enable_pin);
  pca9685.enableOutputs(constants::output_enable_pin);

  pca9685.setToServoFrequency();

  servo_pulse_durationLeft = constants::servo_pulse_duration_min;
  servo_pulse_durationRight = constants::servo_pulse_duration_min;
}

void loop() {
  setChannelDuration(constants::chLeft1, servo_pulse_durationLeft);
  setChannelDuration(constants::chRight1, servo_pulse_durationRight);
  delay(constants::loop_delay);
  
  setChannelDuration(constants::chLeft2, servo_pulse_durationLeft);
  setChannelDuration(constants::chRight2, servo_pulse_durationRight);
  delay(constants::loop_delay);
  
  setChannelDuration(constants::chLeft3, servo_pulse_durationLeft);
  setChannelDuration(constants::chRight3, servo_pulse_durationRight);
  delay(constants::loop_delay);
  
  servo_pulse_durationLeft = switchPulseDuration(servo_pulse_durationLeft, false);
  servo_pulse_durationRight = switchPulseDuration(servo_pulse_durationRight, true);
  delay(constants::loop_delay);
}

void setChannelDuration(PCA9685::Channel channel, PCA9685::DurationMicroseconds duration) {
  pca9685.setChannelServoPulseDuration(channel, duration);
}

PCA9685::DurationMicroseconds switchPulseDuration(PCA9685::DurationMicroseconds previousDuration, boolean right) {
  if (right) {
    if (previousDuration == 1500) {
      return 2100;
    } else if(previousDuration == 2100) {
      return 900;
    } else {
      return 1500;
    }    
  } else {
    if (previousDuration == 1500) {
      return 900;
    } else if(previousDuration == 2100) {
      return 1500;
    } else {
      return 2100;
    }    
  }
}
