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
    string sArchEntrada;
    cout<< "Teclee el nombre del archivo de materias\n"
    cin.ignore();
    getline(cin, sArchEntrada);
    
    ifstream archEntrada;
    archEntrada.open(sArchEntrada);
    
    while()
    
    
}
void getTemas();
void getAutores();
void getEjemplos();
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
