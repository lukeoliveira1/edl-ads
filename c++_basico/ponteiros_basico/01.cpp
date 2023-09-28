// Escreva um programa que declare um inteiro, um real e um char, e ponteiros
// para inteiro, real, e char. Associe as variáveis aos ponteiros (use &). 
// Modifique os valores de cada variável usando os ponteiros. Imprima os
// valores das variáveis antes e após a modificação.

#include <iostream>

using namespace std;

int main() {
    
    int a = 0;
    float b = 0;
    char c = '0';

    cout << "antes: " << endl;
    cout << a << ' ' << b << ' ' << c << endl;

    int* pont_a;
    float* pont_b;
    char* pont_c;

    // associando as variáveis aos ponteiros
    pont_a = &a;
    pont_b = &b;
    pont_c = &c;

    // modificando os valores de cada variável usando os ponteiros
    *pont_a = 1;
    *pont_b = 2;
    *pont_c = '3';

    cout << "depois: " << endl;
    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}