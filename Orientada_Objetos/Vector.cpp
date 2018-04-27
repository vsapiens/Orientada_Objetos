#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    vector<int> lista;
    vector<int>::iterator iter;
    vector<int>::reverse_iterator iter2;
    ifstream archEntrada;
    int iNumber;
    archEntrada.open("Numeros.txt");
    while(archEntrada>>iNumber)
    {
        lista.push_back(iNumber);
    }
    char cTipo;
    do
    {
        cout<<endl;
        cout<<"Vector : ";
        for (size_t i = 0; i < lista.size(); i++)
            cout<<lista[i]<<" ";
        
        cout<<endl;
        
        cout<< "a.Shift a la izquierda"<<endl;
        cout<< "b.Shift a la derecha"<<endl;
        cout<< "c.Invertir el orden"<<endl;
        cout<< "d.Terminar" <<endl;
        
        cout<<"Inserte una opción:  ";
        cin>>cTipo;
        switch (cTipo) {
            case 'a':
            {
                int iNumber = lista[0];
                lista.erase(lista.begin()+0);
                lista.insert(lista.end(),iNumber);
            }
                break;
            case 'b':
            {
                int iNumber = lista[lista.size()-1];
                lista.erase(lista.begin()+lista.size()-1);
                lista.insert(lista.begin(),iNumber);
            }
                break;
            case 'c':
            {
                vector<int> lista2;
                for (iter2 = lista.rbegin(); iter2 != lista.rend(); iter2++)
                    lista2.push_back(*iter2);

                lista = lista2;
            }
                break;
        }
        
    }while(cTipo != 'd');
        
        
        
        return 0;
}
