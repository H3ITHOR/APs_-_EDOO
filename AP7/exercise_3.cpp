#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Classe de exceção interna
    class DivError : public exception {
    public:
        const char* what() const noexcept override {
            return "Division by zero error!";
        }
    };

    // Construtor
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw DivError(); // Lança exceção se o denominador for zero
        }
        numerator = num;
        denominator = denom;
    }

    // Operador de divisão
    Fraction operator/(const Fraction& other) const {
        int newNum = numerator * other.denominator;
        int newDenom = denominator * other.numerator;
        if (newDenom == 0) {
            throw DivError(); // Lança exceção se o denominador resultante for zero
        }
        return Fraction(newNum, newDenom);
    }

    // Operador de leitura (>>)
    friend istream& operator>>(istream& in, Fraction& frac) {
        cout << "Enter numerator: ";
        in >> frac.numerator;
        cout << "Enter denominator: ";
        in >> frac.denominator;
        if (frac.denominator == 0) {
            throw DivError(); // Lança exceção se o denominador for zero
        }
        return in;
    }

    // Método para exibir a fração
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    // Bloco 1: Testando o construtor
    try {
        Fraction f1(1, 2); // Válido
        Fraction f2(0, 1); // Válido
        Fraction f3(1, 0); // Lança exceção
    } catch (const Fraction::DivError& e) {
        cout << "Error in constructor: " << e.what() << endl;
    }

    // Bloco 2: Testando divisão por zero
    try {
        Fraction f1(1, 2);
        Fraction f2(0, 1);
        Fraction f3 = f1 / f2; // Lança exceção (divisão por zero)
    } catch (const Fraction::DivError& e) {
        cout << "Error in division: " << e.what() << endl;
    }

    // Bloco 3: Testando leitura de denominador zero
    try {
        Fraction f;
        cin >> f; // Tenta ler uma fração
        f.print();
    } catch (const Fraction::DivError& e) {
        cout << "Error in input: " << e.what() << endl;
        cout << "New denominator != 0: ";
        int newDenom;
        cin >> newDenom;
        if (newDenom == 0) {
            cout << "Program terminated: Denominator cannot be zero!" << endl;
            return 1; // Termina o programa
        }
        Fraction f(1, newDenom); // Cria uma fração com o novo denominador
        f.print();
    }

    return 0;
}