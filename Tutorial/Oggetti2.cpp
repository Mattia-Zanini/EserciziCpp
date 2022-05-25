#include <iostream>
#include <string>

using namespace std;

class Veicolo {
public:
  void Veic() { cout << "Sono un veicolo" << endl; }
};

class Motore {
public:
  void Mot() { cout << "Ho un motore" << endl; }
};

// multi-eredità
class Auto : public Veicolo, public Motore {};

int main() {
  Auto aut;
  aut.Veic();
  aut.Mot();
  return 0;
}