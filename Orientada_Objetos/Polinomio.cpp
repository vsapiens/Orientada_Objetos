#include <iostream>
#include <cmath>

using namespace std;

#include "Polinomio.h"

int iNumber;
double dVariable;
char cLetter;

void getNumber()
{
    cout<<"¿Cuantos terminos tiene tu polinomio?\n";
    cin>>iNumber;
    while(iNumber <= 0)
    {
        cout<<"Teclea un numero valido"<<endl;
        cin.ignore();
        cin>>iNumber;
    }
}

void getCharacter()
{
    cin.ignore();
    cout<<"Teclea la letra que usaras para la variable del polinomio\n";
    cin>> cLetter;
}
void getVariable()
{
    cout<<"Para evaluar el polinomio, teclea el valor de la variable\n";
    cin>>dVariable;
}
void makePolinomio(Termino Polinomio[8])
{
    int iNum = 0, iDen = 0, iExp= 0;
    for(int iCounter = 0; iCounter < iNumber; iCounter++)
    {
        Polinomio[iNumber].setVariable(cLetter);
        cout<<"Teclea el numerador del coeficiente del termino "<< iCounter<<endl;
        cin>>iNum;
        cout<<"Teclea el denominador del coeficiente del termino "<< iCounter<<endl;
        cin>>iDen;
        Fraccion Coeficiente(iNum,iDen);
        Polinomio[iCounter].setTermino(Coeficiente);
        cout<<"Teclea el exponente del termino " << iCounter<<endl;
        cin>>iExp;
        while(iExp <= 0)
        {
        cout<<"Teclea otro exponente para el termino " << iCounter <<endl;
        cin.ignore();
        cin>>iExp;
        }
        Polinomio[iCounter].setExponente(iExp);
    }
    
}
void displayPolinomio(Termino Polinomio[8])
{
    Fraccion Signo;
    cout<< "El polinomio es: ";
    
    Signo = Polinomio[0].getTermino();
    
    if(Signo.calcValorReal() >= 0)
    {
        cout<<" +";
        Polinomio[0].muestra();
    }
    for(int iCounter = 1; iCounter < iNumber; iCounter++)
    {
        Polinomio[iCounter].muestra();
        
        Signo = Polinomio[iCounter+1].getTermino();
        if(Signo.calcValorReal() >= 0 && iCounter != iNumber-1)
        {
            cout<<" + ";
        }
    }
    cout<<endl;
}
void calculatePolinomio(Termino Polinomio[8], double dVariable)
{
    double iResult = 0;
    for(int iCounter = 0; iCounter < iNumber; iCounter++)
    {
        Fraccion Resultado;
        Resultado = Polinomio[iCounter].getTermino();
        
        /**
         double Exponent;
        Exponent = (double) Polinomio[iCounter].getExponente();
        */
        iResult += (double) Resultado.calcValorReal()*(pow(dVariable,Polinomio[iCounter].getExponente()));
    }
    cout<< "El valor del polinomio es: " <<iResult <<endl;
}

int main()
{
    getNumber();
    Termino Polinomio[8];
    getCharacter();
    makePolinomio(Polinomio);
    displayPolinomio(Polinomio);
    getVariable();
    calculatePolinomio(Polinomio, dVariable);
    return 0;
}
