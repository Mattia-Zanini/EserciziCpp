#include "myvector.h"
#include <iostream>

template <typename T> void printArray(const MyVector<T> &mv);

int main() {
  // Test: Costruttore vuoto
  std::cout << "Test: Costruttore vuoto\n";
  MyVector<int> v1;
  std::cout << "Dimensione iniziale: " << v1.get_size() << "\n";

  // Test: push_back e dimensionamento automatico
  std::cout << "\nTest: push_back e dimensionamento\n";
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  printArray(v1);

  // Test: pop_back
  std::cout << "Test: pop_back\n";
  int removed = v1.pop_back();
  std::cout << "Elemento rimosso: " << removed << "\n";
  printArray(v1);

  // Test: at con accesso valido
  std::cout << "Test: at con accesso valido\n";
  std::cout << "Elemento in posizione 0: " << v1.at(0) << "\n\n";

  // Test: at con accesso fuori limite
  std::cout << "Test: at con accesso fuori limite\n";
  try {
    std::cout << "Elemento in posizione 5: " << v1.at(5) << "\n\n";
  } catch (const MyVector<int>::OutOfBounds &) {
    std::cout << "Eccezione catturata: OutOfBounds\n\n";
  }

  // Test: Costruttore con dimensione iniziale
  std::cout << "Test: Costruttore con dimensione iniziale\n";
  MyVector<double> v2(5);
  v2.push_back(1.1);
  v2.push_back(2.2);
  printArray(v2);

  // Test: Costruttore con initializer_list
  std::cout << "Test: Costruttore con initializer_list\n";
  MyVector<std::string> v3{"A", "B", "C"};
  printArray(v3);

  // Test: Operatore di copia
  std::cout << "Test: Operatore di copia\n";
  MyVector<std::string> v4 = v3;
  printArray(v4);

  // Test: Operatore di spostamento
  std::cout << "Test: Operatore di spostamento\n";
  MyVector<std::string> v5 = std::move(v4);
  printArray(v5);

  // Test: reserve
  std::cout << "Test: reserve\n";
  v2.reserve(10);
  std::cout << "Dimensione dopo reserve(10): " << v2.get_size() << "\n";

  return 0;
}

template <typename T> void printArray(const MyVector<T> &mv) {
  for (int i = 0; i < mv.get_size(); ++i) {
    std::cout << "[" << i << "]: " << mv[i] << "\n";
  }
  std::cout << "\n";
}