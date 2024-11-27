#include "LidarDriver.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

// Costruttori: inizializza le variabili e crea una matrice che ha un numero di
// colonne pari a buffer_dim e ciascuna di esse è di tipo double ed è lunga view
LidarDriver::LidarDriver(double r) : index{0} {
  if (r < 0.1 || r > 1)
    throw ResolutionValueNotValid();

  resolution = r;
  scansion_dim = 1 + view / r;
  buffer.resize(buffer_dim, std::vector<double>(scansion_dim));
}

// Aggiunge una nuova scansione al buffer, adattandola alla dimensione prevista.
// Gestisce la circolarità del buffer sovrascrivendo gli elementi più vecchi
// quando è pieno.
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

// Se il buffer non è pieno, le scansioni vengono semplicemente spostate in
// avanti per coprire il vuoto lasciato dalla rimozione. Se il buffer è pieno,
// la natura circolare del buffer viene temporaneamente eliminata: le scansioni
// più nuove (prima di index) vengono salvate in un'area temporanea, mentre le
// scansioni più vecchie (dopo index) vengono spostate all'inizio del buffer.
// Successivamente, le scansioni più nuove vengono reinserite in fondo al
// buffer, ripristinando un ordine lineare.
std::vector<double> LidarDriver::get_scan() {
  // caso 1: Lidar non pieno (-> gli x<buffer_dim elementi del Lidar si trovano
  // nelle prime x posizioni)
  if (!is_full) {
    if (index == 0) {
      throw LidarDriver::EmptyLidar(); // non c'è alcuna scansione presente
    }
    std::vector<double> oldest = buffer[0];
    // la scansione più vecchia si trova nella prima cella
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
    std::vector<double> oldest = buffer[index];
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
    // prima il lidar era pieno, ora ho rimosso una scansione
    index = buffer_dim - 1;
    is_full = false;
    return oldest;
  }
}

// Resetta lo stato del buffer, cancellando tutte le scansioni memorizzate
// resettando il valore di index a zero
void LidarDriver::clear_buffer() {
  index = 0;
  is_full = false;
}

// Restituisce la distanza rilevata a un angolo specificato nella scansione più
// recente. Controlla la validità di angolo e la disponibilità di scansioni
// (quando index = 0 e il buffer non è pieno).
double LidarDriver::get_distance(double alfa) {
  if (alfa < 0 || alfa > 180)
    throw LidarDriver::AngleOutOfBound(); // l'angolo inserito non è valido

  if (index == 0) {
    if (!is_full) {
      throw LidarDriver::EmptyLidar(); // non c'è alcuna scansione presente
    } else {
      // la scansione più recente si trova nell'ultima cella del buffer (per via
      // della circolarità)
      return buffer[buffer_dim - 1][round(alfa / resolution)];
    }
  }
  return buffer[index - 1][round(alfa / resolution)];
}

// Restituisce la distanza rilevata a un angolo specificato da una scansione
// indicata tramite indice. Verifica validità di angolo e indice.
const double LidarDriver::get_distance_from_specific_scan(double alfa,
                                                          int scan_index) {
  if (alfa < 0 || alfa > 180)
    throw LidarDriver::AngleOutOfBound();

  if (scan_index < 0 || scan_index > buffer_dim)
    throw LidarDriver::ScanIndexOutOfBound();

  return buffer[scan_index][round(alfa / resolution)];
}

// Stampa tutte le distanze rilevate a ogni angolo, per la scansione più
// recente e scrivendo all'inizio il valore della risoluzione
std::ostream &operator<<(std::ostream &os, LidarDriver &ld) {
  constexpr static int view = 180; // angolo di vista costante
  const double resolution = ld.get_resolution();

  os << "Risoluzione: " << resolution << "\n";
  for (double i = 0; i <= view; i += resolution)
    os << "[" << i << "°]: " << ld.get_distance(i) << "\n";

  return os;
}