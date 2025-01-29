#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    long numerator;
    long denominator;

    void simplify(); // Simplifica a fração

public:
    // Construtores
    Fraction(long num = 0, long denom = 1);
    Fraction(int value); // Novo construtor para int

    // Operadores unários
    Fraction operator-() const;
    Fraction& operator++(); // Prefixo
    Fraction& operator--(); // Prefixo

    // Operadores de atribuição
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

    // Conversões
    explicit operator double() const; // Conversão para double
};

#endif
