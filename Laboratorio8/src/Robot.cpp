#include "../include/Robot.h"
#include "../include/Maze.h"

Robot::Robot() {} // non fa nulla, perchè è una classe astratta
bool Robot::has_won() const { return win; }

int Robot::gen_rnd_value(int max) const {
  srand(time(0)); // usa come seed l'ora corrente
  int value = rand() % max;
  return value;
}