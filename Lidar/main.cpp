#include "LidarDriver.cpp"

void print_lider_scans(LidarDriver &ld, int count);

int main() {
  // TEST costruttore di default
  std::cout << "TEST costruttore di default" << std::endl;
  LidarDriver ld;

  // TEST funzione membro: new_scan
  // verifico anche il troncamento dei valori in eccesso
  std::cout << "TEST funzione membro: new_scan, verifico anche il troncamento "
               "dei valori in eccesso"
            << std::endl;
  std::vector<double> testVector(182);
  double value = 0;
  for (int i = 0; i < 182; i++) {
    value += 0.1;
    testVector[i] = value;
  }
  // testVector[181] = 18.2, ovvero il 182-esimo valore
  // non verrà inserito nella scansione

  ld.new_scan(testVector);
  // TEST overload operatore <<
  std::cout << "TEST overload operatore <<" << std::endl;
  std::cout << ld << std::endl;

  // TEST funzione membro: new_scan
  // verifico anche l'inizializzazione dei valori mancanti a 0
  std::cout << "TEST funzione membro: new_scan, verifico anche "
               "l'inizializzazione dei valori mancanti a 0"
            << std::endl;
  std::vector<double> testVector2(20);
  value = 0;
  for (int i = 0; i < 20; i++) {
    value += 0.8;
    testVector2[i] = value;
  }
  ld.new_scan(testVector2);

  // TEST overload operatore <<
  std::cout << "TEST overload operatore <<" << std::endl;
  std::cout << ld << std::endl;

  // TEST funzione membro: get_distance
  // l'ultima scansione inserita è testVector2, quindi
  // se richiedo il valore a 0 gradi dovrei ottenere 0.8
  std::cout << "TEST funzione membro: get_distance" << std::endl;
  std::cout << "Distanza dell'ultima scansione a 0°: " << ld.get_distance(0)
            << std::endl
            << std::endl;

  // TEST circolarità del buffer
  std::cout << "TEST circolarità del buffer" << std::endl;
  std::vector<double> testVector3(1);
  for (int i = 0; i < 12; i++) {
    testVector3[0] = i;
    ld.new_scan(testVector3);
  }

  std::cout << "Situazione teorica:\n"
            << "buffer[0]: {8, 0, ...}\n"
            << "buffer[1]: {9, 0, ...}\n"
            << "buffer[2]: {10, 0, ...}\n"
            << "buffer[3]: {11, 0, ...}\n"
            << "buffer[4]: {2, 0, ...}\n"
            << "buffer[5]: {3, 0, ...}\n"
            << "buffer[6]: {4, 0, ...}\n"
            << "buffer[7]: {5, 0, ...}\n"
            << "buffer[8]: {6, 0, ...}\n"
            << "buffer[9]: {7, 0, ...}\n"
            << std::endl;

  print_lider_scans(ld, 10);

  // TEST funzione membro: get_scan
  std::cout << "\nTEST funzione membro: get_scan, la invoco 4 volte"
            << std::endl;
  ld.get_scan();
  ld.get_scan();
  ld.get_scan();
  ld.get_scan();

  // stampo solo quelle che non risultano eliminate
  print_lider_scans(ld, ld.get_index());

  // TEST funzione membro: clear_buffer
  std::cout << "\nTEST funzione membro: clear_buffer" << std::endl;
  ld.clear_buffer();
  std::cout << "index del buffer: " << ld.get_index() << std::endl;

  return 0;
}

void print_lider_scans(LidarDriver &ld, int count) {
  std::cout << "Situazione corrente dello storico delle scansioni:"
            << std::endl;
  for (int i = 0; i < count; i++)
    std::cout << "buffer[" << i
              << "][0]: " << ld.get_distance_from_specific_scan(0, i)
              << std::endl;
}