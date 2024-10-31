class MyVector {
  int size;
  double *array;

public:
  MyVector();
  MyVector(int n);
  void safe_set(int pos, double value);
  double safe_get(int pos);
  double operator[](const int pos);
  ~MyVector();
};

MyVector::MyVector() {
  size = 1;
  array = new double[size];
}
MyVector::MyVector(int n) {
  size = n;
  array = new double[n];
}

void MyVector::safe_set(int pos, double value) {}
double MyVector::safe_get(int pos) { return 0; }
double MyVector::operator[](const int pos) { return 0; }
MyVector::~MyVector() {
  delete[] array;
}

int main() {
  MyVector v = MyVector();
  return 0;
}
