#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"
#include <random>

class Robot {
protected:
  std::random_device dev;

  int gen_random_value();
  bool is_wall(const char);

public:
  Robot();
  virtual void move(Maze &) = 0;
  bool have_finished();

  class ErrorRobotIsTrapped {};
};

#endif