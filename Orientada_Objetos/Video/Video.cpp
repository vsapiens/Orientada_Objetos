#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#define ErrorID "Porfavor teclee un ID valido"
#define ErrorCar "Porfavor teclee un caracter valido"
#define ErrorVideo "Ese ID ya esta en uso, porfavor teclee un ID valido"
#define ErrorCantidad "Porfavor teclee una cantidad valida"

#include "EjemploVideo.h"
//Variables Globales
Materia mate[5];
Tema tem[10];
Autor aut[10];
EjemploVideo ejem[20];
char cMenu;

//Hacer variables con cantidad
int iCantMaterias = 0;
int iCantTemas=0;
int iCantAutores=0;
int iCantEjemplos=0;
//Busqueda
bool existeMateria();
bool existeTema();
bool existeAutor();
bool existeVideo();

//Get Archivos
void getMaterias();
void getTemas();
void getAutores();
void getEjemplos();

//Despliegar Menu
void displayMenu();
void getCharacter();

bool existeMateria(int idMateria)
{
    for(int iCounter = 0; iCounter < iCantMaterias; iCounter++)
    {
        if(mate[iCounter].getIdMateria() == idMateria)
        {
            return true;
        }
    }
    return false;
}
bool existeTema(int idTema)
{
    for(int iCounter = 0; iCounter < iCantTemas; iCounter++)
    {
        if(tem[iCounter].getIdTema() == idTema)
        {
            return true;
        }
    }
    return false;
}
bool existeVideo(int idVideo)
{
    for(int iCounter = iCantEjemplos; iCounter--;)
    {
        if(ejem[iCounter].getIdVideo() == idVideo)
        {
            return true;
        }
    }
    return false;
}
bool existeAutor(int idAutor)
{
    for(int iCounter = iCantAutores; iCounter--;)
    {
        if(aut[iCounter].getIdAutor() == idAutor)
        {
            return true;
        }
    }
    return false;
}

void displayMateria(int idTema)
{
    for(int iCounter = iCantTemas;iCounter--;)
    {
            if(tem[iCounter].getIdTema() == idTema)
        {
            for(int iCounter2 = iCantMaterias; iCounter2--; )
                    if(tem[iCounter].getIdMateria() == mate[iCounter2].getIdMateria())
                    {
                        cout<<mate[iCounter2].getNombre()<<endl;
                        cout<<"Id de la Materia: "<< mate[iCounter2].getIdMateria()<<endl;
                    }
            
            }
    }
}
void displayTema(int idTema)
{
    for(int iCounter = iCantTemas; iCounter--;)
    {
        if(tem[iCounter].getIdTema()== idTema)
            cout<<tem[iCounter].getNombre()<<endl;
    }
    
}
void despliegarAutor(int idAutor)
{
    for(int iCounter = iCantAutores; iCounter--; )
    {
        if(idAutor == aut[iCounter].getIdAutor())
        {
            cout<<aut[iCounter].getNombre()<<endl;
        }
    }
}

