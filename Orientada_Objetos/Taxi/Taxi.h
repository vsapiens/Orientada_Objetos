//
//  Taxi.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/20/18.
//  Copyright © 2018 Erick González. All rights reserved.
//



#ifndef Taxi_h
#define Taxi_h

#include "PersonaTaxi.h"

class Taxi
{
public:
    Taxi();
    
    Taxi(Persona, int);
    
    Persona getChofer () {return chofer;};
    int getIdent () {return ident;};
    
    void setChofer(Persona chofer) {this->chofer = chofer;};
    void setIdent(int ident){this->ident = ident;};
    
private:
    Persona chofer;
    int ident;
    
    
};

Taxi::Taxi()
{
    chofer.setNombre("No Asignado");
    chofer.setNumCel("0");
    ident = 0;
}
Taxi::Taxi(Persona chofer, int ident)
{
    this->ident = ident;
    this->chofer = chofer;
    
}
#endif /* Taxi_h */
