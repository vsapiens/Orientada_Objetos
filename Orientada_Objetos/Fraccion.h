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
    friend bool operator>(Fraccion, Fraccion);
    friend Fraccion operator+(Fraccion,Fraccion);
    friend Fraccion operator+(Fraccion,int);
    friend Fraccion operator+(int,Fraccion);
    friend Fraccion operator++(Fraccion);
    friend void operator+=(Fraccion,Fraccion);
    
public:
    Fraccion operator * (Fraccion);
    Fraccion operator-(int);
    Fraccion operator-(Fraccion);
    bool operator >(Fraccion);
    Fraccion operator+(Fraccion);
    Fraccion operator+(int);
    Fraccion operator--();
    
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
    Fraccion res;
    res.setDen(f1.getDen()*f2.getNum() + f2.getDen()*f1.getNum());
    res.setNum(f1.getDen()*f2.getDen());
    return res;
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
Fraccion operator+(Fraccion f, int e)
{
    Fraccion f2(e,1);
    Fraccion res;
    res.setDen(f.getNum()*e + f.getDen());
    res.setNum(f.getNum());
    return res;
}
/** Fraccion operator+(int e, Fraccion f1)
{
    return f1 + e;
}
Fraccion operator++(Fraccion &f)
{
    f =  f + 1;
    return f;
}

Fraccion Fraccion::operator++(Fraccion &f)
{
    f = f + 1;
    return f;
}
Fraccion Fraccion::operator--()
{
    *this =  *this + -1;
    return
}
Fraccion Fraccion :: operator+(Fraccion)
{
    
}
Fraccion Fraccion :: operator+(int e)
{
    
}
bool Fraccion :: operator >(Fraccion f)
{
    return this->calcValorReal()< f.calcValorReal();
}

void operator += (Fraccion &f1, Fraccion &f2)
{
    f1 = f1 + f2;
}
 */
#endif /* Fraccion_h */
