#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"
#include <ctime>

class Robot {
protected:
  Robot();
  int gen_rnd_value(int) const;
  std::vector<int> calc_relative_vector(const std::vector<char> &) const;
  bool win = false;

public:
  void virtual move(Maze &) = 0;
  bool has_won() const;

  Robot(const Robot &) = delete;
  Robot &operator=(const Robot &) = delete;

  class InvalidMove {};
};

#endif