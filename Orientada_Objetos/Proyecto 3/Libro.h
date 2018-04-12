//
//  Libro.h
//  Orientada_Objetos
//
//  Created by Erick González on 4/12/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Libro_h
#define Libro_h

#include "Material.h"
class Libro:public Material
{
    Libro():Autor(""),numPag(0){};
    Libro(string Aut, int iNum):Autor(Aut),numPag(iNum){};
    int getNumPag(){return numPag;};
    string getAutor(){return Autor;};
    
    void setNumPag(int iNum){numPag = iNum;};
    void setAutor(string Aut){Autor= Aut;};
    void muestra();
    int cantidadDiasdePrestamo();
private:
    string Autor;
    int numPag;
};

int Libro::cantidadDiasdePrestamo()
{
    return 10;
}
void Libro::muestra()
{
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"ID: "<<idMaterial<<endl;
    cout<<"Número de Páginas: "<<numPag<<endl;
    cout<<"Autor: "<<Autor<<endl;
    cout<<"Días de Préstamo: "<<cantidadDiasdePrestamo()<<endl;
}
#endif /* Libro_h */
