#include "../include/Maze.h"

#include <fstream>

Maze::Maze() {}
Maze::Maze(std::filebuf *buffer) { import_maze(buffer); }

void Maze::import_maze(std::filebuf *buffer) {
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    char c = buffer->sbumpc();

    // se finisce di leggere il file prima di completare la lettura di un
    // labirinto completo
    if (c == EOF)
      throw Maze::ErrorAtReadingMaze();

    // salto i caratteri di new line
    if (c == '\n') {
      i--;
      continue;
    }

    maze.push_back(c);
  }

  // controllo che il labirinto sia valido
  if (!is_maze_valid())
    throw Maze::IncorrectMazeFormat();

  // ottengo la posizione corrente del robot
  current_robot_position = get_robot_current_position();
}

const int Maze::get_robot_current_position() {
  int pos = 0;
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    if (maze[i] == 'S') {
      pos = i;
      break;
    }
  }

  // lo faccio diventare maiuscolo se non lo è (non necessario)
  if (maze[pos] == 's')
    maze[pos] = 'S';

  return pos;
}

int move_robot(int relative_move) { return 0; }

// celle vicine, relative alla posizione del robot, 0 è la posizione del robot
// stesso.
// Per i requisiti che il labirinto deve rispettare per il RighHandRuleRobot,
// non dà mai errore di out_of_range
const std::vector<char> Maze::get_maze_chunck() const {
  std::vector<int> relative_position{-10, -9, -8, -1, 1, 8, 9, 10};
  std::vector<char> robot_near_cells(8);

  // prima di tutto scrivo tutte le celle vicine al robot
  for (int i = 0; i < relative_position.size(); i++) {
    int relative_index = current_robot_position + relative_position[i];
    robot_near_cells[i] = maze[relative_index];
  }

  // lato sinistro
  if (current_robot_position % 9 == 0) {
    robot_near_cells[0] = 0; //-10
    robot_near_cells[3] = 0; //-1
    robot_near_cells[5] = 0; // 8
  }
  // lato destro
  if ((current_robot_position + 1) % 9 == 0) {
    robot_near_cells[2] = 0; //-8
    robot_near_cells[4] = 0; // 1
    robot_near_cells[7] = 0; // 10
  }
  // lato alto
  if (current_robot_position < 9) {
    robot_near_cells[0] = 0; //-10
    robot_near_cells[1] = 0; // -9
    robot_near_cells[2] = 0; // -8
  }
  // lato basso
  if (current_robot_position > 71 && current_robot_position < 81) {
    robot_near_cells[5] = 0; // 8
    robot_near_cells[6] = 0; // 9
    robot_near_cells[7] = 0; // 10
  }

  return robot_near_cells;
}
const std::vector<char> Maze::get_maze() const { return maze; }

// da implementare i vari layer di controlli
bool Maze::is_maze_valid() { return true; }

std::ostream &operator<<(std::ostream &os, const Maze &mz) {
  const std::vector<char> labirinth = mz.get_maze();

  os << "------------------\n";
  for (int i = 0; i < labirinth.size(); i++) {
    os << labirinth[i];

    // se l'iterazione successiva è una cella multipla di 9 inserisco un
    // carattere new line
    if ((i + 1) % 9 == 0)
      os << "\n";
  }
  os << "------------------\n";

  return os;
}