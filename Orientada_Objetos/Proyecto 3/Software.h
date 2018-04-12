//
//  Software.h
//  Orientada_Objetos
//
//  Created by Erick González on 4/12/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Software_h
#define Software_h
#include "Material.h"
class Software:public Material
{
    Software():sistemaOper(""){};
    Software(string Soft):sistemaOper(Soft){};
    string getSoftware(){return sistemaOper;};
    
    void setSoftware(string Soft){sistemaOper = Soft;};
    void muestra();
    int cantidadDiasdePrestamo();
private:
    string sistemaOper;
};

int Software::cantidadDiasdePrestamo()
{
    return 1;
}
void Software::muestra()
{
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"ID: "<<idMaterial<<endl;
    cout<<"Sistema Operativo: "<<sistemaOper<<endl;
    cout<<"Días de Préstamo: "<<cantidadDiasdePrestamo()<<endl;
}
#endif /* Software_h */
