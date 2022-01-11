#include "Servo.h"

Servo::Servo(PCA9685 pca9685, PCA9685::Channel channel) {
    this->pca9685 = pca9685;
    this->channel = channel;
    this->pulseWidthOffset = 0;
    
    this->setPulseWidth(1500);
}

Servo::Servo(PCA9685 pca9685, PCA9685::Channel channel, int pulseWidthOffset) {
    this->pca9685 = pca9685;
    this->channel = channel;
    this->pulseWidthOffset = pulseWidthOffset;
    
    this->setPulseWidth(1500);
}

void Servo::setPulseWidth(int pulseWidth) {
    this->pulseWidth = this->calculateRealPulseWidth(pulseWidth);
    this->pca9685.setChannelServoPulseDuration(this->channel, this->pulseWidth);
}

PCA9685::DurationMicroseconds Servo::calculateRealPulseWidth(int pulseWidth) {
    return pulseWidth + this->pulseWidthOffset;
}
