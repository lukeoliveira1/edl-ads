// Crie um programa que contenha uma função que permita passar por parâmetro
// dois números inteiros A e B. A função deverá calcular a soma entre estes dois
// números e armazenar o resultado na variável A. Esta função não deverá possuir 
// retorno, mas deverá modificar o valor do primeiro parâmetro. Imprima os valores
// de A e B na função ao principal.
#include <iostream>

using namespace std;

void somar(int &x, int y) {
    // (&x) modificando o valor de a no main()
    int soma;
    soma = x + y;
    x = soma;
}

int main() {
    int a=4, b=5;
    somar(a, b);
    cout << "'a' recebe o resultado da soma por conta do (&x) na função: " << a; 
    return 0;
}