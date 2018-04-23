#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> lista;
    lista.push_back(4);
    lista.push_back(2);
    lista.push_back(1);
    lista.push_back(3);
    vector<int>::iterator iter;
    char cTipo;
do
{
    cout<<" Vector : ";
    for (size_t i = 0; i < lista.size(); i++)
        cout<<lista[i]<<" ";
    cout<<endl;
    cout<< "a.Insertar al inicio"<<endl;
    cout<< "b.Insertar al final"<<endl;
    cout<< "c.Borrar del inicio"<<endl;
    cout<< "d.Borrar del final" <<endl;
    cout<< "e.Ordenar"<<endl;
    cout<< "f.Buscar un dato en el vector"<<endl;
    cout<<"g.Terminar"<<endl;
    
    cin>>cTipo;
    switch (cTipo) {
        case 'a':
        { int iNumber(0);
            cout<< "f.Buscar un dato en el vector"<<endl;
            cin>>iNumber;
            lista.insert(lista.begin(), iNumber);
        }
            break;
            
        case 'b':
        { int iNumber(0);
            cin>>iNumber;
            cout<< "f.Buscar un dato en el vector"<<endl;
            lista.insert(lista.end(), iNumber);
        }
            break;
        case 'c':
            lista.erase(lista.begin());
            break;
        case 'd':
            lista.pop_back();
            break;
        case 'e':
            sort(lista.begin(),lista.end());
            break;
        case 'f':
        {
            int dato(0);
            cin>>dato;
            iter = find(lista.begin(), lista.end(), dato);
            if (iter != lista.end())
                cout<<"Si encontro el dato"<<endl;
            else
                cout<<"No encontro el dato"<<endl;
        }
            
            break;
    }
    
}while(cTipo != 'g');
    
    return 0;
}
