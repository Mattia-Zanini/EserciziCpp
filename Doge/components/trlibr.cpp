#include <string>
using namespace std;
class Library {
public:
  Library() {}
  string getLb(string d); // Declaration of function
  void setLb(string d, string c);

private:
  string lbCpp;
  string lbDoge;
};
// Defining of function
string Library::getLb(string d) { return lbCpp; }
void Library::setLb(string d, string c) {
  this->lbCpp = c;
  this->lbDoge = d;
};

class LibrariesTr {
public:
  LibrariesTr() {
    set(0, "input", "<iostream>");
    set(1, "file", "<fstream>");
  }

private:
  Library l[2];
  void set(int pos, string d, string c);
};
void LibrariesTr::set(int pos, string d, string c) {
  Library tmp;
  tmp.setLb(d, c);
  this->l[pos] = tmp;
};