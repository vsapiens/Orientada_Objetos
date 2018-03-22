//
//  Chequera.h
//  Orientada_Objetos
//
//  Created by Erick González on 3/16/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Chequera_h
#define Chequera_h

class Chequera:public CtaBanc
{
    
public:
    Chequera();
    Chequera(int, double,double);
    void mostrar();
    void setComision(double comision){this-> comision = comision;};
    double getComision(){return comision;};
    bool retira(double);
    
private:
    double comision;
    
};
Chequera::Chequera():CtaBanc()
{
    comision = 20;
}
Chequera::Chequera(int n, double s,double comision):CtaBanc(n,s)
{
    this->comision = comision;
}
void Chequera::mostrar()
{
    cout<<endl;
    cout<<"Tu cuenta "<<numCuenta<< " tiene un saldo: "<<saldo<<endl;
    cout<<"comision "<< comision<<endl;
}
bool Chequera::retira(double cant)
{    if (saldo >= (cant+ comision))
{    saldo -= (cant+comision);
    return true;
}
else
    return false;
}
#endif /* Chequera_h */
