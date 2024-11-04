#include <iostream>

class MyVector {
  int size;
  int last_element_position;
  double *array;

public:
  class OutOfBounds {};

  MyVector();
  MyVector(int n);
  int get_size() const;
  void safe_set(double value);
  double safe_get(int pos) const;
  double &operator[](const int pos);
  ~MyVector();

private:
  bool is_in_bound(int pos) const;
  void resize();
};

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

void MyVector::safe_set(double value) {
  if (last_element_position == size)
    resize();

  array[last_element_position] = value;
  last_element_position++;
}
double MyVector::safe_get(int pos) const {
  if (!is_in_bound(pos))
    throw OutOfBounds();

  return array[pos];
}

double &MyVector::operator[](const int pos) {
  if (!is_in_bound(pos))
    throw OutOfBounds();

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

void printArray(const MyVector *mv, int size);

int main() {
  MyVector v;
  v.safe_set(3.33333);
  v.safe_set(7.39814);
  v.safe_set(929.06);
  v.safe_set(2.74);
  v.safe_set(26.83);

  printArray(&v, v.get_size());

  int pos = 10;
  try {
    int val = v.safe_get(pos);
  } catch (MyVector::OutOfBounds) {
    std::cout << "Non è possibile ottenere l'elemento in posizione " << pos
              << "\n";
  }

  return 0;
}

void printArray(const MyVector *mv, const int size) {
  for (int i = 0; i < size; i++)
    std::cout << "[" << i << "]: " << mv->safe_get(i) << "\n";
}