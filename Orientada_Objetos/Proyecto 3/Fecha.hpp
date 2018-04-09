//
//  Fecha.hpp
//  Orientada_Objetos
//
//  Created by Erick González on 4/9/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Fecha_hpp
#define Fecha_hpp
#include <iostream>
using namespace std;
class Fecha
{
    // como friend la sobrecarga del operador >
    friend bool operator >(Fecha, Fecha);
    // como friend la sobrecarga del operador >=
    friend bool operator >=(Fecha, Fecha);
    // como friend la sobrecarga del operador <
    friend bool operator <(Fecha, Fecha);
    // como friend la sobrecarga del operador <=
    friend bool operator <=(Fecha, Fecha);
    // como friend la sobrecarga del operador ==
     friend bool operator == (Fecha, Fecha);
    // como friend la sobrecarga del operador +
    // que recibe como parametro una fecha y un numero entero
    // que representa una cantidad de dias y regresa
    // la fecha a la que se le agregaron los dias indicados
    friend Fecha operator +(Fecha, int);
    // como friend la sobrecarga del operador >>
    // que lee 3 valores enteros: dia, mes, anio con 4 digitos
    friend istream& operator >>(istream &,Fecha &);
    // como friend la sobrecarga del operador <<
    // que muestra la fecha en el formato dd/mm/aaaa
    // no incluyas espacios ni enter
   friend ostream& operator <<(ostream &,Fecha &);
    
public:
    Fecha() { dd = 0; mm = 0; aa = 0; }
    Fecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
    int getDia() { return dd; }
    int getMes() { return mm; }
    int getAnio() { return aa; }
    void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
private:
    // atributos
    int dd, mm, aa;
};
// como friend la sobrecarga del operador >
bool operator >(Fecha f1, Fecha f2)
{
    return ((f1.dd == f2.dd) && (f1.mm == f2.mm) && (f1.aa == f2.aa));
}
// como friend la sobrecarga del operador >=
bool operator >=(Fecha f1, Fecha f2)
{
    return (f1.aa>= f2.aa) ? (f1.mm>= f2.mm) ? (f1.dd>= f2.dd) ? true: true : true: false;
}
// como friend la sobrecarga del operador <
bool operator <(Fecha f1, Fecha f2)
{
    return (f1.aa < f2.aa) ? (f1.mm < f2.mm) ? (f1.dd < f2.dd) ? true: true : true: false;
}
// como friend la sobrecarga del operador <=
bool operator <=(Fecha f1, Fecha f2)
{
    return (f1.aa<= f2.aa) ? (f1.mm<= f2.mm) ? (f1.dd>= f2.dd) ? true: true : true: false;
}
// como friend la sobrecarga del operador ==
bool operator == (Fecha f1, Fecha f2)
{
    return ((f1.dd == f2.dd) && (f1.mm == f2.mm) && (f1.aa == f2.aa));
}
// como friend la sobrecarga del operador +
// que recibe como parametro una fecha y un numero entero
// que representa una cantidad de dias y regresa
// la fecha a la que se le agregaron los dias indicados
Fecha operator +(Fecha f1, int n)
{
    
    
    if(!(f1.aa % 4 && f1.mm % 12-3))
    
    
    return f1;
}
// como friend la sobrecarga del operador >>
// que lee 3 valores enteros: dia, mes, anio con 4 digitos
istream& operator >>(istream& in,Fecha& f1)
{
    int iNumber;
    in>> iNumber;
    in>>f1.dd>>iNumber;
    in>>f1.mm>>iNumber;
    in>>f1.aa>>iNumber;
    return in;
}
// como friend la sobrecarga del operador <<
// que muestra la fecha en el formato dd/mm/aaaa
// no incluyas espacios ni enter
ostream& operator <<(ostream& out,Fecha& f1)
{
    out<<f1.dd<<"/"<<f1.mm<<"/"<<f1.aa<<"/"<<endl;
    return out;
}
#endif /* Fecha_hpp */
