#include "myvector.h"
#include <iostream>

template <typename T> void print_array(const MyVector<T> &mv);
MyVector<int> moveTest();

int main() {
  std::cout << "Test: Costruttore di default\n";
  MyVector<int> v1;
  std::cout << "Dimensione iniziale: " << v1.get_size() << "\n\n";

  std::cout << "Test: push_back e dimensionamento automatico\n";
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  print_array(v1);

  std::cout << "Test: pop_back\n";
  int removed = v1.pop_back();
  std::cout << "Elemento rimosso: " << removed << "\n";
  print_array(v1);

  std::cout << "Test: at con accesso valido\n";
  std::cout << "Elemento in posizione 0: " << v1.at(0) << "\n\n";

  std::cout << "Test: at con accesso fuori limite\n";
  try {
    std::cout << "Elemento in posizione 5: " << v1.at(5) << "\n\n";
  } catch (const MyVector<int>::OutOfBounds &) {
    std::cout << "Eccezione catturata: OutOfBounds\n\n";
  }

  std::cout << "Test: Costruttore con dimensione iniziale\n";
  MyVector<double> v2(5);
  v2.push_back(1.1);
  v2.push_back(2.2);
  print_array(v2);

  std::cout << "Test: Costruttore con initializer_list\n";
  MyVector<std::string> v3{"A", "B", "C"};
  print_array(v3);

  std::cout << "Test: Operatore di copia con due oggetti già inizializzati\n";
  MyVector<std::string> v4(7);
  v4 = v3;
  print_array(v4);

  std::cout << "Test: Self-assignment (DA VEDERE CON IL DEBUGGER)\n";
  v4 = v4;

  std::cout << "Test: Operatore di inizializzazione con un oggetto già "
               "inizializzato\n";
  MyVector<int> v5 = v1;
  print_array(v5);

  std::cout << "Test: Operatore di spostamento\n";
  MyVector<int> v6(2);
  v6 = moveTest();
  print_array(v6);

  std::cout << "Test: reserve\n";
  v2.reserve(10);
  std::cout << "Dimensione dopo reserve(10): " << v2.get_full_size() << "\n";

  return 0;
}

template <typename T> void print_array(const MyVector<T> &mv) {
  for (int i = 0; i < mv.get_size(); ++i) {
    std::cout << "[" << i << "]: " << mv[i] << "\n";
  }
  std::cout << "\n";
}

MyVector<int> moveTest() {
  MyVector<int> v_test;
  for (int i = 0; i < 5; i++)
    v_test.push_back(i);

  return v_test;
}