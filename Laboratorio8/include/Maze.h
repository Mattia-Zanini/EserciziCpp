#ifndef MAZE_H
#define MAZE_H

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

class Maze {
private:
  // massimo numero di celle nel labirinto
  constexpr static int MAX_CELLS_NUMBER = 81;
  std::vector<char> maze;
  int current_robot_position = -1;

  bool check_maze(); // controlla se il contenuto del file è un labirinto
  int get_robot_current_position();

public:
  Maze();                           // labirinto vuoto
  Maze(std::filebuf *);             // importa anche il labirinto
  void import_maze(std::filebuf *); // importa il labirinto da un file
  void update_robot_position(int);
  // ritorna le 8 celle adiacenti al robot
  const std::vector<char> get_maze_chunck() const;

  class ErrorAtReadingMaze {};
  class IncorrectMazeFormat {};
  class IncorrectRobotPlacement {};
};

// stampa il labirinto con la posizione corrente del robot
std::ostream &operator<<(std::ostream &os, const Maze &mz);

#endif
