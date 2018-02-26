//
//  Complejo.cpp
//  Orientada_Objetos
//
//  Created by Erick González on 2/2/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;
#include "Complejo.hpp"


int main()
{
    int iComplex, iReal, iImaginary;
    char cType;
    cout<< "Inserte el numero de numeros complejos \n";
    cin>>iComplex;
    Complejo Lista[iComplex];
    for(int iCounter = 0; iCounter<iComplex;iCounter++)
    {
        cout<< "Inserte el numero real e imaginario para el par complejo numero "<< iCounter<<"\n";
        cin>>iReal>>iImaginary;
        Lista[iCounter].setReal(iReal);
        Lista[iCounter].setImag(iImaginary);
    }
    for(int iCounter = 0; iCounter< iComplex;iCounter++)
    {
        cout<< iCounter<< " :";
        Lista[iCounter].muestra();
        cout<<endl;
    }
    
    do{
        int iComplejo1, iComplejo2;
        Complejo cRespuesta;
        cout<< "a. sumar 2 números \n";
        cout<< "b. restar 2 números \n";
        cout<< "c. sumar todos los números del arreglo \n";
        cout<< "d. terminar \n";
        
        cin>>cType;
        
        switch(cType)
        {
            case 'a':
                cout<<"Insertar los dos numeros que se desean sumar \n";
                cin>> iComplejo1>>iComplejo2;
                cRespuesta = iComplejo1 + iComplejo2;
                cRespuesta.muestra();
                cout<<endl;
                break;
            case 'b':
                cout<<"Insertar los dos numeros que se desean restar \n";
                cin>> iComplejo1>>iComplejo2;
                cRespuesta = Lista[iComplejo1].resta(Lista[iComplejo2]);
                cRespuesta.muestra();
                cout<<endl;
                break;
                
            case 'c':
                
                for(int iCounter = 0; iCounter < iComplex; iCounter++)
                {
                    cRespuesta = cRespuesta.suma(Lista[iCounter]);
                }
                cRespuesta.muestra();
                cout<<endl;
                break;
            
        }
        
    }while(cType != 'd');
    
        
    return 0;
}



