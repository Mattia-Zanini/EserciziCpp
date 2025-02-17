#include <iostream>
#include <utility>
#include <vector>

class Persona {
public:
  char *nome;
  // Costruttore
  Persona(const char *n) {
    nome = new char[strlen(n) + 1]; // Allocazione dinamica
    strcpy(nome, n);
  }
  // Costruttore di copia (Shallow Copy)
  Persona(const Persona &other) {
    nome = other.nome; // ❌ Copia solo il puntatore, non la memoria
  }
  // Distruttore
  ~Persona() { // ❌ Se due oggetti condividono `nome`, doppia deallocazione!
    delete[] nome;
  }
};

class Goo {
public:
  virtual void ciao() = 0;
  void print(void) { std::cout << value << std::endl; }

private:
  int value = 10;
};

class Foo : public Goo {
public:
  // se non definisco ciao() allora anche Goo diventa una classe astratta
  void ciao() override {};
  void print(void) { std::cout << value << std::endl; }

private:
  int value = 10;
};

int main() {
  Foo my_foo;
  my_foo.print();

  std::vector<int> v{2, 10, 4, 6, 5, 8};
  for (int val : v) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  int *danglingPointer = new int(100);
  delete danglingPointer;
  std::cout << "Dangling pointer: " << *danglingPointer << "\n";

  int *p1{&v[0]};
  int *p2{&v[2]};
  std::cout << (p2 - p1) + 1 << std::endl; // aritmetica dei puntatori

  Persona pp1("Alice");
  // Persona pp2 = pp1; // DOPPIA DELETE A FINE PROGRAMMA!
  std::cout << "p1: " << pp1.nome << std::endl;
  // std::cout << "p2: " << pp2.nome << std::endl;

  std::vector<int>::iterator b = v.begin();
  for (; b != v.end(); b++) {
  }

  int v2[4] = {1, 2, 3, 4};
  int *p = &v[2];
  int *q = p + 2;

  return 0;
}