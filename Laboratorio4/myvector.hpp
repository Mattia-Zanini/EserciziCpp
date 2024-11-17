#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <algorithm>

MyVector::MyVector() {
  size = 0;
  last_element_position = 0;
  array = new double(size);
}
MyVector::MyVector(int n) : size{n} {
  last_element_position = 0;
  array = new double(n);
}
MyVector::MyVector(const MyVector &mv2) {
  array = new double[mv2.size];
  // std::copy(mv2.array, mv2.array + mv2.size, array);
  for (int i = 0; i < mv2.size; i++)
    array[i] = mv2.array[i];

  size = mv2.size;
  last_element_position = mv2.last_element_position;
}
MyVector::MyVector(std::initializer_list<double> list)
    : size{static_cast<int>(list.size())}, array{new double[size]} {
  std::copy(list.begin(), list.end(), array);
  last_element_position = size;
}

int MyVector::get_size() const { return last_element_position; }

// funzione membro implementata unicamente con lo scopo di
// verificare il corretto funzionamento di 'reserve()'
int MyVector::get_full_size() const { return size; }

void MyVector::push_back(double value) {
  if (last_element_position == size)
    resize();

  array[last_element_position] = value;
  last_element_position++;
}

double MyVector::pop_back() {
  if (last_element_position != 0)
    last_element_position--;

  array[last_element_position + 1] = 0.0;
  return array[last_element_position];
}

double &MyVector::at(int pos) const {
  if (!is_in_bound(pos))
    throw OutOfBounds();

  return array[pos];
}

void MyVector::reserve(int n) {
  if (size >= n)
    return;

  resize(n);
}

double &MyVector::operator[](const int pos) { return array[pos]; }
double &MyVector::operator[](const int pos) const { return array[pos]; }

/*
double& operator[](const int pos);

- Questa è la versione non-const dell'operatore operator[].
- Restituisce un riferimento modificabile a double, quindi permette di
modificare l'elemento nel vettore.
- Può essere chiamata solo su oggetti non const di MyVector.

Ad esempio, con un oggetto MyVector v;, puoi scrivere v[0] = 10.5; e modificare
l'elemento.


double& operator[](const int pos) const;

- Questa è la versione const dell'operatore operator[].
- L'aggiunta della keyword const alla fine della dichiarazione indica che
l'operatore non modificherà l'oggetto.
- Viene utilizzata per accedere agli elementi di un oggetto const MyVector,
senza permettere modifiche.

Ad esempio, se hai const MyVector v;, puoi usare v[0] per leggere un elemento,
ma non puoi modificare il valore (v[0] = 10.5; darebbe errore).
*/

MyVector &MyVector::operator=(const MyVector &mv2) {
  if (this == &mv2) // Verifica self-assignment
    return *this;

  double *tmp = new double[mv2.size];
  std::copy(mv2.array, mv2.array + mv2.size, tmp);
  delete[] array;
  array = tmp;
  size = mv2.size;
  last_element_position = mv2.last_element_position;
  return *this;
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
}

void MyVector::resize(int n) {
  int newSize = n;

  double *arr = new double[newSize];
  for (int i = 0; i < size; i++)
    arr[i] = array[i];

  size = newSize;
  delete[] array;
  array = arr;
}

MyVector::MyVector(MyVector &&mv2) : size{mv2.size}, array{mv2.array} {
  // annullo il vecchio oggetto
  mv2.size = 0;
  mv2.array = nullptr;
}
MyVector &MyVector::operator=(MyVector &&mv2) {
  delete[] array;
  array = mv2.array;
  size = mv2.size;
  last_element_position = mv2.last_element_position;

  mv2.array = nullptr;
  mv2.size = 0;
  return *this;
}

#endif
