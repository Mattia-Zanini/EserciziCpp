#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
  std::map<std::string, int> words;
  int i = 0;

  // Declaring string
  std::string init_string = "ciao ciao ciao palle palle c++ c++ c++ c++ dio";
  // Converting to stringstream object
  std::stringstream ss(init_string);

  for (std::string s; ss >> s;)
    ++words[s];

  for (const auto &p : words)
    std::cout << p.first << ": " << p.second << '\n';
  return 0;
}