#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <algorithm>

// Costruttore di default: inizializza un vettore vuoto con capacità 0.
template <typename T> MyVector<T>::MyVector() {
  size = 0;
  last_element_position = 0;
  // Alloca un array con capacità 0 (tecnicamente un puntatore nullo)
  array = new T(size);
}

// Costruttore con capacità specificata: crea un array di
// dimensione n e lo inizializza
template <typename T> MyVector<T>::MyVector(int n) : size{n}, array{new T[n]} {
  last_element_position = 0;
  for (int i = 0; i < size; i++) // Inizializza ogni elemento con '\0'
    array[i] = '\0';
}

// Costruttore di copia: crea una copia profonda di un altro vettore
template <typename T> MyVector<T>::MyVector(const MyVector<T> &v2) {
  array = new T[v2.size];
  // Copia manualmente gli elementi dell'array
  for (int i = 0; i < v2.size; i++)
    array[i] = v2.array[i];

  size = v2.size;
  last_element_position = v2.last_element_position;
}

// Costruttore con lista di inizializzazione: consente di creare il vettore
// usando una lista '{}'
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list)
    : size{static_cast<int>(list.size())}, array{new T[size]} {
  // Copia i valori della lista nell'array.
  std::copy(list.begin(), list.end(), array);
  last_element_position = size;
}

// Restituisce il numero di elementi attualmente presenti nel vettore
template <typename T> int MyVector<T>::get_size() const {
  return last_element_position;
}

// Restituisce la capacità totale del vettore (non solo gli elementi occupati)
template <typename T> int MyVector<T>::get_full_size() const { return size; }

// Aggiunge un elemento alla fine del vettore.
// Ridimensiona l'array se necessario
template <typename T> void MyVector<T>::push_back(T value) {
  // Se non c'è spazio, raddoppia la capacità
  if (last_element_position == size)
    resize();

  array[last_element_position] = value; // Inserisce l'elemento
  last_element_position++;
}

// Rimuove e restituisce l'ultimo elemento del vettore
template <typename T> T MyVector<T>::pop_back() {
  if (last_element_position != 0)
    last_element_position--; // Decrementa il contatore degli elementi

  array[last_element_position + 1] = 0.0; // Pulisce il vecchio valore
  return array[last_element_position];    // Restituisce l'elemento rimosso
}

// Restituisce un riferimento all'elemento nella posizione specificata, con
// controllo dei limiti
template <typename T> T &MyVector<T>::at(int pos) const {
  if (!is_in_bound(pos)) // Verifica se l'indice è valido
    throw OutOfBounds(); // Lancia un'eccezione se fuori dai limiti

  return array[pos];
}

// Cambia la capacità del vettore a una dimensione specifica, se maggiore di
// quella attuale
template <typename T> void MyVector<T>::reserve(int n) {
  if (size >= n) // Se la capacità attuale è sufficiente, non fa nulla
    return;

  resize(n); // Altrimenti ridimensiona
}

// Operatore di indicizzazione senza controllo dei limiti
template <typename T> T &MyVector<T>::operator[](const int pos) {
  return array[pos];
}

// Operatore di indicizzazione per oggetti costanti
template <typename T> T &MyVector<T>::operator[](const int pos) const {
  return array[pos];
}

// Operatore di assegnazione: copia profonda da un altro vettore
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v2) {
  if (this == &v2) // Gestisce il caso di self-assignment
    return *this;

  T *tmp = new T[v2.size];                      // Alloca nuova memoria
  std::copy(v2.array, v2.array + v2.size, tmp); // Copia gli elementi
  delete[] array;                               // Libera la vecchia memoria
  array = tmp;
  size = v2.size;
  last_element_position = v2.last_element_position;
  return *this;
}

// Distruttore: libera la memoria allocata dinamicamente
template <typename T> MyVector<T>::~MyVector() {
  delete[] array;
  array = nullptr; // Resetta il puntatore per evitare dangling pointers
}

// Controlla se un indice è valido
template <typename T> bool MyVector<T>::is_in_bound(int pos) const {
  return (pos >= 0 && pos < size);
}

// Ridimensiona il vettore raddoppiandone la capacità
template <typename T> void MyVector<T>::resize() {
  int newSize = 0;
  if (size == 0)
    newSize = size = 1; // Se il vettore è vuoto, alloca capacità 1
  else
    newSize = 2 * size; // Altrimenti raddoppia la capacità

  T *arr = new T[newSize];       // Alloca un nuovo array
  for (int i = 0; i < size; i++) // Copia gli elementi esistenti
    arr[i] = array[i];

  size = newSize;
  delete[] array; // Libera la vecchia memoria
  array = arr;    // Aggiorna il puntatore
}

// Ridimensiona il vettore a una dimensione specifica
template <typename T> void MyVector<T>::resize(int n) {
  int newSize = n;

  T *arr = new T[newSize];
  for (int i = 0; i < size; i++) // Copia gli elementi esistenti
    arr[i] = array[i];

  size = newSize;
  delete[] array; // Libera la vecchia memoria
  array = arr;
}

// Costruttore di move: trasferisce i dati da un altro vettore
template <typename T>
MyVector<T>::MyVector(MyVector<T> &&mv) : size{mv.size}, array{mv.array} {
  mv.size = 0; // Resetta il vettore spostato
  mv.array = nullptr;
}

// Operatore di assegnazione di move: trasferisce i dati da un altro vettore
template <typename T> MyVector<T> &MyVector<T>::operator=(MyVector<T> &&mv) {
  delete[] array;   // Libera la memoria esistente
  array = mv.array; // Trasferisce il puntatore
  size = mv.size;
  last_element_position = mv.last_element_position;

  mv.array = nullptr; // Resetta il vettore spostato
  mv.size = 0;
  return *this;
}

#endif
