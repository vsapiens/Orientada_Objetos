
#ifndef Polinomio_h
#define Polinomio_h

#include <iostream>
#include <stdio.h>
#include "Fraccion.h"
class Termino
{
public:
    
    Termino();
    Termino(Fraccion, char, int);
    
    void setTermino(Fraccion);
    void setVariable(char);
    void setExponente(int);
    
    Fraccion getTermino(){return coeficiente;};
    char getVariable(){return variable;};
    int getExponente(){return exponente;};

    void muestra();
    
private:
    Fraccion coeficiente;
    char variable;
    int exponente;
};

Termino::Termino()
{
    coeficiente.setDen(1);
    coeficiente.setNum(1);
    variable = 'x';
    exponente = 1;
    
}
Termino::Termino(Fraccion coeficiente, char variable, int exponente)
{
    this->coeficiente = coeficiente;
    this->variable = variable;
    this->exponente = exponente;
}

void Termino::setTermino(Fraccion coeficiente)
{
    this->coeficiente =  coeficiente;
}
void Termino::setVariable(char variable)
{
    this->variable = variable;
}
void Termino::setExponente(int exponente)
{
    this->exponente = exponente;
}

void Termino::muestra()
{
    if ((coeficiente.getNum() > 0 && coeficiente.getDen() < 0) || (coeficiente.getNum() < 0 && coeficiente.getDen() < 0))
    cout << -coeficiente.getNum() << "/" << -coeficiente.getDen();
    
    else cout << coeficiente.getNum()<<"/"<< coeficiente.getDen();
    
    cout<<variable;
    if(exponente != 1)
    {
    cout<<"^"<<exponente;
    }
}

#endif /* Polinomio_h */
