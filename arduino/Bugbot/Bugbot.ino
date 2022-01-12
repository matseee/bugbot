/**
  Uses the library PCA9685 (https://github.com/janelia-arduino/PCA9685)
*/

#include <Arduino.h>
#include <PCA9685.h>

#include "Constants.h"
#include "Servo.h"

PCA9685 pca9685;

Servo* servoUpperLeft1;
Servo* servoUpperLeft2;
Servo* servoUpperLeft3;

Servo* servoUpperRight1;
Servo* servoUpperRight2;
Servo* servoUpperRight3;

Servo* servoLowerLeft1;
Servo* servoLowerLeft2;
Servo* servoLowerLeft3;

Servo* servoLowerRight1;
Servo* servoLowerRight2;
Servo* servoLowerRight3;

int pulseWidth = 1500;
int changeValue = 1;

void setup() {
  pca9685.setupSingleDevice(Wire,constants::device_address);

  pca9685.setupOutputEnablePin(constants::output_enable_pin);
  pca9685.enableOutputs(constants::output_enable_pin);

  pca9685.setToServoFrequency();

  servoUpperLeft1 = new Servo(pca9685, constants::channelUpperLeft1);
  servoUpperLeft2 = new Servo(pca9685, constants::channelUpperLeft2, 40);
  servoUpperLeft3 = new Servo(pca9685, constants::channelUpperLeft3);

  servoUpperRight1 = new Servo(pca9685, constants::channelUpperRight1, -70);
  servoUpperRight2 = new Servo(pca9685, constants::channelUpperRight2);
  servoUpperRight3 = new Servo(pca9685, constants::channelUpperRight3);

  servoLowerLeft1 = new Servo(pca9685, constants::channelLowerLeft1);
  servoLowerLeft2 = new Servo(pca9685, constants::channelLowerLeft2);
  servoLowerLeft3 = new Servo(pca9685, constants::channelLowerLeft3);

  servoLowerRight1 = new Servo(pca9685, constants::channelLowerRight1);
  servoLowerRight2 = new Servo(pca9685, constants::channelLowerRight2);
  servoLowerRight3 = new Servo(pca9685, constants::channelLowerRight3);
}

void loop() {
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
