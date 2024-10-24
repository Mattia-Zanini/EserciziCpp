#include "Rational.cpp"
#include <iostream>

int main() {
  Rational r1 = Rational(1, 2);
  Rational r2 = Rational(3, 2);

  std::cout << "R1: " << r1.to_double() << "\n";
  std::cout << "R2: " << r2.to_double() << "\n";

  r1 = r1 + r2;
  std::cout << "R1 = R1 + R2: " << r1.to_double() << "\n";

  Rational r3 = Rational(1, 2);
  std::cout << "R3: " << r3.to_double() << "\n";

  r3 += r2;
  std::cout << "R3 += R2: " << r3.to_double() << "\n";

  r3 /= r2;
  std::cout << "R3 /= R2: " << r3.to_double() << "\n";

  return 0;
}