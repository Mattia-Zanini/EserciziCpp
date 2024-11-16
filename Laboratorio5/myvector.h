#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <initializer_list>

template <typename T> class MyVector {
  int size;
  int last_element_position;
  T *array;

public:
  class OutOfBounds {};

  MyVector();
  explicit MyVector(int n);
  MyVector(const MyVector<T> &v2);
  MyVector(std::initializer_list<T> list);
  int get_size() const;

  // funzione membro implementata unicamente con lo scopo di
  // verificare il corretto funzionamento di 'reserve()'
  int get_full_size() const;

  void reserve(int n);
  void push_back(T value);
  T pop_back(void);
  T &at(const int pos) const;
  T &operator[](const int pos);
  T &operator[](const int pos) const;
  MyVector &operator=(const MyVector &v2);
  MyVector(MyVector &&a);
  MyVector &operator=(MyVector &&a);
  ~MyVector();

private:
  bool is_in_bound(int pos) const;
  void resize();
  void resize(int n);
};

#include "myvector.hpp"
#endif
