#include "../include/Robot.h"

Robot::Robot() {}

// per decidere che movimento compiere, genero un numero da 1 a 8, che deciderà
// quale delle 8 celle adiacenti andare
int Robot::gen_random_value() {
  std::mt19937 rng(dev());

  // range della distribuzione [1, 8]
  std::uniform_int_distribution<std::mt19937::result_type> dist8(1, 8);
  return dist8(rng);
}

bool Robot::is_wall(const char cell) {
  if (cell == '*')
    return true;
  return false;
}