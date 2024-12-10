#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    long numerator;
    long denominator;

    void simplify();

public:
    Fraction(long num = 0, long denom = 1);

    Fraction operator-() const;
    Fraction& operator++();
    Fraction& operator--();

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    // Operadores binários (amigos)
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);

    // Operadores de entrada/saída
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
};

#endif
