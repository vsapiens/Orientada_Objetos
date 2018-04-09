//
//  Perro.h
//  Orientada_Objetos
//
//  Created by Erick González on 3/23/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Perro_h
#define Perro_h
#include "Animal.h"
class Perro: public Animal
{
public:
    Perro(string, int);
    void habla();
    void muestra();
    
};

Perro::Perro(string sNom, int iANac):Animal(sNom,iANac)
{
}
void Perro::habla()
{
    cout<<"GUAU"<<endl;
}
void Perro::muestra()
{
    cout<<"Soy el perro "<< sNombre << " y tengo "<< calculaEdad()<< " años"<<endl;
}

#endif /* Perro_h */
