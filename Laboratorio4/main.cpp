#include "myvector.h"
#include <iostream>

void print_array(const MyVector &mv);
MyVector moveTest();

int main() {
  std::cout << "Test: Costruttore di default\n";
  MyVector v1;
  std::cout << "Dimensione iniziale: " << v1.get_size() << "\n\n";

  std::cout << "Test: push_back e dimensionamento automatico\n";
  v1.push_back(10.945);
  v1.push_back(20.645);
  v1.push_back(30.015);
  print_array(v1);

  std::cout << "Test: pop_back\n";
  double removed = v1.pop_back();
  std::cout << "Elemento rimosso: " << removed << "\n";
  print_array(v1);

  std::cout << "Test: at con accesso valido\n";
  std::cout << "Elemento in posizione 0: " << v1.at(0) << "\n\n";

  std::cout << "Test: at con accesso fuori limite\n";
  try {
    std::cout << "Elemento in posizione 5: " << v1.at(5) << "\n\n";
  } catch (const MyVector::OutOfBounds &) {
    std::cout << "Eccezione catturata: OutOfBounds\n\n";
  }

  std::cout << "Test: Costruttore con dimensione iniziale\n";
  MyVector v2(5);
  v2.push_back(1.952);
  v2.push_back(8.002);
  print_array(v2);

  std::cout << "Test: Costruttore con initializer_list\n";
  MyVector v3{1.789, 3.015, 17.460};
  print_array(v3);

  std::cout << "Test: Operatore di copia con due oggetti già inizializzati\n";
  MyVector v4(7);
  v4 = v3;
  print_array(v4);

  std::cout << "Test: Self-assignment (DA VEDERE CON IL DEBUGGER)\n";
  v4 = v4;

  std::cout << "Test: Operatore di inizializzazione con un oggetto già "
               "inizializzato\n";
  MyVector v5 = v1;
  print_array(v5);

  std::cout << "Test: Operatore di spostamento\n";
  MyVector v6(2);
  v6 = moveTest();
  print_array(v6);

  // Test: reserve
  std::cout << "Test: reserve\n";
  v2.reserve(10);
  std::cout << "Dimensione dopo reserve(10): " << v2.get_full_size() << "\n";

  return 0;
}

void print_array(const MyVector &mv) {
  for (int i = 0; i < mv.get_size(); ++i) {
    std::cout << "[" << i << "]: " << mv[i] << "\n";
  }
  std::cout << "\n";
}

MyVector moveTest() {
  MyVector v_test;
  for (int i = 0; i < 5; i++)
    v_test.push_back(i);

  return v_test;
}