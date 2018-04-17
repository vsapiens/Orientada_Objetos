//
//  EjemploVideo.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include "Tema.h"
#include "Fecha2.h"
#include "Autor.h"
#include "Materia.h"

#ifndef EjemploVideo_h
#define EjemploVideo_h

class EjemploVideo
{
    
public:
    //Constructor Default
    EjemploVideo();
    
    //Metodos de Acceso
    int getIdVideo(){return idVideo;}
    int getCantidadAutores(){return cantidadAutores;}
    string getNombre(){return nombre;}
    Fecha getFechaElaboracion(){return fechaElaboracion;}
    int getIdTema(){return idTema;}
    int getListadeAutores(int iNumber){return listaAutores[iNumber];}
    
    //Metodos de Modificacion
    void setIdVideo(int idVideo){this->idVideo = idVideo;}
    void setNombre(string nombre){this->nombre =  nombre;}
    void setFechaElaboracion(Fecha fechaElaboracion){this->fechaElaboracion= fechaElaboracion;}
    void setIdTema(int idTema){this->idTema= idTema;}
    bool agregaAutor(int);
    
private:
    
    int idVideo, idTema,cantidadAutores,listaAutores[10];
    string nombre;
    Fecha fechaElaboracion;
};
EjemploVideo::EjemploVideo()
{
    idVideo = 0;
    idTema = 0;
    cantidadAutores = 0;
    for(int iCounter= 0; iCounter<10; iCounter++)
    listaAutores[iCounter] = 0;
    nombre = "-";
    fechaElaboracion.setDay(1);
    fechaElaboracion.setYear(2000);
    fechaElaboracion.setMonth(1);
}
bool EjemploVideo::agregaAutor(int idAutor)
{
    for(int iCounter = 0; iCounter < cantidadAutores; iCounter++)
    {
        if (listaAutores[iCounter] == idAutor || cantidadAutores == 10)
            return false;
    }
    listaAutores[cantidadAutores++] = idAutor;
    return true;
}

#endif /* EjemploVideo_h */
