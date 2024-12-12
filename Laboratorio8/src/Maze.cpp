#include "../include/Maze.h"
#include "../include/MazeGraph.h"

#include <fstream>

const std::vector<int> Maze::relative_position({-10, -9, -8, -1, 1, 8, 9, 10});
Maze::Maze() {
  current_robot_position = -1;
  exit_position = -1;
}
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

  init_positions();

  // controllo che il labirinto sia valido
  if (!is_maze_valid())
    throw Maze::IncorrectMazeFormat();
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

// celle vicine relative alla posizione del robot
// 0 è la posizione del robot stesso.
// Per i requisiti che il labirinto deve rispettare per il RighHandRuleRobot,
// non dà mai errore di out_of_range
const std::vector<char> Maze::get_maze_chunck() const {
  return get_maze_chunck_from_cell(-1);
}

// -1 è il valore di default, ovvero ritorna le eventuali 8 caselle adiacenti al
// robot, mentre se è un valore diverso da -1 svolge il suo normale compito
const std::vector<char> Maze::get_maze_chunck_from_cell(int pos = -1) const {
  std::vector<char> robot_near_cells(8);

  if (pos == -1)
    pos = current_robot_position;

  // prima di tutto scrivo tutte le celle vicine al robot
  for (int i = 0; i < relative_position.size(); i++) {
    int relative_index = pos + relative_position[i];
    robot_near_cells[i] = maze[relative_index];
  }

  // lato sinistro
  if (pos % 9 == 0) {
    robot_near_cells[0] = 0; //-10
    robot_near_cells[3] = 0; //-1
    robot_near_cells[5] = 0; // 8
  }
  // lato destro
  if ((pos + 1) % 9 == 0) {
    robot_near_cells[2] = 0; //-8
    robot_near_cells[4] = 0; // 1
    robot_near_cells[7] = 0; // 10
  }
  // lato alto
  if (pos < 9) {
    robot_near_cells[0] = 0; //-10
    robot_near_cells[1] = 0; // -9
    robot_near_cells[2] = 0; // -8
  }
  // lato basso
  if (pos > 71 && pos < 81) {
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

std::vector<int>
Maze::calc_relative_vector(const std::vector<char> &relative_pos) const {
  // contine solo le posizioni relative valide, ovvero quelle che il
  // robot può fare tranquillamente
  std::vector<int> relative_vector(0);

  for (int i = 0; i < relative_pos.size(); i++)
    if (relative_pos[i] != '\0' && relative_pos[i] != '*')
      relative_vector.push_back(relative_position[i]);

  return relative_vector;
}

void Maze::reset_maze() { init_positions(); }
const std::vector<char> Maze::get_maze() const { return maze; }
const int Maze::get_current_robot_position() const {
  return current_robot_position;
}

// da implementare i vari layer di controlli
bool Maze::is_maze_valid() {
  MazeGraph mg = MazeGraph();

  // inserisco all'interno del grafo SOLO le caselle su cui il robot può
  // muoversi
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    if (maze[i] == '*')
      continue;

    const std::vector<char> chunck = get_maze_chunck_from_cell(i);
    std::vector<int> rel_vector = calc_relative_vector(chunck);

    mg.insert_vertex(i); // inserisco la casella corrente come vertice

    // inserisco gli archi
    for (int j = 0; j < rel_vector.size(); j++) {
      int relative_index = i + rel_vector[j];
      mg.insert_vertex(relative_index);
      mg.insert_edge(i, relative_index);
    }
  }

  return mg.BFS(current_robot_position, exit_position);
}

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