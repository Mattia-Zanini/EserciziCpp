#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <vector>

class Maze {
private:
  const static std::vector<int> relative_position;
  // massimo numero di celle nel labirinto
  constexpr static int MAX_CELLS_NUMBER = 81;
  int current_robot_position;
  int exit_position;
  std::vector<char> maze;

  bool is_maze_valid(); // controlla se il labirinto sia valido

  // imposta le posizioni iniziali del robot e dell'uscita
  void init_positions();

  // ritorna le 8 celle adiacenti ad una specifica casella
  const std::vector<char> get_maze_chunck_from_cell(int) const;

public:
  Maze();                           // labirinto vuoto
  Maze(std::filebuf *);             // importa anche il labirinto
  void import_maze(std::filebuf *); // importa il labirinto da un file
  void reset_maze();                // resetta lo stato del labirinto

  // ritorna la posizione corrente del robot
  const int get_current_robot_position() const;

  // aggiorna la posizione del robot all'interno del labirinto,
  // controllando la validità dei movimenti del robot
  int move_robot(int);

  // ritorna le 8 celle adiacenti al robot
  const std::vector<char> get_maze_chunck() const;
  // ritorna l'intero labirinto
  const std::vector<char> get_maze() const;
  std::vector<int> calc_relative_vector(const std::vector<char> &) const;

  class ErrorAtReadingMaze {};
  class IncorrectMazeFormat {};
  class ExitDoesNotExist {};
  class StartDoesNotExist {};
};

// stampa il labirinto con la posizione corrente del robot
std::ostream &operator<<(std::ostream &os, const Maze &mz);

#endif