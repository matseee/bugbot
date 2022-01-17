#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <PCA9685.h>

class Servo
{
protected:
    PCA9685 pca9685;
    PCA9685::Channel channel;

    PCA9685::DurationMicroseconds pulseWidth;
    int pulseWidthOffset;

    PCA9685::DurationMicroseconds calculateRealPulseWidth(int pulseWidth);

public:
    Servo(PCA9685 pca9685, PCA9685::Channel channel);
    Servo(PCA9685 pca9685, PCA9685::Channel channel, int pulseWidthOffset);

    void setPulseWidth(int pulseWidth);
};

#endif
