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

  init_positions();
}

int Maze::move_robot(int relative_move) {
  std::vector<int> relative_position_accepted{-10, -9, -8, -1, 1, 8, 9, 10};

  // metto a 0 le posizioni relative che non mi servono
  // lato sinistro
  if (current_robot_position % 9 == 0) {
    relative_position_accepted[0] = 0; //-10
    relative_position_accepted[3] = 0; //-1
    relative_position_accepted[5] = 0; // 8
  }
  // lato destro
  if ((current_robot_position + 1) % 9 == 0) {
    relative_position_accepted[2] = 0; //-8
    relative_position_accepted[4] = 0; // 1
    relative_position_accepted[7] = 0; // 10
  }
  // lato alto
  if (current_robot_position < 9) {
    relative_position_accepted[0] = 0; //-10
    relative_position_accepted[1] = 0; // -9
    relative_position_accepted[2] = 0; // -8
  }
  // lato basso
  if (current_robot_position > 71 && current_robot_position < 81) {
    relative_position_accepted[5] = 0; // 8
    relative_position_accepted[6] = 0; // 9
    relative_position_accepted[7] = 0; // 10
  }

  for (int i = 0; i < relative_position_accepted.size(); i++) {
    int relative_index = current_robot_position + relative_move;

    // controllo se la mossa è accettabile, guardando se è nella lista delle
    // mosse consentite e che non vada sulla casella dove c'è un muro
    if (relative_move == relative_position_accepted[i] &&
        maze[relative_index] != '*') {
      // aggiorno la posizione del robot all'interno del labirinto
      current_robot_position += relative_move;

      // controllo che il robot sia arrivato all'uscita
      if (current_robot_position == exit_position)
        return 1;

      return 0;
    }
  }

  return -1; // mossa non valida
}

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

void Maze::init_positions() {
  // ottengo la posizione iniziale del robot
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    if (maze[i] == 'S' || maze[i] == 's') {
      maze[i] = 'S';
      current_robot_position = i;
      break;
    }
  }

  // ottengo la posizione iniziale dell'uscita
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    if (maze[i] == 'E' || maze[i] == 'e') {
      maze[i] = 'E';
      exit_position = i;
      break;
    }
  }
}

void Maze::reset_maze() { init_positions(); }
const std::vector<char> Maze::get_maze() const { return maze; }
const int Maze::get_current_robot_position() const {
  return current_robot_position;
}

// da implementare i vari layer di controlli
bool Maze::is_maze_valid() { return true; }

std::ostream &operator<<(std::ostream &os, const Maze &mz) {
  const std::vector<char> labirinth = mz.get_maze();
  int robot_pos = mz.get_current_robot_position();

  os << "------------------\n";
  for (int i = 0; i < labirinth.size(); i++) {
    if (i != robot_pos)
      os << labirinth[i];
    else
      os << 'o';

    // se l'iterazione successiva è una cella multipla di 9 inserisco un
    // carattere new line
    if ((i + 1) % 9 == 0)
      os << "\n";
  }
  os << "------------------\n";

  return os;
}