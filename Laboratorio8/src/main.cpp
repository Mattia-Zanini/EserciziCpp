#include "../include/Maze.h"
#include "../include/RandomRobot.h"
#include "../include/RightHandRuleRobot.h"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  /*if (argc != 2) {
    std::cout << "manca il file del labirinto\n";
    return -1;
  }
  */

  std::fstream fs = std::fstream();
  // fs.open(argv[1], std::fstream::in);
  fs.open("../maze2.txt", std::fstream::in);
  if (fs.fail()) {
    std::cout << "errore nell'apertura del file\n";
    return -1;
  }

  std::filebuf *buffer = fs.rdbuf();
  Maze mz = Maze(buffer);

  fs.close(); // chiudo il file
  buffer = nullptr;

  std::cout << mz << "\n";
  int count_random = 0;
  int count_right_rule = 0;

  RightHandRuleRobot rhrR = RightHandRuleRobot();
  do {
    rhrR.move(mz);
    count_right_rule++;
    std::cout << mz << "\n";
  } while (!rhrR.has_won());

  mz.reset_maze(); // resetto il labirinto
  std::cout << "Labirinto resettato\n\n";
  std::cout << mz << "\n";

  RandomRobot rr = RandomRobot();
  do {
    rr.move(mz);
    count_random++;
    std::cout << mz << "\n";
  } while (!rr.has_won());

  std::cout << "Il RightHandRuleRobot ha impiegato: " << count_right_rule
            << " mosse per vincere\n";
  std::cout << "Il RandomRobot ha impiegato: " << count_random
            << " mosse per vincere\n";
}