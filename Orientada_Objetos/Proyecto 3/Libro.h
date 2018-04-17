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
public:
    Libro():Autor(""),numPag(0){};
    Libro(int idMat, string tit, string Aut, int iNum):Material(idMat,tit),Autor(Aut),numPag(iNum){};
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
    cout<<"Tipo de Material: Libro"<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"ID: "<<idMaterial<<endl;
    cout<<"Número de Páginas: "<<numPag<<endl;
    cout<<"Autor: "<<Autor<<endl;
    cout<<"Días de Préstamo: "<<cantidadDiasdePrestamo()<<endl;
}
#endif /* Libro_h */
