#include "out/output.cpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Startup {
public:
  string filename;
  string code;
  int out;
  Startup(string filename) {
    this->filename = filename;
    this->out = Main();
  }
  int Main() {
    cout << "Starting..." << endl;
    this->code = ReadFile(filename);
    cout << "End" << endl;
    return 0;
  }

private:
  string ReadFile(string filename) {
    string code;
    string row;
    ifstream file(filename);
    while (getline(file, row)) {
      code += row;
      code.push_back('\n');
    }
    code.pop_back(); // for remove the last uneccessary '\n'
    cout << code << endl;
    file.close();
    return code;
  }
  string LibrarysSearch() { return ""; }
};