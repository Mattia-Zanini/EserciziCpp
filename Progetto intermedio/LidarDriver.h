#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H
#include <vector>

class LidarDriver {

private:
  constexpr static int view = 180; // angolo di vista costante
  // numero di scansioni che si possono memorizzare
  constexpr static int buffer_dim = 10;
  const double resolution;                 // risoluzione angolare
  std::vector<std::vector<double>> buffer; // buffer di scansioni
  int index;        // posizione di inserimento della prossima scansione
  int scansion_dim; // numero di letture all'interno di una scansione
  bool is_full = false;

public:
  LidarDriver(double r); // costruttore

  class EmptyLidar {};

  void new_scan(const std::vector<double> &values);
  std::vector<double> &get_scan();
  void clear_buffer();
  double get_distance(double alfa);
  void print_last();

  // getter
  int get_index() { return index; }
  int get_scansion_dim() { return scansion_dim; }
};

#endif