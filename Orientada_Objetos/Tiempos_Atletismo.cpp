/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 2
 Ejercicio 1
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
/*
 readFile
 Lee un archivo en la cual registra la matricula el numero de intentos y el promedio en otro archivo
 Parametros: --
 Regresa: --
 */
void readFile()
{
    int iMatricula, iIntentos;
    float fPromedio = 0;
    ifstream archEntrada;
    ofstream archSalida;
    archEntrada.open("tiempos.txt");
    archSalida.open("promedios.txt");
    while(archEntrada >> iMatricula)
    {
        //Checa la matricula
        if(iMatricula >= 100000)
        {
        //Registra el numero de intentos
        archEntrada>> iIntentos;
        
        //Acumula el numero de intentos y obtiene el promedio
        for(int iCounter = 1, iNumber = 0; iCounter <= iIntentos; iCounter++)
        {
            archEntrada >> iNumber;
            fPromedio += iNumber;
        }
            
        fPromedio /= iIntentos;
            
        archSalida<< iMatricula <<"  "<< setprecision(2) << fixed <<fPromedio<<endl;
        }
        fPromedio = 0;
    }
    archEntrada.close();
    archSalida.close();
};
/*
 main
 Funcion que llama las funciones para la ejecucion
 Parametros: --
 Regresa: --
 */
int main()
{
    readFile();
    
    return 0;
}
