#include <iostream>
#include <memory>

int foo(const int *x);
int goo(int *const x);
void t(int n);
void u(const int &x);
void dArr(int arr[]);

class B {
private:
  int *elem; // Puntatore all'array dinamico
  int size;  // Dimensione dell'array

public:
  // 1️⃣ Costruttore di default
  explicit B() : elem(nullptr), size(0) {
    std::cout << "Costruttore di default\n";
  }

  // 2️⃣ Costruttore con uno o più argomenti
  B(int s, int val = 0) : size(s) {
    std::cout << "Costruttore con parametri\n";
    elem = new int[size];
    std::fill(elem, elem + size,
              val); // Inizializza tutti gli elementi con 'val'
  }

  // 3️⃣ Costruttore di copia (copy constructor)
  B(const B &other) : size(other.size) {
    std::cout << "Costruttore di copia\n";
    elem = new int[size];
    std::copy(other.elem, other.elem + size, elem);
  }

  // 4️⃣ Assegnamento di copia (copy assignment)
  B &operator=(const B &other) {
    std::cout << "Assegnamento di copia\n";
    if (this != &other) { // Evita autoassegnazione
      delete[] elem;      // Libera la memoria esistente
      size = other.size;
      elem = new int[size];
      std::copy(other.elem, other.elem + size, elem);
    }
    return *this;
  }

  int &operator[](int n) { return elem[n]; }; // scrittura
  int operator[](int n) const { return elem[n]; }; // lettura

  // 5️⃣ Costruttore di spostamento (move constructor)
  B(B &&other) : elem(other.elem), size(other.size) {
    std::cout << "Costruttore di spostamento (move constructor)\n";
    other.elem = nullptr;
    other.size = 0;
  }

  // 6️⃣ Assegnamento di spostamento (move assignment)
  B &operator=(B &&other) {
    std::cout << "Assegnamento di spostamento (move assignment)\n";
    if (this != &other) {
      delete[] elem; // Libera la memoria esistente
      elem = other.elem;
      size = other.size;
      other.elem = nullptr;
      other.size = 0;
    }
    return *this;
  }

  // 7️⃣ Distruttore
  ~B() {
    std::cout << "Distruttore\n";
    delete[] elem;
  }

  // Funzione per stampare gli elementi
  void print() const {
    for (int i = 0; i < size; ++i)
      std::cout << elem[i] << " ";
    std::cout << "\n";
  }
};

int p;

int main() {
  float x{2.7};
  double y{x};

  std::cout << "v: " << x << '\n';
  std::cout << "w: " << y << '\n';

  double z{2.7};
  int w = z; // int w{z};
  // int w{static_cast<int>(v)}; Funziona però è brutto

  std::cout << "v: " << z << '\n';
  std::cout << "w: " << w << '\n';

  std::vector<int> v{1, 2, 3, 4, 5};
  int i = 0;
  v[i] = i++;

  int g;
  static int m;
  std::cout << "p: " << p << '\n';
  std::cout << "g: " << g << '\n';
  std::cout << "m: " << m << '\n';

  enum class Month{ jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  Month m1 = Month::feb;
  Month m2 = Month(3);

  int *p0 = nullptr;
  if (!p0)
    std::cout << "p0 = nullptr\n";

  int *p1 = nullptr;
  // *p1 = 5; //segmentation fault
  // std::cout << "*p1:" << *p1 << '\n'; //segmentation fault

  int a = 2;
  const int *p2 = &a; // non posso cambiare il valore di a
  std::cout << "*p2: " << *p2 << '\n';
  int b = 5;
  p2 = &b; // il puntatore può variare
  std::cout << "*p2: " << *p2 << '\n';

  int c = 7;
  int d = 9;
  int *const p3 = &c;
  // p3 = &d; // non posso modificare il puntatore in sè
  *p3 = 8; // però posso cambiare il valore di ciò a cui punta
  std::cout << "*p3: " << *p3 << '\n';
  std::cout << "sizeof(int*) p3: " << sizeof(p3) << '\n';
  std::cout << "sizeof(int) *p3: " << sizeof(*p3) << '\n';

  class A {
  public:
    A() {};
    int valore = 0;
    void print() { std::cout << "this.valore = " << valore << '\n'; };
  };
  A objA = A();
  objA.valore = 5;
  objA.print();
  objA = {}; // resetta l'oggetto
  objA.print();

  t(5);

  std::vector<int> v1(5);    // size = 5, tutti elementi = 0
  std::vector<int> v2(5, 1); // size = 5, tutti elementi = 1
  std::vector<int> v3{5};    // v3[0] = 5

  int e = 3;
  u(e);

  double *p4 = new double(3.14);
  std::cout << "p4: " << p4 << '\n';
  std::cout << "*p4: " << *p4 << '\n';
  delete p4;
  std::cout << "p4 (dopo delete) : " << p4 << '\n';
  std::cout << "*p4 (dopo delete) : " << *p4 << '\n';

  int arr[5];
  std::cout << "Dimensione array: " << sizeof(arr) << '\n';
  dArr(arr);

  B b1(5, 42); // Costruttore con parametri
  B b2 = b1;   // Costruttore di copia
  B b3;        // Costruttore di default
  b3 = b1;     // Assegnamento di copia

  B b4 = std::move(b1); // Costruttore di spostamento
  B b5;
  b5 = std::move(b2); // Assegnamento di spostamento

  int* c1 = new int(6);
  int* c2 = new int(9);
  std::unique_ptr<int> p6 {c1};
  std::shared_ptr<int> p7 {c2};
  std::shared_ptr<int> p8 = p7;

  double x1 = 4.6789;
  int x2 = x1;
  std::cout << "x1: " << x1 << '\n';
  std::cout << "x2: " << x2 << '\n';
}

int foo(const int *x) { return 0; }
int goo(int *const x) { return 0; }
void t(int n) { int arrray[n]; }
void u(const int &x) {
  // x = 10; // dà errore, non posso modificarlo
  std::cout << "Posso solo leggere x: " << x << '\n';
}
void dArr(int arr[]) {
  std::cout << "Dimensione array passato alla funzione: " << sizeof(arr)
            << '\n';
}