#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
/*
#define ErrorNum "Porfavor teclee un numero valido"
#define ErrorCar "Porfavor teclee un caracter valido"
#define ErrorAut "Porfavor teclee un autor valido"
#define ErrorNom "Porfavor teclee un nombre valido"
#define ErrorMat "Porfavor teclee un materia valido"
*/

#include "EjemploVideo.h"
//Variables Globales
Materia mate[5];
Tema tem[10];
Autor aut[10];
EjemploVideo ejem[20];
char cMenu;

//Get Archivos
void getMaterias();
void getTemas();
void getAutores();
void getEjemplos();

//Despliegar Menu
void displayMenu();
void getCharacter();

//--------------------------------------------------------------------------

void getMaterias()
{
    ifstream archEntrada;
    string sArchEntrada;
    string sTitulo;
    int iD, iCounter = 0;
    
    cout<< "Teclee el nombre del archivo de materias\n";
    cin.ignore();
    getline(cin, sArchEntrada);
    
    archEntrada.open(sArchEntrada);
    
    while(archEntrada>> iD && getline(archEntrada, sTitulo))
    {
        mate[iCounter].setIdMateria(iD);
        mate[iCounter].setNombre(sTitulo);
        iCounter++;
    }
    archEntrada.close();
}
void getTemas()
{
    ifstream archEntrada;
    string sArchEntrada;
    string sNombreTema;
    int idTema, idMateria, iCounter = 0;
    
    cout<< "Teclee el nombre del archivo de Temas\n";
    cin.ignore();
    getline(cin, sArchEntrada);
    
    archEntrada.open(sArchEntrada);
    while(archEntrada>> idTema >> idMateria && getline(archEntrada, sNombreTema))
    {
        tem[iCounter].setIdTema(idTema);
        tem[iCounter].setIdMateria(idMateria);
        tem[iCounter].setNombre(sNombreTema);
        iCounter++;
    }
    archEntrada.close();
}
void getAutores()
{
    ifstream archEntrada;
    string sArchEntrada;
    string sNombreAutor;
    int idAutor, iCounter = 0;
    
    cout<< "Teclee el nombre del archivo de Autores\n";
    cin.ignore();
    getline(cin, sArchEntrada);
    
    archEntrada.open(sArchEntrada);
    while(archEntrada>> idAutor && getline(archEntrada, sNombreAutor))
    {
        aut[iCounter].setNombre(sNombreAutor);
        aut[iCounter].setIdAutor(idAutor);
        iCounter++;
    }
    archEntrada.close();
}
void getEjemplos()
{
    ifstream archEntrada;
    string sArchEntrada;
    string sNombreAutor;
    int idVideo, idTema, cantAutores, listaAutores,iCounter = 0, iDay, iMonth, iYear;
    string sNombre;
    
    cout<< "Teclee el nombre del archivo de los videos de ejemplo\n";
    cin.ignore();
    getline(cin, sArchEntrada);
    
    archEntrada.open(sArchEntrada);
    while(archEntrada>> idVideo>>sNombre>> idTema >>iDay>> iMonth>> iYear>> cantAutores>>listaAutores)
    {
        Fecha fechaElaboracion(iDay, iMonth, iYear);
        
        ejem[iCounter].setIdTema(idTema);
        ejem[iCounter].setNombre(sNombre);
        ejem[iCounter].setFechaElaboracion(fechaElaboracion);
        ejem[iCounter].setIdVideo(idVideo);
        
        iCounter++;
    }
    archEntrada.close();
}
void getCharacter()
{
    cout<< "Teclee la opcion del menu"<<endl;
    cin>> cMenu;
}
void displayMenu()
{
    
    do{
        
        getCharacter();
        switch (cMenu)
        {
                //Consulta información de Materias, Temas y Autores
            case 'a':
                break;
                //Dar de alta Videos de Ejemplo
            case 'b':
                break;
                //Consultar la lista de Videos por tema
            case 'c':
                break;
                //Consultar la lista de Videos por materia
            case 'd':
                break;
                //Consultar lista de Videos
            case 'e':
                break;
                //Consulta videos por autor
            case 'f':
                break;
                
        }
        
    }while(cMenu != 'g');
}
int main()
{
    /*
    void getMaterias();
    void getTemas();
    void getAutores();
    void getEjemplos();
    void displayMenu();
     */
    return 0;
}
