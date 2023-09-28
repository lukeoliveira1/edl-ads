// Escreva uma função que dado um número real passado como parâmetro,
// retorne à parte inteira e a parte fracionaria deste número. 

#include <iostream>

using namespace std;

void frac(float num, int* inteiro, float* frac) {
    *inteiro = num;
    *frac = num - *inteiro;
}

int main() {
    float num;
    int parte_int;
    float parte_frac;

    cout << "Digite um número float: " << endl;
    cin >> num;

    frac(num, &parte_int, &parte_frac); // passa o endereço pois a função recebe ponteiros
    cout << "Parte inteira: " << parte_int << endl;
    cout << "Parte fracionaria: " << parte_frac << endl;
    return 0;
}