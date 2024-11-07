#include "myvector.cpp"
#include <iostream>

void printArray(const MyVector *mv, int size);

int main() {
  MyVector v;
  v.push_back(3.33333);
  v.push_back(7.39814);
  v.push_back(929.06);
  v.push_back(2.74);
  v.push_back(26.83);

  printArray(&v, v.get_size());

  int pos = 10;
  try {
    int val = v.at(pos);
  } catch (MyVector::OutOfBounds) {
    std::cout << "Non è possibile ottenere l'elemento in posizione " << pos
              << "\n";
  }

  std::cout << "Riservo 13 elementi\n";
  v.reserve(10);
  printArray(&v, v.get_size());

  return 0;
}

void printArray(const MyVector *mv, const int size) {
  for (int i = 0; i < size; i++)
    std::cout << "[" << i << "]: " << (*mv)[i] << "\n";
}

/*
double& operator[](const int pos);

- Questa è la versione non-const dell'operatore operator[].
- Restituisce un riferimento modificabile a double, quindi permette di modificare l'elemento nel vettore.
- Può essere chiamata solo su oggetti non const di MyVector.

Ad esempio, con un oggetto MyVector v;, puoi scrivere v[0] = 10.5; e modificare l'elemento.


double& operator[](const int pos) const;

- Questa è la versione const dell'operatore operator[].
- L'aggiunta della keyword const alla fine della dichiarazione indica che l'operatore non modificherà l'oggetto.
- Viene utilizzata per accedere agli elementi di un oggetto const MyVector, senza permettere modifiche.

Ad esempio, se hai const MyVector v;, puoi usare v[0] per leggere un elemento, ma non puoi modificare il valore (v[0] = 10.5; darebbe errore).
*/