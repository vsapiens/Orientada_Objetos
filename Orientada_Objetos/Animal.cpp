//
//  CuentaBanc.cpp
//  Orientada_Objetos
//
//  Created by Erick González on 1/26/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

#include "Perro.h"
#include "Gato.h"


int main()
{
    Animal *animales[3];
    animales[0] = new Gato("Silvestre",1947);
    animales[1] = new Perro("Fido",2000);
    animales[2] = new Gato("Tom",1940);
    
    for(int iCounter = 0; iCounter < 3; iCounter++)
    {
        animales[iCounter]->muestra();
        animales[iCounter]->habla();
    }
    return 0;
}
