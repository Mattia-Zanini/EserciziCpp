#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include "../include/RightHandRuleRobot.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "manca il file del labirinto\n";
    return -1;
  }

  std::fstream fs;
  fs.open(argv[1], std::fstream::in);
  if (fs.is_open()) {
    std::cout << "errore nell'apertura del file\n";
    return -1;
  }

  std::filebuf *buffer = fs.rdbuf();

  char c = buffer->sbumpc();
  while (c != EOF) {
    c = buffer->sbumpc();
  }

  fs.close();
}