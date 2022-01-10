#include <Arduino.h>
#include <PCA9685.h>

#include "Constants.h"


PCA9685 pca9685;

PCA9685::DurationMicroseconds servo_pulse_duration;

void setup() {
  pca9685.setupSingleDevice(Wire,constants::device_address);

  pca9685.setupOutputEnablePin(constants::output_enable_pin);
  pca9685.enableOutputs(constants::output_enable_pin);

  pca9685.setToServoFrequency();

  servo_pulse_duration = constants::servo_pulse_duration_min;
}

void loop() {
  if (servo_pulse_duration > constants::servo_pulse_duration_max)
  {
    servo_pulse_duration = constants::servo_pulse_duration_min;
  }

  pca9685.setChannelServoPulseDuration(constants::channel0,servo_pulse_duration);
//  pca9685.setChannelServoPulseDuration(constants::channel1,servo_pulse_duration);
//  pca9685.setChannelServoPulseDuration(constants::channel2,servo_pulse_duration);
//  
//  pca9685.setChannelServoPulseDuration(constants::channel4,servo_pulse_duration);
//  pca9685.setChannelServoPulseDuration(constants::channel5,servo_pulse_duration);
//  pca9685.setChannelServoPulseDuration(constants::channel6,servo_pulse_duration);
  
  Serial.println(servo_pulse_duration);
  
  servo_pulse_duration += constants::servo_pulse_duration_increment;
  delay(constants::loop_delay);
}
