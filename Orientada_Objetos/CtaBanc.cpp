//
//  CuentaBanc.cpp
//  Orientada_Objetos
//
//  Created by Erick González on 1/26/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
using namespace std;

#include "CtaBanc.h"
#include "Chequera.h"
/* int main ()
{
    Chequera ch;
    CtaBanc cb;
    int numCta;
    double saldo, com;
    
    cout << "Teclea el numero de cuenta de la cuenta bancaria ";
    cin >> numCta;
    
    cb.setNumCuenta(numCta);
    
    cout << "Teclea el saldo inicial para el cliente de la cuenta bancaria ";
    cin >> saldo;
    
    cb.setSaldo(saldo);
    
    cout << "Teclea el numero de cuenta de la chequera ";
    cin >> numCta;
    
    ch.setNumCuenta(numCta);
    
    cout << "Teclea el saldo inicial para el cliente de la chequera ";
    cin >> saldo;
    
    ch.setSaldo(saldo);
    
    cout << "Teclea  la comision por retiro de la chequera ";
    cin >> com;
    
    ch.setComision(com);
    
    cout << "Los datos de la cuenta bancaria son " << endl;
    cb.mostrar();
    
    cout << "Los datos de la cuenta de cheques son " << endl;
    ch.mostrar();
    
    cb.retira(100);
    ch.retira(100);
    
    cout << "despues de retirar datos de cuenta bancaria " << endl;
    cb.mostrar();
    
    cout << "despues de retirar datos de chequera " << endl;
    ch.mostrar();
    
}
 */
#include <iostream>
using namespace std;

#include "Chequera.h"

int main()
{
    CtaBanc *listaCtas[20];
    int sizeCtas;
    char tipoCta;
    int numCta;
    double saldoI, com, dinero;
    char opcion;
    
    cout << "Cuantas cuentas bancarias hay? ";
    cin >> sizeCtas;
    
    for (int c = 0; c < sizeCtas; c++)
    {
        cout << "quieres una cuenta bancaria o de cheques? (b ó c) ";
        cin >> tipoCta;
        
        cout << "Numero de cuenta? ";
        cin >> numCta;
        
        cout << "Saldo inicial? ";
        cin >> saldoI;
        
        if (tipoCta == 'c')
        {
            cout << "Comision por hacer retiro? ";
            cin >> com;
            listaCtas[c] = new Chequera(numCta,saldoI,com);
            
        }
        else
        {
            listaCtas[c] = new CtaBanc(numCta,saldoI);
        }
    }
    
    
    do
    {
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "a) depositar " << endl;
        cout << "b) retirar " << endl;
        cout << "c) consultar saldo " << endl;
        cout << "d) terminar " << endl;
        cout << "opcion ->";
        cin >> opcion;
        
        switch (opcion) {
            case 'a':
            {
                cout << "teclea el numero de cuenta ";
                cin >> numCta;
                cout << "cuando vas a depositar? ";
                cin >> dinero;
                for(int iCounter = 0; iCounter < sizeCtas; iCounter++)
                {
                  if(listaCtas[iCounter]->getNumCuenta()== numCta)
                  {
                      listaCtas[iCounter]->setSaldo(listaCtas[iCounter]->getSaldo()+dinero);
                  }
                }
                break;
            }
                
            case 'b':
            {
                cout << "teclea el numero de cuenta ";
                cin >> numCta;
                cout << "cuando vas a retirar? ";
                cin >> dinero;
                for(int iCounter = 0; iCounter < sizeCtas; iCounter++)
                {
                    if(listaCtas[iCounter]->getNumCuenta() == numCta)
                    {
                        listaCtas[iCounter]->retira(dinero);
                    }
                }
                break;
            }
                
            case 'c':
            {
                cout << "teclea el numero de cuenta ";
                cin >> numCta;
                for(int iCounter = 0; iCounter < sizeCtas; iCounter++)
                {
                    if(listaCtas[iCounter]->getNumCuenta() == numCta)
                    {
                        listaCtas[iCounter]->mostrar();
                    }
                }
                
                break;
            }
        }
        
    } while (opcion != 'd');
    
    return 0;
}