void buscarporTema(int idTema)
{
    bool noHay = true;
    for(int iCounter = 0; iCounter < iCantEjemplos; iCounter++)
        {
            if(ejem[iCounter].getIdTema() == idTema)
            {
                Fecha fMuestra = ejem[iCounter].getFechaElaboracion();
                cout<<"\n\n"<<"Nombre de Video: "<<ejem[iCounter].getNombre()<<endl;
                cout<<"Id del Video : "<<ejem[iCounter].getIdVideo()<<endl;
                cout<<"Tema: ";
                displayTema(ejem[iCounter].getIdTema());
                cout<<"Id del tema: "<<ejem[iCounter].getIdTema()<<endl;
                cout<<"Materia: ";
                displayMateria(ejem[iCounter].getIdTema());
                cout<< "Fecha de Elaboración: ";
                fMuestra.muestra();
                cout<< "Autores: "<<endl;
                for(int iInnerCounter =ejem[iCounter].getCantidadAutores(); iInnerCounter--;)
                {
                    despliegarAutor(ejem[iCounter].getListadeAutores(iInnerCounter));
                }
                cout<<"\n\n";
                noHay = false;
            }
        }
    
    if(noHay)
    {
        cout<<"No hay Videos Disponibles"<<endl;
    }
}
void buscarporMateria(int idMateria)
{
    for(int iCounter = iCantTemas; iCounter--;)
    {
        if(tem[iCounter].getIdMateria() == idMateria)
        {
            buscarporTema(tem[iCounter].getIdTema());
        }
    }
}
void buscarporAutor(int idAutor)
{
    int iCounterCollab = 0;
    
    for(int iCounter = iCantEjemplos; iCounter--;)
        {
        for(int iCounter2 = iCantAutores; iCounter2--;)
            {
                 if(ejem[iCounter].getListadeAutores(iCounter2) == idAutor)
                    {
                        cout<<"ID del Video : "<<ejem[iCounter].getIdVideo()<<endl;
                        cout<<"Nombre del Video : "<<ejem[iCounter].getNombre()<<endl;
                        iCounterCollab++;
                    }
            }
        }
    cout<<"Total de Colaboraciones por el Autor: "<<iCounterCollab<<endl;
}
void getMaterias()
{
    ifstream archEntrada;
    string sTitulo;
    int iD, iCounter = 0;
    string sArchEntrada;
    cout<<"Ingrese el nombre del archivo de Materias con .txt:"<<endl;
    cin>>sArchEntrada;
    archEntrada.open(sArchEntrada);
    
    while(archEntrada>> iD && getline(archEntrada, sTitulo))
    {
        mate[iCounter].setIdMateria(iD);
        mate[iCounter].setNombre(sTitulo);
        iCantMaterias++;
        iCounter++;
    }
    archEntrada.close();
}
void getTemas()
{
    ifstream archEntrada;
    string sNombreTema;
    int idTema, idMateria, iCounter = 0;
    string sArchEntrada;
    cout<<"Ingrese el nombre del archivo de Temas con .txt:"<<endl;
    cin>>sArchEntrada;
    archEntrada.open(sArchEntrada);
    while(archEntrada>> idTema >> idMateria && getline(archEntrada, sNombreTema))
    {
        tem[iCounter].setIdTema(idTema);
        tem[iCounter].setIdMateria(idMateria);
        tem[iCounter].setNombre(sNombreTema);
        iCantTemas++;
        iCounter++;
    }
    archEntrada.close();
}
void getAutores()
{
    ifstream archEntrada;
    string sNombreAutor;
    int idAutor, iCounter = 0;
    string sArchEntrada;
    cout<<"Ingrese el nombre del archivo de Autores con .txt:"<<endl;
    cin>>sArchEntrada;
    archEntrada.open(sArchEntrada);
    while(archEntrada>> idAutor && getline(archEntrada, sNombreAutor))
    {
        aut[iCounter].setNombre(sNombreAutor);
        aut[iCounter].setIdAutor(idAutor);
        iCantAutores++;
        iCounter++;
    }
    archEntrada.close();
}
void getEjemplos()
{
    ifstream archEntrada;
    string sNombreAutor;
    int idVideo, idTema, iCounter = 0,iTrueCounter = 0, cantAutores, iDay, iMonth, iYear;
    string sNombre;
    bool bCargar = false;
    string sArchEntrada;
    cout<<"Ingrese el nombre del archivo de Ejemplos  con .txt:"<<endl;
    cin>>sArchEntrada;
    //Check idTema y checar que todos los autores existan
    archEntrada.open(sArchEntrada);
    
    while(archEntrada>> idVideo>>sNombre>> idTema >>iDay>> iMonth>> iYear>> cantAutores)
    {
        bCargar= false;
        int iArrAutores[cantAutores];
        for(int iCountArray = 0; iCountArray< cantAutores; iCountArray++)
        {
            archEntrada>>iArrAutores[iCountArray];
        }
    

         for(int iTemaCounter = 0; iTemaCounter< iCantTemas; iTemaCounter++)
         {
             if(idTema == tem[iTemaCounter].getIdTema())
             {
                 for(int iCounter = 0; iCounter < cantAutores; iCounter++)
                 {
                     for(int iInnerCounter = 0; iInnerCounter < iCantAutores; iInnerCounter++)
                     {
                         if(iArrAutores[iCounter] == aut[iInnerCounter].getIdAutor())
                         {
                         bCargar = ejem[iTrueCounter].agregaAutor(aut[iInnerCounter].getIdAutor());
                         }
                     }
                 }
             }
         }
        
            if(bCargar)
            {
                ejem[iTrueCounter].setIdTema(idTema);
                Fecha fechaElaboracion(iDay, iMonth, iYear);
                ejem[iTrueCounter].setNombre(sNombre);
                ejem[iTrueCounter].setFechaElaboracion(fechaElaboracion);
                ejem[iTrueCounter++].setIdVideo(idVideo);
                iCantEjemplos++;
            }
        bCargar = false;
        iCounter++;
        }
    archEntrada.close();
}
void getCharacter()
{
    cout<< "Teclee la opcion del menu"<<endl;
    cin>> cMenu;
}
void darAltaVideos()
{
    string sNombreAutor;
    int idVideo, idTema, cantAutores, iDay, iMonth, iYear, idAutor;
    string sNombre;
    
    cout<<"Ingrese el idVideo\t";
    cin>>idVideo;
    while(existeVideo(idVideo))
    {
        cout<<ErrorVideo<<endl;
        cin.ignore();
        cin>>idVideo;
    }
    cout<<"\n"<<"Ingrese el Nombre del Video\t";
    cin.ignore();
    getline(cin, sNombre);
    cout<<"\n"<<"Ingrese el Id del Tema\t";
    cin>>idTema;
    while(!existeTema(idTema))
    {
        cout<<ErrorID<<endl;
        cin.ignore();
        cin>>idTema;
    }
    cout<<"\n"<<"Ingrese el Dia de la Fecha\t";
    cin>>iDay;
    cout<<"\n"<<"Ingrese el Mes de la Fecha\t";
    cin>>iMonth;
    cout<<"\n"<<"Ingrese el Año de la Fecha\t";
    cin>>iYear;
    cout<<"\n"<<"Ingrese la cantidad de autores\t";
    cin>>cantAutores;
    while(cantAutores > 10 || cantAutores < 1)
    {
        cout<<ErrorCantidad<<endl;
        cin.ignore();
        cin>>cantAutores;
    }
    int iAutores[cantAutores];
    for(int iCounter = 0; iCounter < cantAutores;iCounter++)
    {
        cout<<"\n"<<"Ingrese el ID del Autor #"<<iCounter+1<<"\t";
        cin>>idAutor;
        while(!existeAutor(idAutor))
        {
            cout<<ErrorID<<endl;
            cin.ignore();
            cin>>idAutor;
        }
        iAutores[iCounter] = idAutor;
    }
    if(iCantEjemplos <= 20)
    {
    ejem[iCantEjemplos].setIdTema(idTema);
    ejem[iCantEjemplos].setIdVideo(idVideo);
    Fecha fAgregar(iDay,iMonth,iYear);
    ejem[iCantEjemplos].setNombre(sNombre);
    ejem[iCantEjemplos].setFechaElaboracion(fAgregar);
    for(int iCounter = 0; iCounter < cantAutores;iCounter++)
    {
        ejem[iCantEjemplos].agregaAutor(iAutores[iCounter]);
    }
        iCantEjemplos++;
    }
    else{
        cout<<"La cantidad maxima de videos ha sido alcanzada"<<endl;
    }
}
void displayMenu()
{
    do{
        bool bExiste = false;
        cout<<setw(20)<<"\n\n"<<"Menu\n";
        cout<<"\t"<<"a) Consulta información de Materias, Temas y Autores\n";
        cout<<"\t"<<"b) Dar de alta Videos de Ejemplo\n";
        cout<<"\t"<<"c) Consultar la lista de Videos por tema\n";
        cout<<"\t"<<"d) Consultar la lista de Videos por materia\n";
        cout<<"\t"<<"e) Consultar lista de Videos\n";
        cout<<"\t"<<"f) Consulta videos por autor\n";
        cout<<"\t"<<"g) Terminar\n";
        cout<<endl;
        getCharacter();
        switch (cMenu)
        {
                //Consulta información de Materias, Temas y Autores
            case 'a':
            case 'A':
                cout<<"\n\n"<<"Temas\n\n";
                cout<<"ID\t"<<"ID Materia\t"<<"Nombre\n";
                cout<<endl;
                for(int iCounter = 0; iCounter< iCantTemas; iCounter++)
                {
                cout<<tem[iCounter].getIdTema()<<"\t \t";
                cout<<tem[iCounter].getIdMateria()<<"\t \t";
                cout<<tem[iCounter].getNombre();
                }
                cout<<"\n\n"<<"Autores\n\n";
                cout<<"iD \t"<<"Nombre\n";
                cout<<endl;
                for(int iCounter = 0; iCounter< iCantAutores; iCounter++)
                {
                    cout<<aut[iCounter].getIdAutor()<<"\t";
                    cout<<aut[iCounter].getNombre();
                }
                
                cout<<"\n\n"<<"Materias\n\n";
                cout<<"iD \t"<<"Nombre\n";
                cout<<endl;
                for(int iCounter = 0; iCounter< iCantMaterias; iCounter++)
                {
                    cout<<mate[iCounter].getIdMateria()<<"\t";
                    cout<<mate[iCounter].getNombre();
                }
                break;
                //Dar de alta Videos de Ejemplo
            case 'b':
            case 'B':
                darAltaVideos();
                break;
                
                //Consultar la lista de Videos por tema
            case 'c':
            case 'C':
                int idBuscaTema;
                cout<<"¿Cual es el ID del Tema? \t";
                cin>>idBuscaTema;
                bExiste = existeTema(idBuscaTema);
                while(!bExiste)
                {
                    cout<< ErrorID<<endl;
                    cin.ignore();
                    cin>>idBuscaTema;
                    bExiste = existeTema(idBuscaTema);
                }
                buscarporTema(idBuscaTema);
                cout<<endl;
                break;
                //Consultar la lista de Videos por materia
                
            case 'd':
            case 'D':
                int idBuscaMateria;
                cout<<"¿Cual es el ID del Materia? \t";
                cin>>idBuscaMateria;
                bExiste = existeMateria(idBuscaMateria);
                while(!bExiste)
                {
                    cout<< ErrorID<<endl;
                    cin.ignore();
                    cin>>idBuscaMateria;
                    bExiste = existeMateria(idBuscaMateria);
                }
                buscarporMateria(idBuscaMateria);
                cout<<endl;
                break;
                //Consultar lista de Videos
            case 'e':
            case 'E':
                cout<<"\n\n"<<"Videos\n\n";
                for(int iCounter = iCantEjemplos; iCounter--;)
                {
                    Fecha fMuestra = ejem[iCounter].getFechaElaboracion();
                    cout<<"\n\n"<<"Nombre de Video: "<<ejem[iCounter].getNombre()<<endl;
                    cout<<"Id del Video : "<<ejem[iCounter].getIdVideo()<<endl;
                    cout<<"Tema: ";
                    displayTema(ejem[iCounter].getIdTema());
                    cout<<"Id del tema: "<<ejem[iCounter].getIdTema()<<endl;
                    cout<<"Materia: ";
                    displayMateria(ejem[iCounter].getIdTema());
                    cout<< "Fecha de Elaboración: ";
                    fMuestra.muestra();
                    cout<< "Autores: "<<endl;
                    for(int iInnerCounter =ejem[iCounter].getCantidadAutores(); iInnerCounter--;)
                    {
                        despliegarAutor(ejem[iCounter].getListadeAutores(iInnerCounter));
                    }
                    cout<<"\n\n";
                }
                break;
                //Consulta videos por autor
            case 'f':
            case 'F':
                int idBuscaAutor;
                cout<<"¿Cual es el ID del Autor? \t";
                cin>>idBuscaAutor;
                bExiste = existeAutor(idBuscaAutor);
                while(!bExiste)
                {
                    cout<< ErrorID<<endl;
                    cin.ignore();
                    cin>>idBuscaAutor;
                    bExiste = existeAutor(idBuscaAutor);
                }
                despliegarAutor(idBuscaAutor);
                cout<<endl;
                buscarporAutor(idBuscaAutor);
                cout<<endl;
                break;
                
        }
        
    } while(cMenu != 'g' && cMenu != 'G');
}
int main()
{
    getMaterias();
    getTemas();
    getAutores();
    getEjemplos();
    displayMenu();
    return 0;
}
