#include "../include/Robot.h"
#include "../include/Maze.h"

bool Robot::has_won() const { return win; }

int Robot::gen_rnd_value(int max) const {
  srand(time(0));
  int value = rand() % max;
  return value;
}

std::vector<int>
Robot::calc_relative_vector(const std::vector<char> &relative_pos) const {
  const static std::vector<int> relative_position{-10, -9, -8, -1, 1, 8, 9, 10};

  // contine solo le posizioni relative valide, ovvero quelle che il
  // robot può fare tranquillamente
  std::vector<int> relative_vector(0);

  for (int i = 0; i < relative_pos.size(); i++)
    if (relative_pos[i] != '\0' && relative_pos[i] != '*')
      relative_vector.push_back(relative_position[i]);

  return relative_vector;
}