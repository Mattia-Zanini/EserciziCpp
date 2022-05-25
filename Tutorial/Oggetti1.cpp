#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
  int eta;
  string nome;
  string cognome;
  void Info() { cout << "Nome: " << nome << " Età: " << eta << endl; }
  void funzione();

  // costruttore, deve avere lo stesso nome della classe
  Persona() { cout << "Oggetto creato con successo" << endl; }
};

// dichiaro la funzione fuori dal codice della classe
void Persona::funzione() { cout << "Funzione chiamata correttamente" << endl; }

class Persona2 : public Persona {
public:
  Persona2(string nome, string cognome, int eta) {
    cout << "Oggetto creato con successo" << endl;
    this->nome = nome;
    this->cognome = cognome;
    this->eta = eta;
    cout << "Nome: " << this->nome << endl
         << "Cognome: " << this->cognome << endl
         << "Età: " << this->eta << endl;
  }
};

int main() {

  Persona persona1;
  persona1.eta = 10;
  persona1.nome = "Mario";

  cout << persona1.nome << endl;
  cout << persona1.eta << endl;

  persona1.Info();
  persona1.funzione();

  Persona2 pers("Luca", "Rossi", 18);

  return 0;
}