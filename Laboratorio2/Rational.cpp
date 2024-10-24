#include "Rational.h"

Rational::Rational() {
  num = 0;
  den = 1;
}
Rational::Rational(int n) {
  num = n;
  den = 1;
}
Rational::Rational(int n, int d) {
  num = n;
  den = d;
}

double Rational::to_double() { return (double)num / (double)den; }

Rational Rational::operator+(const Rational &other) {
  return Rational((num * other.den + den * other.num), den * other.den);
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