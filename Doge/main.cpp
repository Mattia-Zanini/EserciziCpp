#include "components/startup.cpp"
#include <sys/wait.h>

// using namespace logs;
//  using namespace console;
// using namespace extension;

int ErrorsCheck(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  cout << "Compiler startup..." << endl;
  int err = ErrorsCheck(argc, argv);
  if (err != 0) {
    return err;
  }
  Startup start(argv[1]);
  cout << "Compiled with success" << endl;
  return 0;
}

int ErrorsCheck(int argc, char *argv[]) {
  // I check that there is an argument
  if (argc != 2) {
    console::error("Insufficient number of arguments.", 1);
    logs::Log("Error while compiling, error code: 1; insufficient number of "
              "arguments.");
    return -1;
  }
  // I check that exist the file passed by argument
  if (access(argv[1], F_OK) != 0) {
    console::error("File not found.", 2);
    logs::Log("Error while compiling, error code: 2; input file not found.");
    return -1;
  }
  // check the file extension
  if (extension::GoodExtension(argv[1]) == -1) {
    console::error("Bad extension.", 3);
    logs::Log("Error while compiling, error code: 3; input file haven't the "
              "right extension.");
    return -1;
  }
  return 0;
}