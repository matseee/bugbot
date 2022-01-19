#include "Servo.h"

Servo::Servo(PCA9685 pca9685, PCA9685::Channel channel, bool mirrored) {
  this->pca9685 = pca9685;
  this->channel = channel;
  this->pulseWidthOffset = 0;

  this->angle = 0;
  this->mirrored = mirrored;
  this->setPulseWidth(1500);
}

Servo::Servo(PCA9685 pca9685, PCA9685::Channel channel, bool mirrored,
             int pulseWidthOffset) {
  this->pca9685 = pca9685;
  this->channel = channel;
  this->pulseWidthOffset = pulseWidthOffset;

  this->angle = 0;
  this->mirrored = mirrored;
  this->setPulseWidth(1500);
}

void Servo::setAngle(int angle) {
  this->angle = angle;
  this->setPulseWidth(this->convertAngleToPulseWidth(this->mirrorAngle(angle)));
}

int Servo::getAngle() { return this->angle; }

void Servo::setPulseWidth(int pulseWidth) {
  this->pulseWidth = this->calculateRealPulseWidth(pulseWidth);
  this->pca9685.setChannelServoPulseDuration(this->channel, this->pulseWidth);
}

int Servo::mirrorAngle(int angle) {
  return (this->mirrored == true) ? (angle * -1) : angle;
}

PCA9685::DurationMicroseconds Servo::convertAngleToPulseWidth(int angle) {
  Serial.print("Angle:");
  Serial.println(angle);

  float fAngle = float(abs(angle));

  float fPercentage = fAngle / 90.0f;
  float fDuration = 400.0f * fPercentage;

  Serial.print("Duration:");
  Serial.println(fDuration);

  int iDuration = int(fDuration);

  return (angle > 0) ? (1500 + iDuration) : (1500 - iDuration);
}

PCA9685::DurationMicroseconds Servo::calculateRealPulseWidth(int pulseWidth) {
  return pulseWidth + this->pulseWidthOffset;
}
