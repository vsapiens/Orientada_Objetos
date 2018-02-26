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
    Autor();
    Autor(int idAutor, string nombre){this->idAutor =  idAutor;this->nombre = nombre;};
    int getIdAutor(){return idAutor;};
    string getNombre(){return nombre;};
    
    void setIdAutor(int idAutor){this->idAutor =  idAutor;};
    void setNombre(string nombre){this->nombre = nombre;};
    
private:
    int idAutor;
    string nombre;
};
Autor::Autor()
{
    idAutor = 0000;
    nombre = "No Definido";
}
#endif /* Autor_h */
