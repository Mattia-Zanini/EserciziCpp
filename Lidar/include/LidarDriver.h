#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include <iostream>
#include <vector>

class LidarDriver {

private:
  constexpr static int view = 180; // angolo di vista costante
  // numero di scansioni che si possono memorizzare
  constexpr static int buffer_dim = 10;
  double resolution;                       // risoluzione angolare
  std::vector<std::vector<double>> buffer; // buffer di scansioni
  int index;        // posizione di inserimento della prossima scansione
  int scansion_dim; // numero di letture all'interno di una scansione
  bool is_full = false;

public:
  LidarDriver(double r = 1.0);

  class AngleOutOfBound {};
  class EmptyLidar {};
  class ResolutionValueNotValid {};

  void new_scan(const std::vector<double> &values);
  std::vector<double> get_scan();
  void clear_buffer();
  double get_distance(double alfa);

  //-------------------------------------------------------------------------------------//
  // !!! solo per debugging e dimostrazione del corretto funzionamento del
  // codice, stampa la distanza ad un certo angolo da una specifica scansione
  const double get_distance_from_specific_scan(double alfa, int scan_index);
  class ScanIndexOutOfBound {};
  //-------------------------------------------------------------------------------------//

  // getter
  int get_index() { return index; }
  int get_scansion_dim() { return scansion_dim; }
  double get_resolution() { return resolution; }
};

std::ostream &operator<<(std::ostream &os, const LidarDriver &ld);

#endif