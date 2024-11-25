#include <iostream>
#include <string>
using namespace std;

struct X {
  int val;
  void out(const string &s, int nv) {
    cerr << this << "->" << s << ": " << val << "(" << nv << ")\n";
  }

  X() {
    out("X()", 0);
    val = 0;
  }
  
  X(int v) {
    val = v;
    out("X(int)", v);
  }

  X(const X &x) {
    val = x.val;
    out("X(X&)", x.val);
  }

  X &operator=(const X &a) {
    out("X::operator=()", a.val);
    val = a.val;
    return *this;
  }

  ~X() { out("~X()", 0); }
};

X glob(2); // variabile globale
X copy(X a) { return a; }
X copy2(X a) {
  X aa = a;
  return aa;
}
X &ref_to(X &a) { return a; }
X *make(int i) {
  X a(i);
  return new X(a);
}
struct XX {
  X a;
  X b;
};
// segue

int main() {
  X loc{4};         // var locale
  X loc2{loc};      // costruttore di copia
  loc = X{5};       // assegnamento di copia
  loc2 = copy(loc); // call by value e return
  loc2 = copy2(loc);
  X loc3{6};
  X &r = ref_to(loc); // call by reference e return
  delete make(7);
  delete make(8);
  vector<X> v(4);
  XX loc4;
  X *p = new X{9};
  delete p;
  X *pp = new X[5];
  delete[] pp;
}