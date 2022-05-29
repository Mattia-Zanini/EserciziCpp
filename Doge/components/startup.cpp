#include "out/output.cpp"
#include "trlibr.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Startup {
public:
  string filename;
  int out;
  Startup(string filename) {
    this->filename = filename;
    this->out = Main();
  }
  int Main() {
    cout << "Starting..." << endl;
    // count the number of rows the file contains
    int rows = CountRows();
    string code[rows];
    // read every row from the file and write it in the array
    ReadFile(code);
    vector<string> tCode;
    LibrariesTr lt;
    cout << "End" << endl;
    return 0;
  }

private:
  int CountRows() {
    int nRows = 0;
    ifstream inputFile(filename);
    string row;
    while (getline(inputFile, row)) {
      if (!row.empty())
        nRows++;
    }
    cout << "The file have: " << nRows << " rows" << endl;
    inputFile.close();
    return nRows;
  }
  int ReadFile(string arr[]) {
    string row;
    ifstream file(filename);
    for (int i = 0; getline(file, row); i++) {
      arr[i] = row;
      // cout << arr[i] << endl;
    }
    file.close();
    return 0;
  }
  string LibrarysSearch(vector<string> vet, string code[], int rows) {
    for (int i = 0; i < rows; i++) {
    }
    return "";
  }
};