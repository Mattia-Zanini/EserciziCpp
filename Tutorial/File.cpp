#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  /*// Crea un file
  ofstream file("prova.txt");
  file<<"Questa riga verrà scritta sul file";
  file.close();*/

  // leggere dati da un file
  ifstream file("prova.txt");
  string riga;
  //legge riga per riga il file
  while (getline(file, riga)) {
    cout << riga << endl;
  }
  return 0;
}