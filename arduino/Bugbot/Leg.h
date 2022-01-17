#ifndef LEG_H
#define LEG_H

#include "Servo.h"

class Leg
{
private:
    Servo *upper;
    Servo *lower;

public:
    Leg(Servo *upper, Servo *lower);

    void moveForward();
    void moveBackward();
};

#endif