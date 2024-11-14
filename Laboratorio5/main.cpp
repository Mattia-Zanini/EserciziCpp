#include "myvector.h"
#include <iostream>

template<typename T> void printArray(const MyVector<T> *mv, int size);

int main() {
  MyVector<double> v(3);
  v.push_back(3.33333);
  v.push_back(7.39814);
  v.push_back(929.06);
  v.push_back(2.74);
  v.push_back(26.83);
  
  printArray(&v, v.get_size());
  v.reserve(10);

  /*int pos = 10;
  try {
    int val = v.at(pos);
  } catch (MyVector::OutOfBounds) {
    std::cout << "Non è possibile ottenere l'elemento in posizione " << pos
              << "\n";
  }

  std::cout << "Riservo 13 elementi\n";
  v.reserve(10);
  printArray(&v, v.get_size());*/

  return 0;
}

template<typename T> void printArray(const MyVector<T> *mv, const int size) {
  for (int i = 0; i < size; i++)
    std::cout << "[" << i << "]: " << (*mv)[i] << "\n";
}
