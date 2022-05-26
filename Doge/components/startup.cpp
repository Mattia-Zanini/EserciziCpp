#include "debug/output.cpp"
#include <iostream>
#include <string>

using namespace std;
class Startup {
public:
  string filename;
  string _return;
  Startup(string filename) {
    this->_return = extension::GoodExtension(filename);
    this->filename = filename;
  }
};