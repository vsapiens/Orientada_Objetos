#include <iostream>
#include <fstream>
using namespace std;

#include "Libro.h"
#include "Disco.h"
#include "Software.h"

Material *ListaMat[20];
int iCantMat = 0;
Reserva *ListaRes[50];
int iCantRes = 0;

void cargarArchMat()
{
    int idMat, iNumPag, iDur;
    char cTipo;
    string sAutor, sSistema,sTitulo;
    ifstream archEntrada;
    archEntrada.open("Material.txt");

    while(!archEntrada.eof())
    {
        archEntrada>>idMat>>sTitulo>>cTipo;
        
        switch(cTipo)
        {
            case 'L':
            {
                archEntrada>>iNumPag>>sAutor;
                Libro Lib(idMat,sTitulo,sAutor,iNumPag);
                *ListaMat[iCantMat++] = Lib;
            }
                break;
                
            case 'D':
            {
                archEntrada>>iDur;
                Disco Dis(idMat,sTitulo,iDur);
                *ListaMat[iCantMat++] = Dis;
            }
                break;
                
            case 'S':
            {
                 archEntrada>>sSistema;
                Software Soft(idMat,sTitulo,sSistema);
                *ListaMat[iCantMat++] = Soft;
                break;
            }
    }
    }
    archEntrada.close();
}
void cargarArchRes()
{
    ifstream archEntrada;
    Fecha f1;
    int idMat, idCli;
    archEntrada.open("Reserva.txt");
    while(!archEntrada.eof())
    {
        archEntrada>>f1>>idMat>>idCli;
        Reserva Entrada(idMat,idCli,f1);
        *ListaRes[iCantRes++] = Entrada;
    }
    archEntrada.close();
}

void guardarArchRes()
{
    ofstream archSalida;
    archSalida.open("Reserva.txt");
    int iCounter = iCantRes;
    while(iCounter>0)
    {
        Reserva Sal;
        Sal = *ListaRes[iCounter--];
        Fecha Salida;
        Salida = Sal.getReservacion();
        archSalida<< Salida.getDia()<< Salida.getMes()<< Salida.getAnio()<<" "<<Sal.getIdMaterial()<< " "<<Sal.getIdCliente()<<endl;
    }
    archSalida.close();
}
Material* getMaterial(int idMaterial)
{
    Material *Mat = NULL;
    for(int iCounter =0; iCounter< iCantMat;iCounter++)
    {
        if(ListaMat[iCounter]->getIdMaterial() == idMaterial)
        {
            *Mat= *ListaMat[iCounter];
            return Mat;
        }
    }
    return NULL;
}
Reserva* getReserva(int idMaterial)
{
    Reserva *Res = NULL;
    for(int iCounter =0; iCounter< iCantMat;iCounter++)
    {
        if(ListaRes[iCounter]->getIdMaterial() == idMaterial)
        {
            *Res= *ListaRes[iCounter];
            return Res;
        }
    }
    return NULL;
    
}

