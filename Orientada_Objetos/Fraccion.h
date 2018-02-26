//
//  Fraccion.h
//  Orientada_Objetos
//
//  Created by Erick González on 1/23/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Fraccion_h
#define Fraccion_h
class Fraccion
{
    friend Fraccion operator+(Fraccion , Fraccion);
    friend bool operator >(Fraccion, Fraccion);
    friend Fraccion operator+(Fraccion , int);
    friend Fraccion operator ++(Fraccion);
    
public:
    Fraccion operator * (Fraccion);
    Fraccion operator - ();
    Fraccion operator-(Fraccion);
    
    Fraccion();
    Fraccion(int, int);
    
    void setNum(int);
    void setDen(int);
    
    int getNum();
    int getDen();
    
    double calcValorReal();
    void muestra();
    
private:
    int num, den;
};

Fraccion::Fraccion()
{
    num = 1;
    den = 1;
}
Fraccion::Fraccion(int iNumerator, int iDenominator)
{
    num = iNumerator;
    den = iDenominator;
}

void Fraccion::setNum(int iNumerator)
{
    num = iNumerator;
}
void Fraccion::setDen(int iDenominator)
{
    den = iDenominator;
}
int Fraccion::getDen()
{
    return den;
}
int Fraccion::getNum()
{
    return num;
}
double Fraccion::calcValorReal()
{
    return (double) num/den;
}
void Fraccion::muestra()
{
    cout << num<<"/"<< den;
}
Fraccion operator+(Fraccion f1, Fraccion f2)
{
    Fraccion f3(f1.getDen()*f2.getNum() + f2.getDen()*f1.getNum(),f1.getDen()*f2.getDen());
    return f3;
}
Fraccion Fraccion:: operator * (Fraccion f1)
{
    Fraccion f(this->num*f1.getNum(),this->den*f1.getDen());
    return f;
}
bool operator > (Fraccion f1, Fraccion f2)
{
    return f1.calcValorReal() > f2.calcValorReal();
}
Fraccion operator+(Fraccion f1, int e)
{
    Fraccion f(e,1);
    
    return f1 + f;
}
Fraccion operator++(Fraccion &f)
{
    f = f + 1;
    return f;
}
#endif /* Fraccion_h */
