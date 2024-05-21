#include <iostream>
#include <math.h>

using namespace std;

void frac(float num, int* inteiro, float* frac, float* mult10);

void one() {
    int arr[10];
    int x;

    for(int i=0;i<10;i++) {
        cin>>x;
        arr[i]=x;
    }

    for(int i=0;i<10;i++) {
        if(arr[i] % 2 != 0) {
            if(arr[i] > 12) {
                cout<<arr[i]<<" - "<<&arr[i]<<endl;
            }
        }
    }
}

void two(float num, int* inteiro, float* frac, float* mult10) {
    *inteiro = (int)num;
    *frac = num - *inteiro;

    *mult10 = num * 10;

    cout<<"parte inteira: "<<*inteiro<<endl;
    cout<<"parte fracionaria: "<<*frac<<endl;
    cout<<"multiplicado por 10: "<<*mult10<<endl;
}

void calc_hexa(float l, float *area, float *perimetro) {
    if (l > 0) {
        *area = (3 * pow(l, 2) * sqrt(3)) / 2;
        *perimetro = 6 * l;

        cout<<"área do hexágono: "<<*area<<endl;
        cout<<"perímetro: "<<*perimetro<<endl;
    } else {
        cout<<"programa finalizado por entrada negativa";
    }
}

int main()
{
    //ONE
    cout<<"Questao 1"<<endl;
    one();

    //TWO
    cout<<"\n\nQuestao 2"<<endl;
    float num;
    cin>>num;
    int inteiro;
    float frac;
    float mult10;

    two(num, &inteiro, &frac, &mult10);

    //THREE
    cout<<"\n\nQuestao 3"<<endl;
    float valorLado;
    cin>>valorLado;
    float area, perimetro;

    calc_hexa(valorLado, &area, &perimetro);

    return 0;
}
