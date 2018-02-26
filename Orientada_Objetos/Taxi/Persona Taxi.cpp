//
//  main.cpp
//  PersonaTaxi
//
//  Created by Yolanda MartÃ­nez on 5/4/15.
//  Copyright (c) 2015 Yolanda MartÃ­nez. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Taxi.h"

int main()
{
    // crea el arreglo de objetos de tipo Taxi
    Taxi carros[20];
    int sizeTaxis = 0;
    int ide;
    string cel;
    string nomb;
    Persona chof;
    char opcion;
    bool encontro;
    
    ifstream archTaxis;
    archTaxis.open("Taxis.txt");
    
    // lee los datos del archivo de taxis y los agrega al arreglo de objetos
    while(archTaxis>>ide>>cel && getline(archTaxis,nomb))
    {
        chof.setNumCel(cel);
        chof.setNombre(nomb);
        carros[sizeTaxis].setChofer(chof);
        carros[sizeTaxis].setIdent(ide);
        sizeTaxis++;
        // verifico que el nombre no tenga espacios al inicio ni al final
    }
    archTaxis.close();
    
    do
    {
        cout << endl << "M E N U " << endl;
        cout << "a. ver lista de taxis" << endl;
        cout << "b. buscar taxi por chofer " << endl;
        cout << "c. agregar taxis a la lista " << endl;
        cout << "d. modificar el num de celular del chofer " << endl;
        cout << "e. Terminar" << endl;
        cout << "Opcion -> ";
        cin >> opcion;
        
        switch (opcion) {
            case 'a':
                for(int iCounter = 0; iCounter < sizeTaxis ;iCounter++)
                {
                cout<<setw(7)<<carros[iCounter].getIdent()<<"   ";
                cout<<carros[iCounter].getChofer().getNumCel()<<"   ";
                cout<<carros[iCounter].getChofer().getNombre();
                cout<<endl;
                }
                
                break;
                
            case 'b':
                cout << "Teclea el nombre de persona que vas a buscar ";
                cin.ignore();
                getline(cin, nomb);
                encontro = false;
                for(int iCounter = 0; iCounter < sizeTaxis;iCounter++)
                {
                    string nombre;
                    Persona chofi;
                    chofi = carros[iCounter].getChofer();
                    nombre = chofi.getNombre();
                    if(nombre.find(nomb) != -1)
                    {
                        cout<<"Id: "<<setw(7)<<carros[iCounter].getIdent()<<endl;
                        cout<<"Nombre:" <<setw(7)<<chofi.getNombre()<<endl;
                        cout<<"Celular: "<<setw(7)<<chofi.getNumCel()<<endl;
                        cout<<endl;
                        encontro =true;
                    }
                }
                if(!encontro)
                    cout<<"No se encontro el nombre del chofer\n";
                break;
                
            case 'c':
                cout << "Teclea el numero de taxi ";
                cin >> ide;
                cout << "Teclea el nombre del chofer ";
                cin.ignore();
                getline(cin, nomb);
                cout << "Teclea el numero de celular del chofer ";
                cin >> cel;
                chof.setNumCel(cel);
                chof.setNombre(nomb);
                carros[sizeTaxis].setIdent(ide);
                carros[sizeTaxis++].setChofer(chof);
                break;
                
            case 'd':
                cout << "Teclea el nombre del chofer ";
                cin.ignore();
                getline(cin, nomb);
                encontro = false;
                for(int iCounter = 0; iCounter < sizeTaxis;iCounter++)
                {
                    string nombre;
                    Persona chofi;
                    chofi = carros[iCounter].getChofer();
                    nombre = chofi.getNombre();
                    if(nombre.find(nomb) != -1)
                    {
                        cout<<"Id: "<<setw(7)<<carros[iCounter].getIdent()<<endl;
                        cout<<"Nombre:" <<setw(7)<<chofi.getNombre()<<endl;
                        cout<<"Celular: "<<setw(7)<<chofi.getNumCel()<<endl;
                        cout<<endl;
                        cout << "Teclea el nuevo celular del chofer\n";
                        cin.ignore();
                        cin>> cel;
                        chofi.setNumCel(cel);
                        carros[iCounter].setChofer(chofi);
                        encontro =true;
                    }
                }
                if(!encontro)
                cout<<"No se encontro el nombre del chofer\n";
                break;
        }
        
    } while (opcion != 'e');  // e es terminar
    
    return 0;
}
