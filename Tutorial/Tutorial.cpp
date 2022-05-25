#include <iostream>
#include <string>

using namespace std;

void Funzione(string str = "valore di defualt"); // dichiarazione della funzione
void Funzione2(string str = "valore di defualt", int giorno = 25);
void ScambiaNumeri(int &x, int &y);

/*una funzione può avere anche dei valori di default che vengono impostati dal
programmatore questi valori vengono usati dal programma quando non viene passato
quel determinato argomento
quando si mette un valore di default anche tutti gli altri parametri devono
averne uno per forza */
/* ESEMPIO:
void Funzione(string str = "valore di defualt", int giorno = 25); */

int main(int argc,     // Number of strings in array argv
         char *argv[], // Array of command-line argument strings
         char *envp[]  // Array of environment variable strings
) {

  string pippo = "variabile stringa";
  int eta;

  cout << "Welcome" << endl;

  cout << "Inserisci la tua età: ";
  cin >> eta;
  cout << "La tua età: " << eta << endl;

  cout << pippo << endl;
  cout << "La stringa ha una lunghezza di: " << pippo.size() << endl;
  cout << "Questa è la prima lettera: " << pippo[0] << endl;
  pippo[8] = '3';
  cout << "Stringa modificata: " << pippo << endl;

  int x = 5;
  int y = 3;
  cout << "Condizione: ";
  cout << (x > y) << endl;

  string nome;
  cout << "Inserisci il tuo nome: " << endl;
  cin >> nome; // lo spazio è un carattere che termina l'input
  cout << "Ciao " << nome << endl;

  string *puntatore = &pippo;
  cout << "Puntatore della variabile pippo: " << puntatore << endl;
  cout << "Contenuto della variabile in posizione 'puntatore': " << *puntatore
       << endl;

  Funzione("Funzione chiamata correttamente");
  Funzione();
  Funzione2("Che bella giornata ", 7);
  Funzione2("Che bella giornata ");

  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
  ScambiaNumeri(x, y);
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;

  return 0;
}

void Funzione(string str) { cout << str << endl; }
void Funzione2(string str, int giorno) { cout << str << giorno << endl; }
void ScambiaNumeri(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}