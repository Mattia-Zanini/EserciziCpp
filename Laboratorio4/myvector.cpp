#include "myvector.h"

MyVector::MyVector() {
  size = 0;
  last_element_position = 0;
  array = new double[size];
}
MyVector::MyVector(int n) : size{n} {
  size = n;
  last_element_position = 0;
  array = new double[n];

  // inizializzo l'array
  for (int i = 0; i < size; i++)
    array[i] = 0.0;
}

int MyVector::get_size() const { return size; }

void MyVector::push_back(double value) {
  if (last_element_position == size)
    resize();

  array[last_element_position] = value;
  last_element_position++;
}
double& MyVector::at(int pos) const {
  if (!is_in_bound(pos))
    throw OutOfBounds();

  return array[pos];
}

double& MyVector::operator[](const int pos){
  return array[pos];
}
double& MyVector::operator[](const int pos) const{
  return array[pos];
}

// Distruttore
MyVector::~MyVector() {
  delete[] array;
  array = nullptr;
}
bool MyVector::is_in_bound(int pos) const { return (pos >= 0 && pos < size); }
void MyVector::resize() {
  int newSize = 0;
  if (size == 0)
    newSize = size = 1;
  else
    newSize = 2 * size;

  double *arr = new double[newSize];
  for (int i = 0; i < size; i++)
    arr[i] = array[i];

  size = newSize;
  delete[] array;
  array = arr;
  arr = nullptr;
}
