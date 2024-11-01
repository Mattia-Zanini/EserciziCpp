#include <iostream>

class MyVector {
  int size;
  double *array;

public:
  class Invalid {};

  MyVector();
  MyVector(int n);
  void safe_set(int pos, double value);
  double safe_get(int pos);
  double &operator[](const int pos);
  ~MyVector();

private:
  bool isInBound(int pos);
};

MyVector::MyVector() {
  size = 1;
  array = new double[size];
}
MyVector::MyVector(int n) {
  size = n;
  array = new double[n];
}

void MyVector::safe_set(int pos, double value) {
  if (!isInBound(pos))
    throw Invalid();

  array[pos] = value;
}
double MyVector::safe_get(int pos) {
  if (!isInBound(pos))
    throw Invalid();

  return array[pos];
}

double &MyVector::operator[](const int pos) {
  if (!isInBound(pos)) {
    throw Invalid();
  }
  return array[pos];
}

MyVector::~MyVector() { delete[] array; }
bool MyVector::isInBound(int pos) { return (pos >= 0 && pos < size); }

int main() {
  MyVector v(5);
  v.safe_set(0, 3.33333);
  v.safe_set(1, 7.39814);

  std::cout << "[0]: " << v[0] << "\n";
  std::cout << "[1]: " << v[1] << "\n";

  return 0;
}
