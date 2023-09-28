// Crie um programa que contenha um array de inteiros contendo 5 elementos. 
// Utilizando apenas aritmética de ponteiros, leia esse array do teclado e
// imprima o dobro de cada valor lido.

#include <iostream>

using namespace std;

int main() {
    int vet[5];
    int* pont = &vet[0];
    int x;

    for (int i = 0; i < 5; i++) {
        cout << "Digite o valor " << i << ": ";
        cin >> x;
        *(pont + i) = x; //ponteiro vai passando em cada posição
    }
    
     for (int i = 0; i < 5; i++) {
        cout << *(pont + i) * 2 << " ";
    }

    return 0;
}