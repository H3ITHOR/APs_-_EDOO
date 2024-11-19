#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // Obtendo a semente com o tempo atual em milissegundos
    time_t now = time(0);  // Tempo atual em segundos
    long long int seed = static_cast<long long>(now) * 1000;  // Convertendo para milissegundos

    // Inicializando o gerador de números aleatórios com a semente
    srand(static_cast<unsigned int>(seed));

    // Gerando e exibindo 20 números aleatórios
    for (int i = 0; i < 20; i++) {
        int randNumber = rand() % 100 + 1;
        cout << randNumber << endl;
    }

    return 0;
}
