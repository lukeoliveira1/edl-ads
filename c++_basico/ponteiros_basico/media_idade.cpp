// Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o endereço de cada posição dessa matriz.
// Média de idades só usando ponteiros

#include <iostream>

using namespace std;

int main() {
    int* idade1 = new int;
    int* idade2 = new int;
    cout << "Qual a idade?" << endl;
    cin >> *idade1;
    cout << "Qual a idade?" << endl;
    cin >> *idade2;

    float *media = new float;
    *media = (*idade1 + *idade2) / 2;
    
    cout << "A média das idades é: " << *media << endl;

    return 0;
}