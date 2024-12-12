#include "../include/RandomRobot.h"
#include "../include/Maze.h"

RandomRobot::RandomRobot() {} // non fa nulla

// muove il robot in posizioni randomiche valide
void RandomRobot::move(Maze &mz) {
  const std::vector<char> nearby_cells = mz.get_maze_chunck();
  const std::vector<int> relative_vector =
      mz.calc_relative_vector(nearby_cells);

  const int rnd_move_index = gen_rnd_value(relative_vector.size());

  int status = mz.move_robot(relative_vector[rnd_move_index]);

  if (status == -1)
    throw InvalidMove();
  else if (status == 1)
    win = true;
}