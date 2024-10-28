#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
  int num;
  int den;

public:
  class Invalid {};

  Rational();
  Rational(int n);
  Rational(int n, int d);

  int getDenominator() const;
  int getNumerator() const;
  double to_double() const;

  Rational &operator=(const Rational &other);

  Rational operator+(const Rational &other);
  Rational operator+(const int value);
  void operator+=(const Rational &other);

  Rational operator-(const Rational &other);
  void operator-=(const Rational &other);

  Rational operator*(const Rational &other);
  void operator*=(const Rational &other);

  Rational operator/(const Rational &other);
  void operator/=(const Rational &other);

  bool operator==(const Rational &other);
  bool operator>(const Rational &other);
  bool operator<(const Rational &other);

private:
};

#endif