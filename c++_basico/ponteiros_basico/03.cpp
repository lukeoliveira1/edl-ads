// Crie um programa que contenha um array de float contendo 10 elementos.
// Imprima o endereço de cada posição desse array.
#include <iostream>

using namespace std;

int main() {
    int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i=0; i < 10; i++) {
        cout << &vet[i] << " ";
    }
    
    return 0;
}