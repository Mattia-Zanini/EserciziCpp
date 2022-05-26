#include "components/startup.cpp"

// using namespace logs;
//  using namespace console;
// using namespace extension;

int main(int argc, char *argv[]) {
  cout << "Compiler startup..." << endl;
  if (argc != 2) {
    console::error("Insufficient number of arguments.", 1);
    return -1;
  }
  Startup start(argv[1]);
  return 0;
}