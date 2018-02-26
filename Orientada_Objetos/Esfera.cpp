/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 3
 Ejercicio 1
 */

#include <iostream>

using namespace std;

#include "Esfera.hpp"
//Funcion que despliea los valores de la esfera con un radio determinado
void display(Esfera Esf)
{
    cout<<"Radio = "<<Esf.getRadio()<<endl;
    
    cout<<"Área = "<< Esf.calcArea()<<endl;
    
    cout<<"Volumen = "<<Esf.calcVolum()<<endl;
    
}

int main()
{
    Esfera Esf;
    int Radio;
    //Funcion con valores predeterminados
    display(Esf);
    //Cambio de radio
    cout<<"Inserte un valor para el radio de la esfera"<<endl;
    cin>>Radio;
    //Funcion de clase que cambia de radio
    Esf.setRadio(Radio);
    //Funcion que despliega con valores cambiados
    display(Esf);
    
    return 0;
}
