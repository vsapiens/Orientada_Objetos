//
//  Evento.cpp
//  Orientada_Objetos
//
//  Created by Erick González on 2/16/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Evento.hpp"
int getNumber()
{
    int iNumber;
    cout<< "Inserte el numero de eventos que desea crear.\n";
    cin>>iNumber;
    return iNumber;
}
void crearEventos(Evento Eventos[100], int iNumber)
{
    for(int iCounter= 0; iCounter > iNumber; iCounter++)
    {
        int Duracion = 0, Hora, Minuto;
        string Asunto;
        cout<<"Duracion? \n";
        cin>> Duracion;
        Eventos[iCounter].setDuracion(Duracion);
        cout<<"Asunto? \n";
        cin.ignore();
        getline(cin,Asunto);
        Eventos[iCounter].setAsunto(Asunto);
        cout<<"Hora y minuto de inicio? \n";
        cin>> Hora>> Minuto;
        Reloj Evento(Hora, Minuto);
        Eventos[iCounter].setInicio(Evento);
    }
}
void despliegarEventos(Evento Eventos[100], int iNumber)
{
    
    cout<< setw(30)<< "Asunto"<< "Inicio"<<setw(30)<<"Duracion"<<setw(30)<<"Final\n";
    
    for(int iCounter= 0; iCounter > iNumber; iCounter++)
    {
        Reloj tiempo;
        cout<< setw(30)<< Eventos[iCounter].getDuracion();
        cout<< setw(30)<<Eventos[iCounter].getAsunto();
        tiempo = Eventos[iCounter].getInicio();
        cout<< setw(30)<<tiempo.getHora()<< ":"<< tiempo.getMinu()<<endl;
        
    }
    
}
int main()
{
    int iNumber;
    iNumber = getNumber();
    Evento Eventos[100];
    crearEventos(Eventos, iNumber);
    despliegarEventos(Eventos, iNumber);
    return 0;
}

