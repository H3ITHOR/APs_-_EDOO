#include <iostream>
#include <string>
using namespace std;

// Classe base: Product
class Product {
protected:
    long barcode;
    string name;
    double price;

public:
    Product(long barcode = 0, string name = "Unknown", double price = 0.0)
        : barcode(barcode), name(name), price(price) {}

    virtual ~Product() {} // Destrutor virtual

    // Métodos virtuais
    virtual void scanner() {
        cout << "Enter barcode: ";
        cin >> barcode;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void printer() const {
        cout << "Barcode: " << barcode << ", Name: " << name << ", Price: $" << price << endl;
    }

    double getPrice() const { return price; }
};

// Classe derivada: PrepackedFood
class PrepackedFood : public Product {
public:
    PrepackedFood(long barcode = 0, string name = "Unknown", double price = 0.0)
        : Product(barcode, name, price) {}

    void scanner() override {
        Product::scanner(); // Chama o scanner da classe base
    }

    void printer() const override {
        cout << "PrepackedFood - ";
        Product::printer(); // Chama o printer da classe base
    }
};

// Classe derivada: FreshFood
class FreshFood : public Product {
private:
    double weight;

public:
    FreshFood(long barcode = 0, string name = "Unknown", double price = 0.0, double weight = 0.0)
        : Product(barcode, name, price), weight(weight) {}

    void scanner() override {
        Product::scanner(); // Chama o scanner da classe base
        cout << "Enter weight (in kg): ";
        cin >> weight;
        price *= weight; // Calcula o preço total
    }

    void printer() const override {
        cout << "FreshFood - ";
        Product::printer(); // Chama o printer da classe base
        cout << "Weight: " << weight << " kg" << endl;
    }
};

// Função para registrar produtos
void record() {
    Product* products[100]; // Array de ponteiros para Product
    int count = 0; // Contador de produtos
    double total = 0.0; // Total da compra

    while (count < 100) {
        cout << "\nAdd a product (1: PrepackedFood, 2: FreshFood, 0: Finish): ";
        int choice;
        cin >> choice;

        if (choice == 0) break; // Finaliza o registro

        switch (choice) {
            case 1:
                products[count] = new PrepackedFood(); // Aloca memória para PrepackedFood
                break;
            case 2:
                products[count] = new FreshFood(); // Aloca memória para FreshFood
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
                continue;
        }

        products[count]->scanner(); // Escaneia o produto
        total += products[count]->getPrice(); // Adiciona ao total
        count++;
    }

    // Exibe a lista de produtos
    cout << "\n--- Purchased Products ---\n";
    for (int i = 0; i < count; i++) {
        products[i]->printer();
    }

    // Exibe o total da compra
    cout << "\nTotal: $" << total << endl;

    // Libera a memória alocada
    for (int i = 0; i < count; i++) {
        delete products[i];
    }
}

// Função principal
int main() {
    while (true) {
        cout << "\nNew customer? (1: Yes, 0: No): ";
        int choice;
        cin >> choice;

        if (choice == 0) break; // Finaliza o programa

        record(); // Registra os produtos do cliente
    }

    cout << "Program terminated. Goodbye!" << endl;
    return 0;
}