//
//  Materia.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Materia_h
#define Materia_h

class Materia
{
public:
    Materia();
    Materia(int idMateria, string nombre){this->idMateria = idMateria;this->nombre = nombre;};
    
    int getIdMateria(){return idMateria;};
    string getNombre(){return nombre;};
    
    void setIdMateria(int idMateria){this->idMateria = idMateria;};
    void setNombre(string nombre){this->nombre = nombre;};
    
private:
    int idMateria;
    string nombre;
};

Materia::Materia()
{
    idMateria = 0000;
    nombre = "No definido";
}
#endif /* Materia_h */
