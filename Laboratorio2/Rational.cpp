#include <iostream>
#include <string>

class Rational {
  int num;
  int den;

public:
  // FARE LISTE INIZIALIZZAZIONE
  Rational() {
    num = 0;
    den = 1;
  };
  Rational(int n) {
    num = n;
    den = 1;
  };
  Rational(int n, int d) {
    num = n;
    den = d;
  }; // CONTROLLO CON DENOMINATORE A 0
  std::string to_string() const;
  double to_double() const { return (double)num / (double)den; };

  Rational operator+(const Rational &other);
  void operator+=(const Rational &other);

  Rational operator-(const Rational &other);
  void operator-=(const Rational &other);

  Rational operator*(const Rational &other);
  void operator*=(const Rational &other);

  Rational operator/(const Rational &other);
  void operator/=(const Rational &other);

private:
};

Rational Rational::operator+(const Rational &other) {
  return Rational((num * other.den + den * other.num), den * other.den);
}
void Rational::operator+=(const Rational &other) {
	/*
  std::cout << "THIS: " << to_string() << "\n";
  std::cout << "OTHER: " << other.to_string() << "\n";
	*/

  num = (num * other.den) + (other.num * den);
  den *= other.den;
}

Rational Rational::operator-(const Rational &other) {
  return Rational((num * other.den - den * other.num), den * other.den);
}
void Rational::operator-=(const Rational &other) {
  num = (num * other.den) - (other.num * den);
  den *= other.den;
}

Rational Rational::operator*(const Rational &other) {
  return Rational(num * other.num, den * other.den);
}
void Rational::operator*=(const Rational &other) {
  num *= other.num;
  den *= other.den;
}

Rational Rational::operator/(const Rational &other) {
  return Rational(num * other.den, den * other.num);
}
void Rational::operator/=(const Rational &other) {
  num *= other.den;
  den *= other.num;
}

std::string Rational::to_string() const {
  return std::string("Numeratore : " + std::to_string(num) +
                     "; Denominatore: " + std::to_string(den) +
                     "; Valore: " + std::to_string(to_double()));
}

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