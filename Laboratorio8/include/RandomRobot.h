#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Robot.h"

class RandomRobot : Robot {
public:
  RandomRobot();
  void move(Maze &);
};

#endif