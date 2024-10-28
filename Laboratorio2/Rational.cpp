#include "Rational.h"
#include <iostream>

// COSTRUTTORI
Rational::Rational() {
  num = 0;
  den = 1;
}
Rational::Rational(int n) {
  num = n;
  den = 1;
}
Rational::Rational(int n, int d) {
  // Controllo che il denominatore non sia uguale a zero, in caso lancio
  // un'eccezzione
  if (d == 0)
    throw Invalid();

  num = n;
  den = d;
}

int Rational::getDenominator() const { return den; };
int Rational::getNumerator() const { return num; };

// Converte il numero razionale in un double
double Rational::to_double() const { return (double)num / (double)den; }

// OVERLOAD DEGLI OPERATORI
Rational &Rational::operator=(const Rational &other) {
  num = other.num;
  den = other.den;

  return *this;
}

Rational Rational::operator+(const Rational &other) {
  return Rational((num * other.den + den * other.num), den * other.den);
}
// Operatore di somma con int
Rational Rational::operator+(int value) {
  return Rational(num + value * den, den);
}
void Rational::operator+=(const Rational &other) {
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

bool Rational::operator==(const Rational &other) {
  if (this->to_double() == other.to_double())
    return true;

  return false;
}
bool Rational::operator<(const Rational &other) {
  if (this->to_double() < other.to_double())
    return true;

  return false;
}
bool Rational::operator>(const Rational &other) {
  if (this->to_double() > other.to_double())
    return true;

  return false;
}

std::ostream &operator<<(std::ostream &os, Rational r) {
  return os << "(" << r.getNumerator() << "/" << r.getDenominator() << ")";
}