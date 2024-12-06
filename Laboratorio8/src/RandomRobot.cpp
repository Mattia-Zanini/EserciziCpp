#include "../include/RandomRobot.h"

RandomRobot::RandomRobot() {}

void RandomRobot::move(Maze &mz) {
  static const std::vector<int> near_cells{-10, -9, -8, -1, 1, 8, 9, 10};
  // ottiene le 8 caselle adiecenti al robot, utilizza queste celle per vedere
  // se ci sono dei muri nelle vicinanze
  const std::vector<char> cells = mz.get_maze_chunck();

  int pos = 0;
  for (int i = 0; i < cells.size(); i++) {
    pos = gen_random_value(); // genera un numero randomico

    // controlla che la casella scelta a caso non sia un muro, nel caso si passa
    // all'iterazione sucessiva e si controlla la nuova cella
    if (cells[pos] != '*') {
      mz.update_robot_position(near_cells[pos]);
      return;
    }
  }

  // per il momento ho questo errore però poi magari faccio il controllo sul
  // labirinto.
  // se tutte le 8 caselle vicine sono dei muri, allora il robot è rinchiuso
  throw ErrorRobotIsTrapped();
}