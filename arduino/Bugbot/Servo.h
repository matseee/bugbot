#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <PCA9685.h>

class Servo {
protected:
  PCA9685 pca9685;
  PCA9685::Channel channel;

  int angle;
  bool mirrored;

  PCA9685::DurationMicroseconds pulseWidth;
  PCA9685::DurationMicroseconds pulseWidthOffset;

  int mirrorAngle(int angle);

  PCA9685::DurationMicroseconds convertAngleToPulseWidth(int angle);
  PCA9685::DurationMicroseconds calculateRealPulseWidth(int pulseWidth);

public:
  Servo(PCA9685 pca9685, PCA9685::Channel channel, bool mirrored);
  Servo(PCA9685 pca9685, PCA9685::Channel channel, bool mirrored,
        int pulseWidthOffset);

  void setAngle(int angle);
  int getAngle();

  void setPulseWidth(int pulseWidth);
};

#endif
