#include "debug/output.cpp"
#include <iostream>
#include <string>

using namespace std;
class Startup {
public:
  string filename;
  Startup(string filename) { this->filename = filename; }
};