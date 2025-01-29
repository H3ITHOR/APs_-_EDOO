#include "fraction.h"
#include <iostream>
#include <stdexcept>
#include <bits/stl_algo.h>

// Construtor para long
Fraction::Fraction(long num, long denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        std::cerr << "Erro: Denominador não pode ser zero." << std::endl;
        std::exit(1);
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    simplify();
}

// Construtor para int
Fraction::Fraction(int value) : numerator(value), denominator(1) {}

// Simplificação
void Fraction::simplify() {
    long gcd = std::__gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

// Operadores unários
Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

// Operadores de atribuição
Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    if (other.numerator == 0) {
        throw std::invalid_argument("Divisão por zero.");
    }
    numerator *= other.denominator;
    denominator *= other.numerator;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    simplify();
    return *this;
}

// Operadores binários
Fraction operator+(const Fraction& a, const Fraction& b) {
    Fraction result = a;
    result += b;
    return result;
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    Fraction result = a;
    result -= b;
    return result;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    Fraction result = a;
    result *= b;
    return result;
}

Fraction operator/(const Fraction& a, const Fraction& b) {
    Fraction result = a;
    result /= b;
    return result;
}

// Operadores de entrada/saída
std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.numerator << "/" << frac.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    std::cout << "Digite o numerador: ";
    in >> frac.numerator;
    std::cout << "Digite o denominador: ";
    in >> frac.denominator;
    if (frac.denominator == 0) {
        throw std::invalid_argument("Denominador não pode ser zero.");
    }
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }
    frac.simplify();
    return in;
}

// Conversão para double
Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

// Função principal para teste
int main() {
    Fraction a(3, 4), b(5, 6);
    int integer = 7;
    double result;

    // Converter int para fração
    Fraction c = integer;

    // Converter fração para double
    result = static_cast<double>(a);

    std::cout << "Fração a: " << a << std::endl;
    std::cout << "Fração b: " << b << std::endl;
    std::cout << "Inteiro convertido para fração (c): " << c << std::endl;
    std::cout << "Fração a convertida para double: " << result << std::endl;

    // Operações e atribuições
    Fraction d = a + b;
    std::cout << "a + b = " << d << std::endl;

    return 0;
}
