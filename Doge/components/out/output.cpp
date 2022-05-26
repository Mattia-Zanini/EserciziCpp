#include <fstream>
#include <iostream>

using namespace std;

namespace logs {
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
  // for more information about date/time format
  strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

  return buf;
}
int Log(string message) {
  ofstream logrow("logs_file.log", ios_base::app | ios_base::out);
  logrow << "[" << currentDateTime() << "] " << message << endl;
  logrow.close();
  return 0;
}
} // namespace logs
namespace console {
void ChangeTextColor(int id) {
  switch (id) {
  case -1:
    printf("\033[0m"); // DEFAULT COLOR
    break;
  case 0:
    printf("\033[0;30m"); // BLACK
    break;
  case 1:
    printf("\033[1;31m"); // RED
    break;
  case 2:
    printf("\033[0;32m"); // GREEN
    break;
  case 3:
    printf("\033[0;33m"); // YELLOW
    break;
  case 4:
    printf("\033[0;34m"); // BLUE
    break;
  case 5:
    printf("\033[0;35m"); // PURPLE
    break;
  case 6:
    printf("\033[0;36m"); // CYAN
    break;
  case 7:
    printf("\033[0;37m"); // WHITE
    break;
  }
}
void write(int txtColor1, string txt1, int txtColor2, string txt2) {
  ChangeTextColor(txtColor1);
  cout << txt1;
  ChangeTextColor(txtColor2);
  cout << txt2 << endl;
  // reset console color
  ChangeTextColor(-1);
}
void error(string txt1, int error) {
  ChangeTextColor(1);
  cout << "ERROR [" << error << "] ";
  ChangeTextColor(-1);
  cout << txt1 << endl;
}
void warn(string txt1) {
  ChangeTextColor(3);
  cout << "WARN ";
  ChangeTextColor(-1);
  cout << txt1 << endl;
}
} // namespace console
namespace extension {
// check the file extension, which must be .dg
int GoodExtension(string filename) {
  int length = filename.size();
  if (filename[length - 2] == 'd' && filename[length - 1] == 'g') {
    return 0; // good extension
  }
  return -1; // bad extension
}
} // namespace extension