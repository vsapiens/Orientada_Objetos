//
//  Gato.h
//  Orientada_Objetos
//
//  Created by Erick González on 3/23/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Gato_h
#define Gato_h
#include "Animal.h"
class Gato: public Animal
{
public:
    Gato(string, int );
    void habla();            //Nota    que    son    funciones    virtual    pura.
    void muestra();
    
};

Gato::Gato(string sNom, int iANac):Animal(sNom,iANac)
{
}
void Gato::habla()
{
    cout<<"MIAU"<<endl;
}
void Gato::muestra()
{
    cout<<"Soy el gato "<< sNombre << " y tengo "<< calculaEdad() << " años"<<endl;
}


#endif /* Gato_h */
