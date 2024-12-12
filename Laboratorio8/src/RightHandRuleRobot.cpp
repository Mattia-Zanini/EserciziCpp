#include "../include/RightHandRuleRobot.h"
#include "../include/Maze.h"

RightHandRuleRobot::RightHandRuleRobot() {} // non fa nulla

bool RightHandRuleRobot::is_there_wall_nearby(
    const std::vector<char> &cells) const {
  for (int i = 0; i < cells.size(); i++)
    if (cells[i] == '*')
      return true;

  return false;
}

// muove il robot in posizioni randomiche valide
void RightHandRuleRobot::move(Maze &mz) {
  const std::vector<char> nearby_cells = mz.get_maze_chunck();
  int relative_move_value = 0;

  if (!is_there_wall_nearby(nearby_cells))
    relative_move_value = move_random(mz, nearby_cells);
  else
    relative_move_value = move_right_rule(nearby_cells);

  int status = mz.move_robot(relative_move_value);

  if (status == -1)
    throw InvalidMove();
  else if (status == 1)
    win = true;
}

int RightHandRuleRobot::move_random(Maze &mz,
                                    const std::vector<char> &cells_near_robot) {
  const std::vector<int> relative_vector =
      mz.calc_relative_vector(cells_near_robot);

  int rnd_move_index = gen_rnd_value(relative_vector.size());
  return relative_vector[rnd_move_index];
}

int RightHandRuleRobot::move_right_rule(
    const std::vector<char> &cells_near_robot) {
  // non è necessario calcolare il vettore di posizioni relative in quanto
  // controllo già con l'orientazione la prima casella libera disponibile in
  // senso anti-orario
  const static std::vector<int> relative_move{-10, -9, -8, -1, 1, 8, 9, 10};
  int index = robot_orientation(cells_near_robot);

  // se ci sono problemi col definire l'orientaazione del robot
  if (index == -1)
    throw CantDefineOrientation();

  return relative_move[index];
}

int RightHandRuleRobot::robot_orientation(const std::vector<char> &cells) {
  // controllo in senso anti-orario rispetto alle caselle ricevute seguendo
  // l'ordine standard, ovvero [-10, -9, -8, -1, 1, 8, 9, 10] e questi sono gli
  // indici di questo vettore che contiene le rispettive posizioni relative del
  // robot.
  // Ovvero: [1] = -9; [0], = -10; [3] = -1; e così via
  const static std::vector<int> index_check_cells{1, 0, 3, 5, 6, 7, 4, 2};

  for (int i = 0; i < index_check_cells.size(); i++) {
    int relative_index_to_check = (current_robot_orientation + i + 6) % 8;
    int index_to_check = index_check_cells[relative_index_to_check];

    if (cells[index_to_check] != '*') {
      current_robot_orientation = relative_index_to_check;
      return index_to_check;
    }
  }

  return -1;
}