#include "out/output.cpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class Startup {
public:
  string filename;
  ifstream *file;
  Startup(string filename) {
    this->filename = filename;
    ifstream filestream(filename);
    this->file = &filestream;
  }
  string ReadFileLine() {
    string riga;
    // legge riga per riga il file
    getline(this->file, riga);
    cout << riga << endl;
    return "";
  }
};