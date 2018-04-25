#include <iostream>
#include <fstream>
#include <iomanip>
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
                ListaMat[iCantMat++] = new Libro(idMat,sTitulo,sAutor,iNumPag);
            }
                break;
                
            case 'D':
            {
                archEntrada>>iDur;
                ListaMat[iCantMat++] = new Disco(idMat,sTitulo,iDur);
            }
                break;
                
            case 'S':
            {
                 archEntrada>>sSistema;
                
                ListaMat[iCantMat++] = new Software(idMat,sTitulo,sSistema);;
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
    while(archEntrada>>f1>>idMat>>idCli)
    {
        ListaRes[iCantRes++] = new Reserva(idMat,idCli,f1);
    }
    archEntrada.close();
}

/*void guardarArchRes()
{
    ofstream archSalida;
    archSalida.open("Reserva.txt");
    for(int iCounter = 0; iCounter<iCantRes; iCounter++)
    {
        cout<<iCounter<<endl;
        cout<<iCantRes<<endl;
        Fecha Salida = ListaRes[iCounter]->getFechaReservacion();
        archSalida<< Salida.getDia()<<" "<<  Salida.getMes()<<" "<< Salida.getAnio()<<" "<<ListaRes[iCounter]->getIdMaterial()<< " "<<ListaRes[iCounter]->getIdCliente()<<endl;
    
    }
    archSalida.close();
}
*/
Material* getMaterial(int idMaterial)
{
    Material *Mate;
    for(int iCounter =0; iCounter< iCantMat;iCounter++)
    {
        if(ListaMat[iCounter]->getIdMaterial() == idMaterial)
        {
            Mate= ListaMat[iCounter];
            return Mate;
            
        }
    }
    return NULL;
}

