#include <iostream>
#include <string>
using namespace std;

// Classe base: Product
class Product {
protected:
    long barcode;
    string name;

public:
    Product(long barcode = 0, string name = "Unknown") : barcode(barcode), name(name) {}

    long getBarcode() const { return barcode; }

    virtual void printer() const {
        cout << "Product - Barcode: " << barcode << ", Name: " << name << endl;
    }
};

// Classe derivada: PrepackedFood
class PrepackedFood : public Product {
private:
    double unitPrice;

public:
    PrepackedFood(long barcode = 0, string name = "Unknown", double unitPrice = 0.0)
        : Product(barcode, name), unitPrice(unitPrice) {}

    void printer() const override {
        cout << "PrepackedFood - Barcode: " << barcode << ", Name: " << name
             << ", Unit Price: $" << unitPrice << endl;
    }
};

// Classe derivada: FreshFood
class FreshFood : public Product {
private:
    double weight;
    double pricePerKilo;

public:
    FreshFood(long barcode = 0, string name = "Unknown", double weight = 0.0, double pricePerKilo = 0.0)
        : Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {}

    void printer() const override {
        cout << "FreshFood - Barcode: " << barcode << ", Name: " << name
             << ", Weight: " << weight << " kg, Price per Kilo: $" << pricePerKilo << endl;
    }
};

// Função global para comparar códigos de barras
Product& isLowerCode(Product& p1, Product& p2) {
    return (p1.getBarcode() < p2.getBarcode()) ? p1 : p2;
}

int main() {
    // Array de ponteiros para Product
    Product* products[3];

    // Criando objetos dinamicamente
    products[0] = new Product(123456, "Generic Product");
    products[1] = new PrepackedFood(654321, "Chips", 2.99);
    products[2] = new FreshFood(987654, "Apples", 1.5, 3.49);

    // Ponteiro para FreshFood
    FreshFood* freshFoodPtr = new FreshFood(111111, "Bananas", 2.0, 1.49);

    // Chamando printer() para todos os objetos
    cout << "--- Printer() without casting ---\n";
    for (int i = 0; i < 3; i++) {
        products[i]->printer(); // Qual versão de printer() é chamada?
    }
    freshFoodPtr->printer();

    // Downcasting para chamar a versão correta de printer()
    cout << "\n--- Printer() with downcasting ---\n";
    for (int i = 0; i < 3; i++) {
        if (PrepackedFood* pf = dynamic_cast<PrepackedFood*>(products[i])) {
            pf->printer(); // Chama PrepackedFood::printer()
        } else if (FreshFood* ff = dynamic_cast<FreshFood*>(products[i])) {
            ff->printer(); // Chama FreshFood::printer()
        } else {
            products[i]->printer(); // Chama Product::printer()
        }
    }

    // Upcasting: Chamando a versão da classe base (Product) a partir de FreshFood
    cout << "\n--- Upcasting: Calling Product::printer() from FreshFood ---\n";
    Product* productPtr = freshFoodPtr; // Upcasting implícito
    productPtr->printer(); // Chama Product::printer()

    // Testando a função isLowerCode()
    cout << "\n--- Testing isLowerCode() ---\n";
    Product& lower1 = isLowerCode(*products[0], *products[1]);
    cout << "Product with lower barcode: ";
    lower1.printer();

    Product& lower2 = isLowerCode(*products[1], *freshFoodPtr);
    cout << "Product with lower barcode: ";
    lower2.printer();

    // Liberando memória
    for (int i = 0; i < 3; i++) {
        delete products[i];
    }
    delete freshFoodPtr;

    return 0;
}