//
//  Reserva.h
//  Orientada_Objetos
//
//  Created by Erick González on 4/12/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h
#include "Fecha.h"
class Reserva
{
public:
    Reserva();
    Reserva(int, int, Fecha);
    int getIdMaterial(){return idMaterial;};
    int getIdCliente(){return idCliente;};
    Fecha getReservacion(){return Reservacion;};
    
    void setIdMaterial(int idM){idMaterial = idM;};
    void setIdCliente(int idC){idCliente = idC;};
    void setReservacion(Fecha Res){Reservacion = Res;};
    Fecha calculaFechaFinReserva(int);
private:
    int idMaterial, idCliente;
    Fecha Reservacion;
};

Reserva::Reserva(): Reservacion(),idMaterial(0),idCliente(0){};
Reserva::Reserva(int idM, int idC, Fecha f1):Reservacion(f1),idMaterial(idM),idCliente(idC){};
Fecha Reserva::calculaFechaFinReserva(int iDias)
{
    return Reservacion + iDias;
}

#endif /* Reserva_h */
