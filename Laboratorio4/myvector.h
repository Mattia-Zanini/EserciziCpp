#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <initializer_list>

class MyVector {
  int size;
  int last_element_position;
  double *array;

public:
  class OutOfBounds {};

  MyVector();
  MyVector(int n);
  MyVector(const MyVector& v2);
  MyVector(std::initializer_list<double> lst);
  int get_size() const;
  void reserve(int n);
  void push_back(double value);
  double pop_back(void);
  double& at(const int pos) const;
  double& operator[](const int pos);
  double& operator[](const int pos) const;
  MyVector& operator=(const MyVector& v2);
  MyVector(MyVector&& a);
  MyVector&operator=(MyVector&& a);
  ~MyVector();

private:
  bool is_in_bound(int pos) const;
  void resize();
  void resize(int n);
};

#include "myvector.hpp"
#endif
