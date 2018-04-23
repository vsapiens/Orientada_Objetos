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
    Fecha getFechaReservacion(){return fechaReservacion;};
    
    void setIdMaterial(int idM){idMaterial = idM;};
    void setIdCliente(int idC){idCliente = idC;};
    void setFechaReservacion(Fecha Res){fechaReservacion = Res;};
    Fecha calculaFechaFinReserva(int);
private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva():fechaReservacion(),idMaterial(0),idCliente(0){};

Reserva::Reserva(int idM, int idC, Fecha f1):fechaReservacion(f1),idMaterial(idM),idCliente(idC){};

Fecha Reserva::calculaFechaFinReserva(int iDias)
{
    return fechaReservacion + iDias;
}

#endif /* Reserva_h */
