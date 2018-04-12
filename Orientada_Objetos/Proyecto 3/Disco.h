//
//  Disco.h
//  Orientada_Objetos
//
//  Created by Erick González on 4/12/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Disco_h
#define Disco_h
#include "Material.h"
class Disco:public Material
{
    Disco():duracion(0){};
    Disco(int dur):duracion(dur){};
    int getDuracion(){return duracion;};

    void setDuracion(int dur){duracion = dur;};
    void muestra();
    int cantidadDiasdePrestamo();
private:
    int duracion;
};


int Disco::cantidadDiasdePrestamo()
{
    return 3;
}
void Disco::muestra()
{
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"ID: "<<idMaterial<<endl;
    cout<<"Duracion "<<duracion<<endl;
    cout<<"Días de Préstamo: "<<cantidadDiasdePrestamo()<<endl;
    //Fecha de Fin de Reserva
}
#endif /* Disco_h */
