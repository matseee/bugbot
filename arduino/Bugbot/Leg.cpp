#include "Leg.h"

Leg::Leg(Servo *upper, Servo *lower) {
  this->upper = upper;
  this->lower = lower;
}

void Leg::moveForward(bool half) {
  if (half) {
    this->upper->setAngle(0);
  } else {
    this->upper->setAngle(45);
  }
}

void Leg::pushForward() {
  if (this->upper->getAngle() == 45) {
    this->upper->setAngle(0);
  } else if (this->upper->getAngle() == 0) {
    this->upper->setAngle(-45);
  }
}

void Leg::reset() {
  this->upper->setAngle(0);
  this->lower->setAngle(0);
}

void Leg::up() { this->lower->setAngle(-45); }

void Leg::down() { this->lower->setAngle(0); }
