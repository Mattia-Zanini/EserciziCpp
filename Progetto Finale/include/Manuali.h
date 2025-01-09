#ifndef MANUALI_H
#define MANUALI_H

#include "Dispositivo.h"
#include <iostream>
#include <string>

class Manuali : public Dispositivo {
private:
  int oraSpegnimento;

public:
  // costruttore
  Manuali(std::string n, int indirizzo, double cons);
  ~Manuali(); // distruttore
  // ritorna l'orario di spegnimento in minuti
  int orarioSpegnimento() const { return oraSpegnimento; }
  void modificaSpegnimento(int ora);
};

#endif