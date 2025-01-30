#include <iostream>
#include <string>
using namespace std;

// Classe base: Product
class Product {
protected:
    long barcode;
    string name;

public:
    // Construtor com valores padrão
    Product(long barcode = 0, string name = "Unknown") : barcode(barcode), name(name) {}

    // Métodos de acesso
    void setCode(long code) { barcode = code; }
    long getCode() const { return barcode; }

    // Métodos para leitura e exibição
    virtual void scanner() {
        cout << "Enter barcode: ";
        cin >> barcode;
        cout << "Enter product name: ";
        cin.ignore(); // Limpar o buffer
        getline(cin, name);
    }

    virtual void printer() const {
        cout << "Barcode: " << barcode << ", Name: " << name << endl;
    }
};

// Classe derivada: PrepackedFood
class PrepackedFood : Product {
private:
    double unitPrice;

public:
    // Construtor com valores padrão
    PrepackedFood(long barcode = 0, string name = "Unknown", double unitPrice = 0.0)
        : Product(barcode, name), unitPrice(unitPrice) {}

    // Métodos de acesso
    void setUnitPrice(double price) { unitPrice = price; }
    double getUnitPrice() const { return unitPrice; }

    // Redefinição dos métodos scanner() e printer()
    void scanner() override {
        Product::scanner(); // Chama o scanner da classe base
        cout << "Enter unit price: ";
        cin >> unitPrice;
    }

    void printer() const override {
        Product::printer(); // Chama o printer da classe base
        cout << "Unit Price: $" << unitPrice << endl;
    }
};

// Classe derivada: FreshFood
class FreshFood : public Product {
private:
    double weight;
    double pricePerKilo;

public:
    // Construtor com valores padrão
    FreshFood(long barcode = 0, string name = "Unknown", double weight = 0.0, double pricePerKilo = 0.0)
        : Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {}

    // Métodos de acesso
    void setWeight(double w) { weight = w; }
    double getWeight() const { return weight; }

    void setPricePerKilo(double price) { pricePerKilo = price; }
    double getPricePerKilo() const { return pricePerKilo; }

    // Redefinição dos métodos scanner() e printer()
    void scanner() override {
        Product::scanner(); // Chama o scanner da classe base
        cout << "Enter weight (in kg): ";
        cin >> weight;
        cout << "Enter price per kilo: ";
        cin >> pricePerKilo;
    }

    void printer() const override {
        Product::printer(); // Chama o printer da classe base
        cout << "Weight: " << weight << " kg, Price per Kilo: $" << pricePerKilo << endl;
        cout << "Total Price: $" << weight * pricePerKilo << endl;
    }
};

// Função principal para teste
int main() {
    // Testando a classe Product
    Product p1(123456, "Generic Product");
    Product p2;
    p2.scanner();

    // Testando a classe PrepackedFood
    PrepackedFood pf1(654321, "Chips", 2.99);
    PrepackedFood pf2;
    pf2.scanner();

    // Testando a classe FreshFood
    FreshFood ff1(987654, "Apples", 1.5, 3.49);
    FreshFood ff2;
    ff2.scanner();

    // Exibindo os produtos
    cout << "\n--- Product Details ---\n";
    p1.printer();
    p2.printer();

    cout << "\n--- Prepacked Food Details ---\n";
    pf1.printer();
    pf2.printer();

    cout << "\n--- Fresh Food Details ---\n";
    ff1.printer();
    ff2.printer();

    return 0;
}