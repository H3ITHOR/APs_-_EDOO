#include <iostream>
#include <ctime>
using namespace std;


int main() {

    int qtd_try = 3;
    int nbr_chosen;
    time_t now = time(0);
    long long int seed = static_cast<long long int>(now);
    srand(seed);
    int rand_number = rand() % 15 + 1;

    cout << "escolha um numero de 1 a 15: ";
    for (int i = 0; i < 3; i++){
        if(qtd_try > 0){
            cin >> nbr_chosen;
            cout << "\n";
            if (nbr_chosen == rand_number){
                cout << "PARABENS, VOCÊ ACERTOU O NUMERO!" << endl;
            } else{
                qtd_try--;
                if(qtd_try > 0){
                    cout <<"Tente novamente: ";
                }
            }
        }
    }

    return 0;
}