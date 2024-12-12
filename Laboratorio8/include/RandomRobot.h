#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Maze.h"
#include "Robot.h"

class RandomRobot : public Robot {
public:
  RandomRobot();
  void move(Maze &) override;
};

#endif