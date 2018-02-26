/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 3
 Ejercicio 2
 */

#include <iostream>
#include <string>
using namespace std;

#include "SalaCine.hpp"

int main()
{
    int iLug, iBoletos = 0;
    SalaCine Sala1;
    string PeliculaSala1;
    
    cout << "¿Cuántos lugares hay en la Sala 1? \n";
    
    cin >> iLug;
    //Decalara el numero de lugares en la sala 1
    Sala1.setLugares(iLug);
    
    cout << "\n¿Qué película se despliega en la Sala 1? \n";
    //Ignora cualquier espacio que no permita que el usuario nombre la sala
    cin.ignore();
    // Se nombra la pelicula de la sala
    getline(cin,PeliculaSala1);
    
    Sala1.setPelicula(PeliculaSala1);

    //Se ejecuta mientras que haya lugares en la sala
    while(Sala1.getLugares() != 0)
 {
    
        cout<< "\n¿Cuántos boletos desea comprar? \n";
        
        cin>> iBoletos;
        //Checa por los lugares disponibles
        if(iBoletos <= Sala1.getLugares())
        {
        //Compra los boletos y se reduce el numero de lugares disponibles en la sala
            Sala1.compraBoleto(iBoletos);
        }
        //Despliega cuantos lugares quedan y para que pelicula (actualizada)
        cout<<"\nQuedan "
        << Sala1.getLugares()
        <<" lugares disponibles para la pelicula "
        << Sala1.getPelicula()<<".\n";
 }
    
    
}

