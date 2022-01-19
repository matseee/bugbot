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

void setup() {
  pca9685.setupSingleDevice(Wire, constants::device_address);

  pca9685.setupOutputEnablePin(constants::output_enable_pin);
  pca9685.enableOutputs(constants::output_enable_pin);

  pca9685.setToServoFrequency();

  bugbot = createBugbot();
}

void loop() {
  bugbot->moveForward();
  delay(5000);
}

Bugbot *createBugbot() {
  Leg *left1 = new Leg(new Servo(pca9685, constants::channelUpperLeft1, true),
                       new Servo(pca9685, constants::channelLowerLeft1, true));

  Leg *left2 =
      new Leg(new Servo(pca9685, constants::channelUpperLeft2, true, 40),
              new Servo(pca9685, constants::channelLowerLeft2, true));

  Leg *left3 = new Leg(new Servo(pca9685, constants::channelUpperLeft3, true),
                       new Servo(pca9685, constants::channelLowerLeft3, true));

  Leg *right1 =
      new Leg(new Servo(pca9685, constants::channelUpperRight1, false, -70),
              new Servo(pca9685, constants::channelLowerRight1, false));

  Leg *right2 =
      new Leg(new Servo(pca9685, constants::channelUpperRight2, false),
              new Servo(pca9685, constants::channelLowerRight2, false));

  Leg *right3 =
      new Leg(new Servo(pca9685, constants::channelUpperRight3, false),
              new Servo(pca9685, constants::channelLowerRight3, false, -50));

  return new Bugbot(left1, left2, left3, right1, right2, right3);
}
