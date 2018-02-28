//
//  Tema.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#ifndef Tema_h
#define Tema_h

class Tema
{
public:
    //Constructor Default
    Tema();
    
    //Constructor con parametros
    Tema(int idTema, string nombre, int idMateria){this-> idTema = idTema;this->idMateria = idMateria;this->nombre = nombre;}
    
    //Metodos de Modificacion
    void setIdMateria(int idMateria){this->idMateria = idMateria;}
    void setNombre(string nombre){this->nombre = nombre;}
    void setIdTema(int idTema){this-> idTema = idTema;}
    
    //Metodos de Acceso
    string getNombre(){return nombre;}
    int getIdMateria(){return idMateria;}
    int getIdTema(){return idTema;}

private:
    int idTema, idMateria;
    string nombre;
};
Tema::Tema()
{
    idTema = 0;
    idMateria = 0;
    nombre = "-";
}
#endif /* Tema_h */
