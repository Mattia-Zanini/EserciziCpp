#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
  int num;
  int den;

public:
  Rational();
  Rational(int n);
  Rational(int n, int d);
  double to_double();

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

#endif