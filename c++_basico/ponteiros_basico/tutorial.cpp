#include <iostream>

using namespace std;

int main() {
    
    int a = 0;

    cout << "antes: " << a << endl;

    int* pont1;
    
    pont1 = &a; // associando a variável 'a' ao ponteiro
    
    *pont1 = 5; // modificando o valor de 'a' usando o ponteiro

    cout << "depois: " << a << endl;

    // ------------------------------------------------------------------------------------

    // ponteiro como variável: a vida útil desse objeto é controlada manualmente.

    //"espaço de memória" == variável sem nome

    int* pont3 = new int;  //criei um "espaço de memória" no ponteiro
    // MAS se apontar pra outra coisa vai perder o valor
    *pont3 = 35;

    cout << "valor pont3 antes de pegar o valor de pont1: " << *pont3 << endl;

    *pont3 = *pont1; // pegando o VALOR(usando *) de pont1, será 5

    // pont3 = pont1; // apontando para o ENDEREÇO de pont1, logo, o valor será 5 também
    // perdemos o "espaço de memória(35)" que tinha antes de pont3, VAZOU MEMÓRIA!

    //COMO NÃO VAZAR MEMÓRIA?
    // delete pont3; // deletando o "espaço de memória(35)" antes de apontar para algo
    // pont3 = pont1; 

    cout << "valor pont3 depois de pegar o valor de pont1: " << *pont3 << endl;

    return 0;
}