/* void getReserva(int idMaterial)
{
    
    for(int iCounter =0; iCounter< iCantMat;iCounter++)
    {
        if(ListaRes[iCounter]->getIdMaterial() == idMaterial)
            Res = ListaRes[iCounter];
    }
}
*/
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
        cout<<"f. Terminar"<<endl;
    cin>>cMenu;
        
        switch (cMenu) {
            case 'a':
            {
                short int iArticulo(1);
                for(int iCounter = 0; iCounter < iCantMat; iCounter++)
                {
                    cout<<"Articulo #"<< iArticulo++<<endl;
                    ListaMat[iCounter]->muestra();
                    cout<<endl;
                }
            }
                break;
            case 'b':
            {
                int iArticulo = 1;
                cout<< setw(50)<<" Lista de Reservaciones"<<endl;
                for(int iCounter = 0; iCounter < iCantRes; iCounter++)
                {
                    /*
                    Material *Mate = NULL;
                    for( int iMatCounter = 0; iMatCounter < iCantMat; iMatCounter++)
                    {
                        if(ListaRes[iCounter]->getIdMaterial() == ListaMat[iMatCounter]->getIdMaterial())
                        {
                            Mate  = ListaMat[iMatCounter];
                        }
                    }
                     */
                    Material *Mate =  getMaterial(ListaRes[iCounter]->getIdMaterial());
                    
                    Fecha F1;
                    
                    cout<<endl;
                    cout<<"Reservacion #"<<iArticulo++<<endl;
                    cout<<" Titulo: "<< Mate->getTitulo()<<endl;
                    cout<<" ID Cliente: "<<ListaRes[iCounter]->getIdCliente()<<endl;
                    F1 = ListaRes[iCounter]->getFechaReservacion();
                    cout<<" Fecha de Inicio: "<<F1<<endl;
                    F1 = ListaRes[iCounter]->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    cout<<" Fecha de Terminacion: "<<F1<<endl;
                }
                cout<<endl<<endl;
            }
                break;
            case 'c':
            {
                int idMaterial = 0, iArticulo = 1;
                bool bExiste =false;
                Reserva *Res;
                
                cout<<"Introduzca el id del Material"<<endl;
                cin>>idMaterial;
                
                
                /*for( int iMatCounter = 0; iMatCounter < iCantMat; iMatCounter++)
                {
                    if(idMaterial == ListaMat[iMatCounter]->getIdMaterial())
                        Mate  = ListaMat[iMatCounter];
                }
                 */
                Material *Mate =  getMaterial(idMaterial);
                
                while(Mate == NULL)
                {
                    cout<< "Ingrese un ID Valido"<<endl;
                    cin>>idMaterial;
                    for( int iMatCounter = 0; iMatCounter < iCantMat; iMatCounter++)
                    {
                        Mate = getMaterial(idMaterial);
                    }
                }
                
                for (int iCounter  =0; iCounter < iCantRes; iCounter++)
                {
                    if(ListaRes[iCounter]->getIdMaterial() == idMaterial)
                    {
                        cout<<endl;
                    Res = ListaRes[iCounter];
                    cout<<"Articulo de Busqueda #"<<iArticulo++<<endl;
                        cout<<" Titulo: "<< Mate->getTitulo()<<endl;
                        cout<<" ID Cliente: "<<Res->getIdCliente()<<endl;
                    Fecha F1;
                    F1 = Res->getFechaReservacion();
                    cout<<" Fecha de Inicio: "<<F1<<endl;
                    F1 = Res->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    cout<<" Fecha de Terminacion: "<<F1<<endl;
                        bExiste = true;
                    }
                    
                }
                
                if(!bExiste)
                {
                    
                    cout<<" No existe una reservación de ese material"<<endl;
                    
                }
                cout<<endl<<endl;
            }
                break;
            case 'd':
            {
                //Busqueda por Fecha
                Fecha fEntrada,fInicio, fTerminar;
                int iArticulo = 1;
                Material *Mate;
                cout<<" Inserte día, mes y año de la busqueda  ";
                cin>>fEntrada;
                for(int iCounter =0; iCounter < iCantRes;iCounter++)
                {
                    Mate =  getMaterial(ListaRes[iCounter]->getIdMaterial());
                    
                    fInicio = ListaRes[iCounter]->getFechaReservacion();
                    
                    fTerminar = ListaRes[iCounter]->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    
                    if(fEntrada >= fInicio && fEntrada <= fTerminar)
                    {
                        cout<<" Articulo de Busqueda #"<<iArticulo++<<endl;
                        cout<<" Titulo: "<< Mate->getTitulo()<<endl;
                        cout<<" ID Cliente: "<<ListaRes[iCounter]->getIdCliente()<<endl;
                        
                    }
                }
                if(iArticulo == 1)
                    cout<<"No se encontraron reservas durante la fecha de búsqueda."<<endl<<endl;
                
            }
                cout<<endl<<endl;
                break;
            case 'e':
            {
                
                int idCliente, idMaterial;
                bool bMaterialReservado = false;
                Fecha fEntrada, fSalida,fInicio, fTerminar;
                
                cout<<"Ingrese el ID del Cliente ";
                cin>>idCliente;
                cout<<"Ingrese el ID del Material ";
                cin>>idMaterial;
                
                Material *Mate =  getMaterial(idMaterial);
                
                while(Mate == NULL)
                {
                    cout<< "Ingrese un ID Valido"<<endl;
                    cin>>idMaterial;
                    for( int iMatCounter = 0; iMatCounter < iCantMat; iMatCounter++)
                        Mate = getMaterial(idMaterial);
                }
                
                cout<<"Ingrese día, mes y año de la reservación."<<endl;
                
                cin>>fEntrada;
                
                int iNumber  =  Mate->cantidadDiasdePrestamo();
                fSalida = fEntrada + iNumber;
                
                for (int iCounter  =0; iCounter < iCantRes; iCounter++)
                {
                    fInicio = ListaRes[iCounter]->getFechaReservacion();
                    fTerminar = ListaRes[iCounter]->calculaFechaFinReserva(Mate->cantidadDiasdePrestamo());
                    if(ListaRes[iCounter]->getIdMaterial() == idMaterial)
                    {
                        if((fEntrada >= fInicio && fEntrada <= fTerminar) || (fSalida >= fInicio && fSalida <= fTerminar))
                            bMaterialReservado = true;
                            
                    }
                    
                    
                }
                    
                
                
               if(!bMaterialReservado)
               {
                cout<<" ¡Nuevo Reservación Agregada! "<<endl;
                cout<<" Titulo: "<< Mate->getTitulo()<<endl;
                cout<<" ID Cliente: "<<idCliente<<endl;
                ListaRes[iCantRes] = new Reserva(idMaterial,idCliente,fEntrada);
                cout<<" Fecha de Reserva: "<<fEntrada<<endl;
                   iCantRes++;
               }
               else cout<<" Existe una reservacion durante esa fecha. "<<endl;
                
                
            }
                break;
        }
        
    } while(cMenu != 'f');
    
    ofstream archSalida;
    archSalida.open("Reserva.txt");
    for(int iCounter = 0; iCounter<iCantRes; iCounter++)
    {
        Fecha Salida = ListaRes[iCounter]->getFechaReservacion();
        archSalida<< Salida.getDia()<<" "<<  Salida.getMes()<<" "<< Salida.getAnio()<<" "<<ListaRes[iCounter]->getIdMaterial()<< " "<<ListaRes[iCounter]->getIdCliente()<<endl;
        
    }
    archSalida.close();
}

int main()
{
    cargarArchMat();
    cargarArchRes();
    Menu();
    return 0;
}
