#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include "../include/RightHandRuleRobot.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc != 1) {
    std::cout << "manca il file del labirinto\n";
    return -1;
  }

  std::fstream fs = std::fstream();
  // fs.open(argv[1], std::fstream::in);
  fs.open("../maze.txt", std::fstream::in);
  if (fs.fail()) {
    std::cout << "errore nell'apertura del file\n";
    return -1;
  }

  std::filebuf *buffer = fs.rdbuf();
  Maze mz = Maze(buffer);

  fs.close();
  buffer = nullptr;

  std::cout << mz;
  const std::vector<char> test = mz.get_maze_chunck();
}