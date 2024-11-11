#ifndef MYVECTOR_H
#define MYVECTOR_H

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
  double pop_back(void);
  double& at(const int pos) const;
  double& operator[](const int pos);
  double& operator[](const int pos) const;
  void reserve(int n);
  ~MyVector();

private:
  bool is_in_bound(int pos) const;
  void resize();
  void resize(int n);
};

#endif