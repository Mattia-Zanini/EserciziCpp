#include "LidarDriver.h"
#include <algorithm>
#include <iostream>
#include <vector>

// costruttore: inizializza le variabili e crea una matrice che ha un numero di
// colonne pari a buffer_dim e ciascuna di esse è di tipo double ed è lunga view
LidarDriver::LidarDriver(double r)
    : resolution{r}, index{0}, scansion_dim{static_cast<int>(1 + view / r)} {
  buffer.resize(buffer_dim, std::vector<double>(view)); //<--MODIFICARE
}

void LidarDriver::new_scan(const std::vector<double> &values) {
  std::vector<double> adjusted_values = values;
  // Se la dimensione dei valori è inferiore al previsto, aggiungi zeri
  if (adjusted_values.size() < scansion_dim) {
    adjusted_values.resize(scansion_dim, 0.0); // Completa con zeri
  }
  // Se la dimensione è maggiore, taglia i valori in eccesso
  else if (adjusted_values.size() > scansion_dim) {
    adjusted_values.resize(scansion_dim); // Taglia in eccesso
  }

  // Aggiungi la nuova scansione
  buffer[index] = adjusted_values;
  ++index;

  // Gestione circolare
  if (index == buffer_dim) {
    is_full = true;
    index = 0;
  }
}

std::vector<double> &LidarDriver::get_scan() {

  // caso 1: Lidar non pieno (-> gli x<buffer_dim elementi del Lidar si trovano
  // nelle prime x posizioni)
  if (!is_full) {
    if (index == 0) {
      throw LidarDriver::EmptyLidar(); // non c'è alcuna scansione presente
    }
    std::vector oldest =
        buffer[0]; // la scansione più vecchia si trova nella prima cella
    // rimozione della scansione più vecchia spostando le altre scansioni
    // all'inizio del buffer mantenendo l'ordine di inserimento
    --index;
    for (int i = 0; i < index; i++) {
      buffer[i] = buffer[i + 1];
    }
    return oldest;
  }

  // Caso 2: Lidar pieno (in questo caso index per come è stato progettato punta
  // già all'elemento più vecchio)
  else {
    std::vector oldest = buffer[index];
    // rimozione della scansione più vecchia spostando le altre scansioni
    // all'inizio del buffer mantenendo l'ordine di inserimento TENERE PRESENTE
    // DELLA CIRCOLARITà DEL BUFFER passo 1: copio in un vettore le scansioni
    // che si trovano nelle celle precedenti a quella da eliminare, le quali
    // sono le più nuove
    std::vector<std::vector<double>> newest(index);
    for (int i = 0; i < index; i++) {
      newest[i] = buffer[i];
    }
    // passo2: sposto all'inizio del buffer le scansioni che si trovano nelle
    // celle successive a quella da eliminare, le quali sono le più vecchie
    for (int i = 0; i < buffer_dim - (index + 1); i++) {
      buffer[i] = buffer[index + 1 + i];
    }
    // passo 3: risposto le scansioni più nuove nel buffer, ma non nelle loro
    // celle iniziali, ma in quelle successive a quelle appena occupate dalle
    // scansioni più vecchie
    for (int i = 0; i < index; i++) {
      buffer[buffer_dim - (index + 1) + i] = newest[i];
    }
    index = buffer_dim -
            1; // prima il lidar era pieno, ora ho rimosso una scansione
    is_full = false;
    return oldest;
  }
}

void LidarDriver::clear_buffer() {
  index = 0;
  is_full = false;
}

double LidarDriver::get_distance(double alfa) {
  if (index == 0) {
    if (!is_full) {
      throw LidarDriver::EmptyLidar(); // non c'è alcuna scansione presente
    } else {
      return buffer[buffer_dim - 1]
                   [(int)alfa /
                    resolution]; // la scansione più recente si trova
                                 // nell'ultima cella del buffer (per via della
                                 // circolarità)
    }
  }
  return buffer[index - 1][(int)alfa / resolution];
}

int main() { return 0; }