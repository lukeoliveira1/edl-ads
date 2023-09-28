#include <iostream>

using namespace std;

#define pi 3.14; //variável global
#define print_end cout << "end!";

void print() { //função
    cout << "Hello!" << endl;
} 

int somar(int x, int y) {
// int somar(int &x, int &y) {
// com o & os valores de x e y irão alterar os valores de a e b no main()
    int soma;
    soma = x + y;
    x=30;
    return soma;
}

int main() {
    float mainpi = pi;

    print();

    int a=4, b=5;
    int res;
    res = somar(a, b);
    cout << res << endl;
    cout << "Valor de a: " << a << endl;

    // Vetor estático
    int array[5];
    // Alocação dinâmica de vetor
    int tamanho;
    cout << "Digite o tamanho: " << endl;
    cin >> tamanho;
    int* vetor = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o elemento " << i << " do vetor: " << endl;
        cin >> vetor[i];
    }
    
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    print_end;

    return 0;
}