#include "Manuali.h"

// Costruttore, dispositivo manuale, l'ora di spegnimento viene impostata
// a 23.59 in minuti
Manuali::Manuali(std::string n, int indirizzo, double cons)
    : oraSpegnimento(1439) {
  nome = n;
  consumo = cons;
  statoDispositivo = false;
  id = indirizzo;
}
// Distruttore
Manuali::~Manuali() {}
void Manuali::modificaSpegnimento(int ora) { oraSpegnimento = ora; }