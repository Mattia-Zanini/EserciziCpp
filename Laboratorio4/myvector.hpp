#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include "myvector.h"

MyVector::MyVector() {
  size = 0;
  last_element_position = 0;
  array = new double(size);
}
MyVector::MyVector(int n) : size{n} {
  size = n;
  last_element_position = 0;
  array = new double(n);
}

int MyVector::get_size() const { return size; }

void MyVector::push_back(double value) {
  if (last_element_position == size)
    resize();

  array[last_element_position] = value;
  last_element_position++;
}

double MyVector::pop_back() {
  if(last_element_position != 0)
    last_element_position--;

  array[last_element_position + 1] = 0.0;
  return array[last_element_position];
}

double &MyVector::at(int pos) const {
  if (!is_in_bound(pos))
    throw OutOfBounds();

  return array[pos];
}

void MyVector::reserve(int n){
  if(size >= n)
    return;

  resize(n);
}

double &MyVector::operator[](const int pos) { return array[pos]; }
double &MyVector::operator[](const int pos) const { return array[pos]; }

/*
double& operator[](const int pos);

- Questa è la versione non-const dell'operatore operator[].
- Restituisce un riferimento modificabile a double, quindi permette di modificare
  l'elemento nel vettore.
- Può essere chiamata solo su oggetti non const di MyVector.

Ad esempio, con un oggetto MyVector v;, puoi scrivere v[0] = 10.5; e modificare l'elemento.


double& operator[](const int pos) const;

- Questa è la versione const dell'operatore operator[].
- L'aggiunta della keyword const alla fine della dichiarazione indica che l'operatore non
  modificherà l'oggetto.
- Viene utilizzata per accedere agli elementi di un oggetto const MyVector, senza permettere
  modifiche.

Ad esempio, se hai const MyVector v;, puoi usare v[0] per leggere un elemento, ma non puoi
modificare il valore (v[0] = 10.5; darebbe errore).
*/

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

void MyVector::resize(int n) {
  int newSize = n;

  double *arr = new double[newSize];
  for (int i = 0; i < size; i++)
    arr[i] = array[i];

  size = newSize;
  delete[] array;
  array = arr;
  arr = nullptr;
}

#endif