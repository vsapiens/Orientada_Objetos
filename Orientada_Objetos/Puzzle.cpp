/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 1
 Ejercicio 1
 */

#include <iostream>
#include <iomanip>

using namespace std;

int iRowIndex = 0, iColumnIndex=0;

// Matriz que determina el tablero principal
int iPuzzle[4][4]
{
    {4, 7, 2, 0},
    {3, 10, 1, 9},
    {5, 8, 12, 15},
    {6, 11, 13, 14}

};

/*
 getNumber
 Funcion que recibe el numero que se desea cambiar en el tablero
 Parametros: -
 Regresa: Número que se recibe en la consola.
*/

 int getNumber()
{
    int iNumber;
    
    cin>> iNumber;
    
    return iNumber;
};

void swap(int iNumber)
{
    if(iPuzzle[iRowIndex-1][iColumnIndex] == 0 && iRowIndex-1 >= 0)
    {
        iPuzzle[iRowIndex][iColumnIndex] = 0;
        iPuzzle[iRowIndex-1][iColumnIndex] = iNumber;
    }
    if(iPuzzle[iRowIndex][iColumnIndex-1] == 0 && iColumnIndex-1 >= 0)
    {
        iPuzzle[iRowIndex][iColumnIndex] = 0;
        iPuzzle[iRowIndex][iColumnIndex-1] = iNumber;
    }
    
    if(iPuzzle[iRowIndex+1][iColumnIndex] == 0 && iRowIndex+1 <= 3)
    {
        iPuzzle[iRowIndex][iColumnIndex] = 0;
        iPuzzle[iRowIndex+1][iColumnIndex] = iNumber;
    }
    
    if(iPuzzle[iRowIndex][iColumnIndex+1] == 0 && iColumnIndex+1 <= 3)
    {
        iPuzzle[iRowIndex][iColumnIndex] = 0;
        iPuzzle[iRowIndex][iColumnIndex+1] = iNumber;
    }
}
/*
 move
 Funcion que encuentra la posición del número, verifica que sea
 Parametros: Matriz del tablero y el número que se va a mover
 Regresa: -
 */
void move(int iPuzzle[4][4], int iNumber)
{
    for(int iCounterRow = 0; iCounterRow < 4 ; iCounterRow++)
    {
        
        for(int iCounterColumn = 0; iCounterColumn < 4 ; iCounterColumn++)
        {
            
            if(iPuzzle[iCounterRow][iCounterColumn] == iNumber)
            {
                iRowIndex = iCounterRow;
                iColumnIndex= iCounterColumn;

        }
        }
    }
};
/*
 display
 Funcion que despliega la matriz modificada
 Parametros: Matriz del tablero
 Regresa: -
 */
void display(int iPuzzle[4][4])
{
    for(int iCounter = 0; iCounter < 30; iCounter++)
    {
        cout<< '\n' ;
        
    }
    for(int iCounterRow = 0; iCounterRow < 4 ; iCounterRow++)
        {
            
         for(int iCounterColumn = 0; iCounterColumn < 4 ; iCounterColumn++)
         {
             if(iPuzzle[iCounterRow][iCounterColumn] == 0)
             {
                 cout<< setw(4) << " ";
             }
             else cout<< setw(4) << iPuzzle[iCounterRow][iCounterColumn] << " ";

         }
            cout<< endl;
        }
    
};
/*
 runGame
 Funcion llama a las demas funciones de mover y despliegar tablero
 Parametros: -
 Regresa: -
 */
void runGame()
{
    int iNumber;
    
    display(iPuzzle);
    
//Este ciclo se repite hasta que el usuario introduzca 0 para terminar el programa
    
    while(true)
    {
        iNumber = getNumber();
        
            if(iNumber == 0)
        {
            break;
        }
        
        move(iPuzzle,iNumber);
        
        swap(iNumber);
        
        display(iPuzzle);
    }
}
/*
 main
 Funcion llama a las demás funciones
 Parametros: -
 Regresa: -
 */
int main()
{
    runGame();
    
    return 0;
}
