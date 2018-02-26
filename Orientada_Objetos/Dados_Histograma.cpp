/*
 Erick Francisco Gonzalez Martinez
 A01039859
 Programación Orientada a Objetos
 Tarea 1
 Ejercicio 2
 
 @funcName Erick
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int iArrProbability[13];

/*
 randomizeDice
 Funcion que recibe el numero que se desea cambiar en el tablero
 Parametros: -
 Regresa: Número que se recibe en la consola.
 */
void randomizeDice()
{
    int iSum = 0;
    
    int iDice1 = 0, iDice2 = 0;
    
    for(int iCounter = 0; iCounter <= 200; iCounter++)
    {
        
        iDice1 = 1 + rand() % 6;
        
        iDice2 = 1 + rand() % 6;
        
        iSum = iDice1 + iDice2;
        
        ++iArrProbability[iSum];
    }
};
/*
 displayHistogram
 Funcion que despliega el histograma de las posibilidades
 Parametros: -
 Regresa: -
 */
void displayHistogram()
{
    for(int iCounter = 2; iCounter < 13; iCounter++)
    {
        if(iCounter > 9)
        {
        cout << iCounter << " | ";
        }
        
        else cout << iCounter << "  | ";
        
        for(int iInnerCounter = 0; iInnerCounter < iArrProbability[iCounter]; iInnerCounter++)
        {
            cout<< "*";
        }
        cout<<endl;
    }
};
/*
 displayHistogram
 Funcion que calcula la "probabilidad" de obtener la suma, ya sea mayor o menor
 Parametros: -
 Regresa: -
 */
void calculateProbability()
{
    int iBiggest = 0;
    int iLowest = 13;
    iArrProbability[1] = 201;
    
    for(int iCounter = 2; iCounter < 13; iCounter++)
    {

        if(iArrProbability[0] < iArrProbability[iCounter])
        {
            iArrProbability[0] = iArrProbability[iCounter];
            
            iBiggest = iCounter;
        }
        
    }
    for(int iCounter = 2; iCounter < 13; iCounter++)
    {
        
    if(iArrProbability[1] > iArrProbability[iCounter])
    {
        iArrProbability[1] = iArrProbability[iCounter];
        
        iLowest = iCounter;
    }
        
    }
    
    cout<< '\n' <<"El número más probable de salir es: "<< iBiggest <<endl;
    cout<< '\n' <<"El número menos probable de salir es: "<< iLowest << '\n' <<endl;
    
};
/*
 main
 Funcion que llama y ejecuta las funciones
 Parametros: -
 Regresa: -
 */
int main()
{
    srand(time(0));
    randomizeDice();
    displayHistogram();
    calculateProbability();
    return 0;
}
