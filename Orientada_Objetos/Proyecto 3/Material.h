//
//  Material.h
//  Orientada_Objetos
//
//  Created by Erick González on 4/10/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Material_h
#define Material_h
#include "Reserva.h"
class Material
{
public:
    Material():idMaterial(0),titulo(""){};
    Material(int idMat, string tit):titulo(tit),idMaterial(idMat){};
    void setIdMaterial(int idMat){idMaterial = idMat;};
    int getIdMaterial(){return idMaterial;};
    void setTitulo(string tit){titulo=tit;};
    string getTitulo(){return titulo;};
    
    virtual void muestra() = 0;
    virtual int cantidadDiasdePrestamo() = 0;
    bool bPrestado = false;
protected:
    int idMaterial;
    string titulo;
};

#endif /* Material_h */
