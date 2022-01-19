#include "Bugbot.h"
#include "Leg.h"

Bugbot::Bugbot(Leg *left1, Leg *left2, Leg *left3, Leg *right1, Leg *right2,
               Leg *right3) {
  this->left1 = left1;
  this->left2 = left2;
  this->left3 = left3;

  this->right1 = right1;
  this->right2 = right2;
  this->right3 = right3;
}

void Bugbot::moveForward() {
  // Step 1
  this->left2->up();
  this->right1->up();
  this->right3->up();
  delay(500);

  this->left2->moveForward();
  this->right1->moveForward();
  this->right3->moveForward();
  delay(1000);

  this->left2->down();
  this->right1->down();
  this->right3->down();
  delay(500);

  // Step 2
  this->left1->pushForward();
  this->left2->pushForward();
  this->left3->pushForward();
  this->right1->pushForward();
  this->right2->pushForward();
  this->right3->pushForward();
  delay(1000);

  // Step 3
  this->left1->up();
  this->left3->up();
  this->right2->up();
  delay(500);

  this->left1->moveForward();
  this->left3->moveForward();
  this->right2->moveForward();
  delay(1000);

  this->left1->down();
  this->left3->down();
  this->right2->down();
  delay(500);

  // Step 4
  this->left1->pushForward();
  this->left2->pushForward();
  this->left3->pushForward();
  this->right1->pushForward();
  this->right2->pushForward();
  this->right3->pushForward();
  delay(1000);

  // Step 5
  this->left2->up();
  this->right1->up();
  this->right3->up();
  delay(500);

  this->left2->moveForward(true);
  this->right1->moveForward(true);
  this->right3->moveForward(true);
  delay(1000);

  this->left2->down();
  this->right1->down();
  this->right3->down();
  delay(500);

  // Reset everything
  this->left1->reset();
  this->left2->reset();
  this->left3->reset();
  this->right1->reset();
  this->right2->reset();
  this->right3->reset();
}

void Bugbot::moveBackward() {}

void Bugbot::turnLeft() {}

void Bugbot::turnRight() {}
