class MyVector {
  int size;
  int last_element_position;
  double *array;

public:
  class OutOfBounds {};

  MyVector();
  MyVector(int n);
  int get_size() const;
  void push_back(double value);
  double* pop_back(void);
  double& at(const int pos) const;
  double& operator[](const int pos);
  ~MyVector();

private:
  bool is_in_bound(int pos) const;
  void resize();
};
