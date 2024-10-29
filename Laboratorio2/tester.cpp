#include "Rational.cpp"
#include <iostream>

int main() {
  Rational r1 = Rational(1, 3);
  Rational r2 = Rational {3, 6};

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

  r3 = r2;
  std::cout << "R3 = R2: " << r3.to_double() << "\n";

  Rational r4 = Rational(7, 8);
  std::cout << "R4: " << r4 << '\n';
  std::cout << "R4 == R2: " << (r4 == r2) << "\n";

  Rational r5 = Rational(2, 9);
  std::cout << "R5: " << r5 << '\n';
  Rational r6 = r5;
  std::cout << "R6: " << r6 << '\n';

  std::cout << "R5 > R4: " << (r5 > r4) << "\n";
  std::cout << "R5 < R4: " << (r5 < r4) << "\n";

  Rational r7 = Rational();
  r7 = r7 + 8;
  std::cout << "R7: " << r7 << '\n';

  // Da ovviamente errore perchè non esiste l'overloading degli interi per un ogetto Rational
  // Rational r8 = 5 + r7;

  return 0;
}