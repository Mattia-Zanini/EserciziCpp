#include "../include/Maze.h"

Maze::Maze() {}
Maze::Maze(std::filebuf *buffer) { import_maze(buffer); }

void Maze::import_maze(std::filebuf *buffer) {
  for (int i = 0; i < MAX_CELLS_NUMBER; i++) {
    char c = buffer->sbumpc();

    if (c = EOF)
      throw Maze::ErrorAtReadingMaze();

    maze.push_back(c);
  }

  if (!check_maze())
    throw Maze::IncorrectMazeFormat();

  current_robot_position = get_robot_current_position();
}

int Maze::get_robot_current_position() {
  int pos = 0;
  // si può ottimizzare, per esempio NON guardando le pareti
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

const std::vector<char> Maze::get_maze_chunck() const {
  // celle vicine, relative alla posizione del robot, 0 è la posizione del robot
  // stesso
  static const std::vector<int> near_cells{-10, -9, -8, -1, 1, 8, 9, 10};
  std::vector<char> robot_near_cells(0);
  for (int i = 0; i < near_cells.size(); i++) {
    int relative_index = current_robot_position + near_cells[i];
    robot_near_cells.push_back(maze[relative_index]);
  }

  return robot_near_cells;
}