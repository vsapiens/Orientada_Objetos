//
//  claseTiempo.cpp
//
//  Created by Yolanda Martinez on 3/9/17.
//  Copyright Â© 2017 com.itesm. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Implementa los funciones faltantes de la Clase Tiempo
 El valor de hora puede ser cualquier valor positivo
 El valor de minutos debe ser un valor entre 0 y 59
 Al realizar cualquier operaciÃ³n, el tiempo (hora y minutos) debe quedar con valores vÃ¡lidos
 */
class Tiempo {
    
public:
    Tiempo();
    Tiempo(int h, int m);
    void setHora(int h);
    void setMinu(int m);
    int getHora();
    int getMinu();
    void muestra();
    
    // Miembro de la clase. operador ++ incrementa el Tiempo en 1 minuto y regresa el tiempo
    Tiempo operator ++();
    //Friend. operador -- decrementa el Tiempo en 1 minuto y regresa el tiempo
    // si la hora es 0:0 y se pide decrementar, regresa 0:0
    friend Tiempo operator --(Tiempo &t1);
    // Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
    bool operator >(Tiempo);
    // Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
    Tiempo operator +(int);
    // Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
    friend Tiempo operator +(int, Tiempo);
    // Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
    Tiempo operator +(Tiempo);
    // Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
    friend void operator += (Tiempo &t1, Tiempo t2);
    
private:
    int hora;
    int minu;
};

Tiempo::Tiempo() {
    hora = 0;
    minu = 0;
}

Tiempo::Tiempo(int h, int m) {
    hora = h;
    minu = m;
}

void Tiempo::setHora(int h) {
    hora = h;
}

void Tiempo::setMinu(int m) {
    minu = m;
}

int Tiempo::getHora() {
    return hora;
}

int Tiempo::getMinu() {
    return minu;
}

void Tiempo::muestra() {
    cout <<hora<<":";
    if (minu<10)
        cout << "0" <<minu;
    else
        cout << minu;
}
// Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
Tiempo Tiempo:: operator + (int iNumber)
{
    int Horas = iNumber /60;
    
    int Minutos = iNumber % 60;
    Tiempo t1;
    t1.setHora(getHora());
    t1.setMinu(getMinu());
    
    if(Minutos + t1.getMinu() > 59)
    {
        if(Horas + t1.getHora() > 24)
        {
        t1.setMinu(Minutos+t1.getMinu()-60);
        t1.setHora(Horas +t1.getHora()-23);
        }
        else
        {
        t1.setMinu(Minutos+t1.getMinu()-60);
        t1.setHora(Horas + t1.getHora()+1);
        }
    }
    
    else
    {
        t1.setMinu(Minutos + t1.getMinu());
        t1.setHora(Horas + t1.getHora());
    }
    return t1;
}
Tiempo Tiempo:: operator ++()
{
    *this = *this + 1;
    return (*this);
}

// Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
bool Tiempo:: operator >(Tiempo t1)
{
 if(hora > t1.getHora())
 {
     return true;
 }
 if(hora == t1.getHora() && minu > t1.getMinu())
 {
    return true;
 }
 return false;
}

//Friend. operador -- decrementa el Tiempo en 1 minuto y regresa el tiempo
// si la hora es 0:0 y se pide decrementar, regresa 0:0
Tiempo operator --(Tiempo &t1)
{
    if(t1.getHora() == 0 && t1.getMinu() == 0)
    {
        return t1;
    }
    if(t1.getHora() != 0 && t1.getMinu() == 0)
    {
        t1.setHora(t1.getHora()-1);
        t1.setMinu(59);
        return t1;
    }
    else
    {
        t1.setHora(t1.getHora());
        t1.setMinu(t1.getMinu()-1);
        return t1;
    }
}
// Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
Tiempo operator +(int iNumber, Tiempo t1)
{
    return t1 + iNumber;
}
// Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
Tiempo Tiempo:: operator +(Tiempo t1)
{
    Tiempo t3;
    t3 = *this + (t1.getHora()*60 +t1.getMinu());
    return t3;
}
// Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
void operator += (Tiempo &t1, Tiempo t2)
{
    t1 = t1 + t2;
}

int main() {
    int t1h, t1m, t2h, t2m, t4h, t4m, t5h, t5m;
    char opcion;
    Tiempo t3, t6, t7(15, 59), t8(0,0), t9;
    
    // teclear los valores para tiempo 1, tiempo2, tiempo4 y tiempo5
    cin >> t1h >> t1m >> t2h >> t2m >> t4h >> t4m >> t5h >> t5m;
    Tiempo t1(t1h, t1m), t2(t2h, t2m);
    Tiempo t4(t4h, t4m), t5(t5h, t5m);
    
    cin >> opcion;
    
    switch (opcion) {
        case 'a':
            // + SUMA tiempo con tiempo miembro
            t3 = t1 + t2;
            t1.muestra();
            cout << endl;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            t6 = t4 + t5;
            t4.muestra();
            cout << endl;
            t5.muestra();
            cout << endl;
            t6.muestra();
            cout << endl;
            
            
            break;
            
        case 'b':
            // + SUMA tiempo con minutos miembro
            t3 = t2 + 10;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            t3 = t2 + 190;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            break;
            
        case 'c':
            // + SUMA minutos con tiempo friend
            t3 = 45 + t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            
            t3 = 90 + t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            break;
            
        case 'd':
            // ++ Incrementa 1 minuto   miembro
            t3 = ++t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            t3 = ++t7;
            t7.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            break;
            
        case 'e':
            // -- Decrementa 1 minuto   friend
            t3 = --t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            t3 = --t8;
            t3.muestra();
            cout << endl;
            t8.muestra();
            cout << endl;
            break;
            
        case 'f':
            // += SUMA tiempo con tiempo  friend
            t2 += t4;
            t2.muestra();
            cout << endl;
            t4.muestra();
            cout << endl;
            
            t7 += t5;
            t5.muestra();
            cout << endl;
            t7.muestra();
            cout << endl;
            break;
            
        case 'g':
            // > Regresa true si el primer tiempo es mayor que el segundo  miembro
            if (t1 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;
            
            if (t4 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;
            break;
    }
    return 0;
}
