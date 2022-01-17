/**
  *  Uses the library PCA9685 (https://github.com/janelia-arduino/PCA9685)
 **/

#include <Arduino.h>
#include <PCA9685.h>

#include "Bugbot.h"
#include "Constants.h"
#include "Leg.h"
#include "Servo.h"

PCA9685 pca9685;
Bugbot *bugbot;

int pulseWidth = 1500;
int changeValue = 1;

void setup()
{
    pca9685.setupSingleDevice(Wire, constants::device_address);

    pca9685.setupOutputEnablePin(constants::output_enable_pin);
    pca9685.enableOutputs(constants::output_enable_pin);

    pca9685.setToServoFrequency();

    bugbot = createBugbot();
}

void loop()
{
    // servoLowerLeft1->setPulseWidth(pulseWidth);
    // servoLowerLeft2->setPulseWidth(pulseWidth);
    // servoLowerLeft3->setPulseWidth(pulseWidth);
    // servoLowerRight1->setPulseWidth(pulseWidth);
    // servoLowerRight2->setPulseWidth(pulseWidth);
    // servoLowerRight3->setPulseWidth(pulseWidth);
    // delay(10);
    //
    // pulseWidth += changeValue;
    //
    // if (pulseWidth > 1840) {
    //   changeValue = -1;
    // } else if (pulseWidth < 1160) {
    //   changeValue = 1;
    // }
}

Bugbot createBugbot()
{
    Leg *left1 = new Leg(
        new Servo(pca9685, constants::channelUpperLeft1),
        new Servo(pca9685, constants::channelLowerLeft1));

    Leg *left2 = new Leg(
        new Servo(pca9685, constants::channelUpperLeft2, 40),
        new Servo(pca9685, constants::channelLowerLeft2));

    Leg *left3 = new Leg(
        new Servo(pca9685, constants::channelUpperLeft3),
        new Servo(pca9685, constants::channelLowerLeft3));

    Leg *right1 = new Leg(
        new Servo(pca9685, constants::channelUpperRight1, -70),
        new Servo(pca9685, constants::channelLowerRight1));

    Leg *right2 = new Leg(
        new Servo(pca9685, constants::channelUpperRight2),
        new Servo(pca9685, constants::channelLowerRight2));

    Leg *right3 = new Leg(
        new Servo(pca9685, constants::channelUpperRight3),
        new Servo(pca9685, constants::channelLowerRight3));

    return new Bugbot(left1, left2, left3, right1, right2, right3);
}
