// Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o endereço de cada posição dessa matriz.
#include <iostream>

using namespace std;

int main() {
    int mat[3][3] = {{0, 1, 2}, {3, 4 ,5}, {6, 7, 8}};

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            cout << &mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}