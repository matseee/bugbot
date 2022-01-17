#ifndef BUGBOT_H
#define BUGBOT_H

#include "Leg.h"

class Bugbot
{
protected:
    Leg *left1;
    Leg *left2;
    Leg *left3;

    Leg *right1;
    Leg *right2;
    Leg *right3;

public:
    Bugbot(Leg *left1, Leg *left2, Leg *left3, Leg *right1, Leg *right2, Leg *right 3);

    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
}

#endif