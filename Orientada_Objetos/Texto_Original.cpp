/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 2
 Ejercicio 2
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/*
countSpaces
 Cuenta el numero de espacios que contiene un string
 Parametros: La frase a la que se contarán los espacios
 Regresa: El número de espacios en una frase
 */
int countSpaces(string sFrase)
{
    int iSpaces = 0;
    for(int iCounter = 0; iCounter < sFrase.length(); iCounter++)
    {
        if(sFrase[iCounter] == ' ')
            iSpaces++;
    }
    return iSpaces;
}
/*
 readFile
 Lee un archivo por línea, lo justifica a 25 caracteres y lo escribe en otro archivo justificado
 Parametros: --
 Regresa: --
 */
void read_write_File()
{
    int iSpaces = 0;
    int iNumber = 0,iRemainder = 0;
    string sFrase;
    ifstream archEntrada;
    ofstream archSalida;
    archEntrada.open("textoOriginal.txt");
    archSalida.open("textoJustificado.txt");
    // Mientras que el archivo tengoa renglones, se seguirá ejecutando
    while(getline(archEntrada,sFrase))
    {
        //Obtiene el número de espacios de la frase y la guarda
        iSpaces = countSpaces(sFrase);
        //Checa el largo de la frase y el número de espacios
        if(iSpaces != 0 && sFrase.length() < 25)
        {
            //Obtiene el residuo de espacios
            iRemainder = (25 - sFrase.length()) % iSpaces;
            //Obtiene el número de espacios que se añadirán por espacio
            iNumber = (25 - sFrase.length()) / iSpaces;
            
            //Inserta los espacios
            for(int iCounter = 0; iCounter < sFrase.length(); iCounter++)
            {
                if(sFrase[iCounter] == ' ')
                {
                    sFrase.insert(iCounter, iNumber, ' ');
                    iCounter += iNumber;
                }
            }
            //Inserta los espacios en el último espacio
            if(iRemainder != 0)
            {
                for(int iCounter = sFrase.length(); iCounter >= 0 && iRemainder != 0;iCounter--) 
                {
                    if(sFrase[iCounter] == ' ')
                    {
                        sFrase.insert(iCounter, 1, ' ');
                        iCounter -= iNumber--;
                        iRemainder--;
                    }
                }
            }
            //Escribe en el archivo
            archSalida << sFrase <<endl;
            
        }
        //En caso de que la frase sea más larga o no tenga espacios la despliega como tal
        else archSalida << sFrase <<endl;
    }
    archEntrada.close();
    archSalida.close();
};

/*
 main
 Llama a todas las funciones para ejecutarlas
 Parametros: --
 Regresa: --
 */
int main()
{
    read_write_File();
    
    return 0;
}
