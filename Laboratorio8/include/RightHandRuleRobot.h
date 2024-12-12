#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H

#include "Maze.h"
#include "Robot.h"

class RightHandRuleRobot : public Robot {
private:
  // 0 up, 1 left-up, 2 left, 3 left-down
  // 4 down 5 right-down, 6 right 7 right-up
  int current_robot_orientation = 0;

  // ritorna true se c'è una casella con un muro vicino
  bool is_there_wall_nearby(const std::vector<char> &) const;
  int move_random(Maze &, const std::vector<char> &);
  int move_right_rule(const std::vector<char> &);

public:
  RightHandRuleRobot();
  void move(Maze &) override;
  int robot_orientation(const std::vector<char> &);

  class CantDefineOrientation {};
};

#endif