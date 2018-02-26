//
//  Tema.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include "Materia.h"
#ifndef Tema_h
#define Tema_h

class Tema
{
public:
    Tema();
    Tema(Materia mat, string nombre){this->mat = mat;this->nombre = nombre;};
    
    void setMateria(Materia mat){this->mat = mat;};
    void setNombre(string nombre){this->nombre = nombre;};
    
    string getNombre(){return nombre;};
    Materia getMateria(){return mat;};
    
private:
    Materia mat;
    string nombre;
};
Tema::Tema()
{
    Materia(0000, "No Definida");
    nombre = "No definido";
}
#endif /* Tema_h */
