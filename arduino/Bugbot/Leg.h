#ifndef LEG_H
#define LEG_H

#include "Servo.h"

class Leg {
protected:
  Servo *upper;
  Servo *lower;

public:
  Leg(Servo *upper, Servo *lower);

  void moveForward(bool half = false);
  void pushForward();

  void reset();

  void up();
  void down();
};

#endif
