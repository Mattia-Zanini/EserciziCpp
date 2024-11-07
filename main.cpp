#include "myvector.cpp"
#include <iostream>

//void printArray(MyVector mv, int size);

int main() {
  MyVector v;
  v.push_back(3.33333);
  v.push_back(7.39814);
  v.push_back(929.06);
  v.push_back(2.74);
  v.push_back(26.83);

  for (int i = 0; i < v.get_size(); i++)
    std::cout << "[" << i << "]: " << v[i] << "\n";

  int pos = 10;
  try {
    int val = v.at(pos);
  } catch (MyVector::OutOfBounds) {
    std::cout << "Non è possibile ottenere l'elemento in posizione " << pos
              << "\n";
  }

  return 0;
}

/*void printArray(MyVector mv, const int size) {
  for (int i = 0; i < size; i++)
    std::cout << "[" << i << "]: " << mv[i] << "\n";
}*/
