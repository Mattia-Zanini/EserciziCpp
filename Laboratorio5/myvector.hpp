#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <algorithm>

template <typename T> MyVector<T>::MyVector() {
  size = 0;
  last_element_position = 0;
  array = new T(size);
}
template <typename T> MyVector<T>::MyVector(int n) : size{n}, array{new T[n]} {
  for (int i = 0; i < size; ++i)
    array[i] = 0;
  last_element_position = 0;
}
template <typename T> MyVector<T>::MyVector(const MyVector<T> &v2) {
  array = new T[v2.size];
  // std::copy(v2.array, v2.array + size, array);
  for (int i = 0; i < v2.size; i++)
    array[i] = v2.array[i];

  size = v2.size;
  last_element_position = v2.last_element_position;
}
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list)
    : size{static_cast<int>(list.size())}, array{new T[size]} {
  std::copy(list.begin(), list.end(), array);
  last_element_position = size;
}

template <typename T> int MyVector<T>::get_size() const {
  return last_element_position;
}

// funzione membro implementata unicamente con lo scopo di
// verificare il corretto funzionamento di 'reserve()'
template <typename T> int MyVector<T>::get_full_size() const { return size; }

template <typename T> void MyVector<T>::push_back(T value) {
  if (last_element_position == size)
    resize();

  array[last_element_position] = value;
  last_element_position++;
}

template <typename T> T MyVector<T>::pop_back() {
  if (last_element_position != 0)
    last_element_position--;

  array[last_element_position + 1] = 0.0;
  return array[last_element_position];
}

template <typename T> T &MyVector<T>::at(int pos) const {
  if (!is_in_bound(pos))
    throw OutOfBounds();

  return array[pos];
}

template <typename T> void MyVector<T>::reserve(int n) {
  if (size >= n)
    return;

  resize(n);
}

template <typename T> T &MyVector<T>::operator[](const int pos) {
  return array[pos];
}
template <typename T> T &MyVector<T>::operator[](const int pos) const {
  return array[pos];
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v2) {
  T *tmp = new T[v2.size];
  std::copy(v2.array, v2.array + size, tmp);
  delete[] array;
  array = tmp;
  size = v2.size;
  last_element_position = v2.last_element_position;
  return *this;
}

// Distruttore
template <typename T> MyVector<T>::~MyVector() {
  delete[] array;
  array = nullptr;
}

template <typename T> bool MyVector<T>::is_in_bound(int pos) const {
  return (pos >= 0 && pos < size);
}

template <typename T> void MyVector<T>::resize() {
  int newSize = 0;
  if (size == 0)
    newSize = size = 1;
  else
    newSize = 2 * size;

  T *arr = new T[newSize];
  for (int i = 0; i < size; i++)
    arr[i] = array[i];

  size = newSize;
  delete[] array;
  array = arr;
  arr = nullptr;
}

template <typename T> void MyVector<T>::resize(int n) {
  int newSize = n;

  T *arr = new T[newSize];
  for (int i = 0; i < size; i++)
    arr[i] = array[i];

  size = newSize;
  delete[] array;
  array = arr;
  arr = nullptr;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T> &&mv) : size{mv.size}, array{mv.array} {
  // annullo il vecchio oggetto
  mv.size = 0;
  mv.array = nullptr;
}
template <typename T> MyVector<T> &MyVector<T>::operator=(MyVector<T> &&mv) {
  delete[] array;
  array = mv.array;
  size = mv.size;
  last_element_position = mv.last_element_position;

  mv.array = nullptr;
  mv.size = 0;
  return *this;
}

#endif
