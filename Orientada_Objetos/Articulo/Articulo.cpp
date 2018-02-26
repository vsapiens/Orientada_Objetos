//
//  Articulo.cpp
//  Orientada_Objetos
//
//  Created by Erick González on 2/9/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Articulo.hpp"

Articulo Producto[20];
Proveedor Personas[20];

void getArticulos()
{
    int clave, numProveedor;
    string descripcion;
    double precio;
    ifstream archEntrada;
    archEntrada.open("Articulos.txt");
    
    while(!archEntrada.eof())
    {
        int iCounter  = 0;
        
        archEntrada>>clave>>precio>>numProveedor;
        
        cin.ignore();
        
        getline(archEntrada,descripcion);
        
        Producto[iCounter].setClave(clave);
        Producto[iCounter].setDescripcion(descripcion);
        Producto[iCounter].setNumProveedor(numProveedor);
        Producto[iCounter].setPrecio(precio);
        iCounter++;
    }
    archEntrada.close();
}
void getProveedor()
{
    int numero;
    string nombre;
    ifstream archEntrada;
    archEntrada.open("Proveedor.txt");
    
    while(!archEntrada.eof())
    {
        int iCounter  = 0;
        
        archEntrada>>numero;
        
        cin.ignore();
        
        getline(archEntrada,nombre);
        
        Personas[iCounter].setNombre(nombre);
        Personas[iCounter].setNumero(numero);
        
        iCounter++;
    }
    archEntrada.close();
}
void displayProveedores()
{
    string sName;
    cout<< "Inserte el Nombre del Archivo"<<endl;
    getline(cin, sName);
    sName += ".txt";
    ofstream archSalida;
    archSalida.open(sName);
    archSalida<< "clave"<<setw(10)<<"precio"<<setw(10)<<"numProveedor"<<setw(10)<<"descripcion"<<setw(10)<<endl;

}
int main()
{
    getProveedor();
    getArticulos();
    return 0;
}
