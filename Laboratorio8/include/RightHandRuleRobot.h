#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H

#include "Robot.h"

class RightHandRuleRobot : Robot {
private:
public:
  RightHandRuleRobot();
  void move(const Maze &);
  ~RightHandRuleRobot();
};

#endif
