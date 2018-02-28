//
//  Autor.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Autor_h
#define Autor_h
class Autor
{
public:
    //Constructor Default
    Autor();
    
    //Constructor con parametros
    Autor(int idAutor, string nombre){this->idAutor =  idAutor;this->nombre = nombre;}
    
    //Metodos de Acceso
    int getIdAutor(){return idAutor;}
    string getNombre(){return nombre;}
    
    //Metodos de Modificacion
    void setIdAutor(int idAutor){this->idAutor =  idAutor;}
    void setNombre(string nombre){this->nombre = nombre;}
    
private:
    int idAutor;
    string nombre;
};
Autor::Autor()
{
    idAutor = 0;
    nombre = "-";
}
#endif /* Autor_h */