void Menu()
{
    char cMenu;
    do{
        
        cout<< "a. Consultar la lista de Materiales" <<endl;
        cout<<"b. Consultar la lista de reservaciones"<<endl;
        //al hacerlo deberás mostrar la fecha en la que inicia la reservación, la fecha en la que termina la reservación, el nombre del material y el id del cliente.
        cout<< "c. Consultar las reservaciones por Material"<<endl;
        //dado, que muestre para cada reservación el nombre del material, su fecha de inicio de reservación y su fecha de terminación.
        cout<< "d. Consultar las reservaciones por fecha"<<endl;
        //dada, que muestre la lista de los materiales que se encuentren reservados en la fecha dada. Debe mostrar el nombre del material y el id del cliente. Nota que tienes que revisar el rango de fechas de cada reservación para verificar si el material está reservado o no en una fecha dada.
        cout<<"e. Hacer una reservación"<<endl;
        //en esta opción pregunta al usuario el id del cliente y del material, así como la fecha en que desea reservar. El programa validará que id del material sea válido y que el material este disponible en esa fecha (o sea debe revisar las reservaciones existentes) y en caso de que sí se pueda, se reservará.
    cin>>cMenu;
        
        switch (cMenu) {
            case 'a':
                for(int iCounter = 0; iCounter < iCantMat; iCounter++)
                {
                    ListaMat[iCounter]->muestra();
                }
                break;
            case 'b':
            {
                int iArticulo = 1;
                for(int iCounter = 0; iCounter < iCantRes; iCounter++)
                {
                    Material *Mate;
                    Mate = getMaterial(ListaRes[iCounter]->getIdMaterial());
                    cout<<"Material #"<<iArticulo++<<endl;
                    cout<<"Titulo"<< Mate->getTitulo()<<endl;
                    cout<<"ID Cliente"<<ListaRes[iCounter]->getIdCliente()<<endl;
                    Fecha F1;
                    F1 = ListaRes[iCounter]->getReservacion();
                    cout<<" Fecha de Inicio: "<<F1<<endl;
                    F1 = ListaRes[iCounter]->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    cout<<" Fecha de Terminacion: "<<F1<<endl;
                }
            }
                break;
            case 'c':
            {
                int idMaterial = 0, iArticulo = 1;
                cout<<"Introduzca el id del Material /t";
                cin>>idMaterial;
                Material *Mate = getMaterial(idMaterial);
                while(Mate == NULL)
                {
                    cout<< "Ingrese un ID Valido"<<endl;
                    cin>>idMaterial;
                    Mate = getMaterial(idMaterial);
                }
                Reserva *Res = NULL;
                
                for (int iCounter  =0; iCounter < iCantRes; iCounter++)
                {
                    if( ListaRes[iCounter]->getIdMaterial() == idMaterial)
                    {
                    *Res = *ListaRes[iCounter];
                    cout<<"Articulo de Busqueda #"<<iArticulo++<<endl;
                    cout<<"Titulo"<< Mate->getTitulo()<<endl;
                    cout<<"ID Cliente"<<Res->getIdCliente()<<endl;
                    Fecha F1;
                    F1 = Res->getReservacion();
                    cout<<" Fecha de Inicio: "<<F1<<endl;
                    F1 = Res->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    cout<<" Fecha de Terminacion: "<<F1<<endl;
                    }
                }
            }
                break;
            case 'd':
            {
                Fecha fEntrada,fInicio, fTerminar;
                int iArticulo = 1;
                cout<<" Inserte día, mes y año de la busqueda /t";
                cin>>fEntrada;
                for(int iCounter =0; iCounter< iCantRes;iCounter++)
                {
                    Material *Mate =  getMaterial(ListaRes[iCounter]->getIdMaterial());
                    fInicio = ListaRes[iCounter]->getReservacion();
                    fTerminar = ListaRes[iCounter]->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    if(fInicio <= fEntrada && fEntrada <= fTerminar)
                    {
                        cout<<"Articulo de Busqueda #"<<iArticulo++<<endl;
                        cout<<"Titulo"<< Mate->getTitulo()<<endl;
                        cout<<"ID Cliente"<<ListaRes[iCounter]->getIdCliente()<<endl;
                    }
                }
                if(iArticulo == 1)
                {
                    cout<<"No se encontraron reservas durante la fecha de búsqueda"<<endl;
                }
            }
                break;
            case 'e':
            {
                int idCliente, idMaterial;
                Fecha fEntrada,fInicio, fTerminar;
                
                cout<<"Ingrese el ID del Cliente /t";
                cin>>idCliente;
                cout<<"Ingrese el ID del Material /t";
                cin>>idMaterial;
                
                Material *Mate = getMaterial(idMaterial);
                while(Mate == NULL)
                {
                    cout<< "Ingrese un ID Valido"<<endl;
                    cin>>idMaterial;
                    Mate = getMaterial(idMaterial);
                }
                cout<<" Inserte día, mes y año de la reservación /t";
                cin>>fEntrada;
                Reserva *Res = NULL;
                
                for (int iCounter  =0; iCounter < iCantRes; iCounter++)
                {
                    if( ListaRes[iCounter]->getIdMaterial() == idMaterial)
                    {
                        *Res = *ListaRes[iCounter];
                        cout<<"Titulo"<< Mate->getTitulo()<<endl;
                        cout<<"ID Cliente"<<Res->getIdCliente()<<endl;
                        Fecha F1;
                        F1 = Res->getReservacion();
                        cout<<" Fecha de Inicio: "<<F1<<endl;
                        F1 = Res->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                        cout<<" Fecha de Terminacion: "<<F1<<endl;
                    }
            }
            }
                break;
        }
        
    } while(cMenu != 'f');
    
    guardarArchRes();
}

int main()
{
    cargarArchMat();
    cargarArchRes();
    Menu();
    return 0;
}
