#include <iostream>
using namespace std;

#include "Fraccion.h"


void displayFraction(Fraccion fF1)
{
    cout<<"El valor de la fraccion ";
    fF1.muestra();
    cout<<" es "<< fF1.calculaValorReal()<<endl;
}
int main()
{
    Fraccion fF1;
    Fraccion fF2(3,4);
    displayFraction(fF1);
    displayFraction(fF2);
    return 0;
}
