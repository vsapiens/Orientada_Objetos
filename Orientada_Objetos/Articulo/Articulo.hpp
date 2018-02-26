//
//  Articulo.hpp
//  Orientada_Objetos
//
//  Created by Erick González on 2/9/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Articulo_hpp
#define Articulo_hpp

#include <stdio.h>

class Articulo
{
public:
    Articulo(int, int, string, double);
    Articulo();
    void setNumProveedor(int);
    void setClave(int);
    void setDescripcion(string);
    void setPrecio(double);
    
    int getNumProveedor()
    {
        return numProveedor;
    };
    int getClave()
    {
        return clave;
    }
    string getDescripcion()
    {
        return descripcion;
    }
    double getPrecio()
    {
        return precio;
    };
    
private:
    int clave, numProveedor;
    string descripcion;
    double precio;
    
};
Articulo::Articulo()
{
    precio = 0;
    numProveedor = 0;
    clave = 0;
}
Articulo::Articulo(int numProveedor, int clave, string descripcion, double precio)
{
        this->numProveedor = numProveedor;
        this->clave = clave;
        this->descripcion = descripcion;
        this-> precio = precio;
}

void Articulo::setNumProveedor(int numProveedor)
{
    this->numProveedor = numProveedor;
}
void Articulo::setClave(int clave)
{
    this->clave = clave;
}
void Articulo::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
void Articulo::setPrecio(double precio)
{
    this-> precio = precio;
}

class Proveedor
{
public:
    Proveedor();
    Proveedor(int, string);
    void setNumero(int);
    void setNombre(string);
    
    int getNumero()
    {
        return numero;
    }
    string getNombre()
    {
        return string;
    }
private:
    int numero;
    string nombre;
};
Proveedor::Proveedor(int numero, string nombre)
{
        this->numero = numero;
        this->nombre = nombre;
}
Proveedor::Proveedor()
{
    numero = 0;
}

void Proveedor::setNumero(int numero)
{
    this->numero = numero;
}
void Proveedor::setNombre(string nombre)
{
    this->nombre = nombre;
}

#endif /* Articulo_hpp */
