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
    string nombreMes();
    bool esBisiesto();
    
};
// como friend la sobrecarga del operador >
bool operator >(Fecha f1, Fecha f2)
{
    if(!(f1.aa > f2.aa))
    {
        if (!(f1.mm > f2.mm))
        {
           if (!(f1.dd > f2.dd))
           {
               return false;
           }
            else return true;
        }
        else return true;
    }
    return true;
}

// como friend la sobrecarga del operador <
bool operator <(Fecha f1, Fecha f2)
{
    if(!(f1.aa < f2.aa))
    {
        if (!(f1.mm < f2.mm))
        {
            if (!(f1.dd < f2.dd))
            {
                return false;
            }
            else return true;
        }
        else return true;
    }
    return true;
}
// como friend la sobrecarga del operador ==
bool operator == (Fecha f1, Fecha f2)
{
    return (f1.dd == f2.dd && f1.mm == f2.mm && f1.aa == f2.aa);
}
// como friend la sobrecarga del operador >=
bool operator >=(Fecha f1, Fecha f2)
{
    return (f1 > f2 || f1 == f2) ;
}
// como friend la sobrecarga del operador <=
bool operator <=(Fecha f1, Fecha f2)
{
    return  (f1 < f2 || f1 == f2);
}
string Fecha::nombreMes()
{
    string Mes;
    switch(mm)
    {
        case 1:
            Mes = "Ene";
            break;
        case 2:
            Mes = "Feb";
            break;
        case 3:
            Mes = "Mar";
            break;
        case 4:
            Mes = "Abr";
            break;
        case 5:
            Mes = "May";
            break;
        case 6:
            Mes = "Jun";
            break;
        case 7:
            Mes = "Jul";
            break;
        case 8:
            Mes = "Ago";
            break;
        case 9:
            Mes = "Sep";
            break;
        case 10:
            Mes = "Oct";
            break;
        case 11:
            Mes = "Nov";
            break;
        case 12:
            Mes = "Dic";
            break;
    }
    return Mes;
}
bool Fecha::esBisiesto()
{
    if(this->aa % 4 == 0 && (this->aa % 100 != 0 || this->aa % 400 == 0))
    {
        return true;
    }
    return false;
}
// como friend la sobrecarga del operador +
// que recibe como parametro una fecha y un numero entero
// que representa una cantidad de dias y regresa
// la fecha a la que se le agregaron los dias indicados
Fecha operator +(Fecha f1, int n)
{
    int iResult = 0;
    f1.dd += n;
    iResult = f1.dd;
    while(iResult > 0)
    {
        switch (f1.mm) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                if(f1.dd > 31)
                {
                    f1.dd -= 31;
                    f1.mm++;
                    iResult -= 31;
                }
                else iResult -= f1.dd;
                
                break;
                
            case 4:
            case 6:
            case 9:
            case 11:
                if(f1.dd > 30)
                {
                    f1.dd -= 30;
                    f1.mm++;
                    iResult -= 30;
                }
                else iResult -= f1.dd;
                break;
                
            case 2:
                if(f1.esBisiesto())
                {
                    if(f1.dd > 29)
                    {
                        f1.dd -= 29;
                        f1.mm++;
                        iResult -= 29;
                    }
                    else iResult -= f1.dd;
                    break;
                }
                else
                {
                    if(f1.dd > 28)
                    {
                        f1.dd -= 28;
                        f1.mm++;
                        iResult -= 28;
                    }
                    else iResult -= f1.dd;
                }
                break;
            case 12:
                if(f1.dd > 31)
                {
                    f1.dd -= 31;
                    f1.mm = 1;
                    f1.aa++;
                    iResult -= 31;
                }
                else iResult -= f1.dd;
                break;
        }
    }
    return f1;
}
// como friend la sobrecarga del operador >>
// que lee 3 valores enteros: dia, mes, anio con 4 digitos
istream& operator >>(istream& in,Fecha& f1)
{
    in>>f1.dd>>f1.mm>>f1.aa;
    return in;
}
// como friend la sobrecarga del operador <<
// que muestra la fecha en el formato dd/mm/aaaa
// no incluyas espacios ni enter
ostream& operator <<(ostream& out,Fecha& f1)
{
    out<<f1.dd<<"/"<<f1.mm<<"/"<<f1.aa;
    return out;
}
int main() {
    
    Fecha f1, f2, f3, f4, f5, f6;
    
    int op;
    // opcion 1 ==, 2 +, 3 <=, 4 >=, 5 >, 6 <
    cin >> op;
    
    cin >> f1 >> f2 >> f3;
    
    switch (op) {
            
        case 1: {
            if (f1 == f2) {
                cout << f1 << " si es igual a " << f2 << endl;
            } else {
                cout << f1 << " no es igual a " << f2 << endl;
            }
            if (f1 == f3) {
                cout << f1 << " si es igual a " << f3 << endl;
            } else {
                cout << f1 << " no es igual a " << f3 << endl;
            }
            if (f2 == f3) {
                cout << f2 << " si es igual a " << f3 << endl;
            } else {
                cout << f2 << " no es igual a " << f2 << endl;
            }
            break;
        }
        case 2: {
            f4 = f1 + 1;
            f5 = f2 + 5;
            f6 = f3 + 10;
            cout << f4 << endl;
            cout << f5 << endl;
            cout << f6 << endl;
            break;
        }
        case 3: {
            if (f1 <= f2) {
                cout << f1 << " es <= a " << f2 << endl;
            } else {
                cout << f1 << " no es <= a " << f2 << endl;
            }
            if (f1 <= f3) {
                cout << f1 << " es <= a " << f3 << endl;
            } else {
                cout << f1 << " no es <= a " << f3 << endl;
            }
            if (f2 <= f3) {
                cout << f2 << " es <= a " << f3 << endl;
            } else {
                cout << f2 << " no es <= a " << f3 << endl;
            }
            break;
        }
        case 4: {
            if (f1 >= f2) {
                cout << f1 << " es >= a " << f2 << endl;
            } else {
                cout << f1 << " no es >= a " << f2 << endl;
            }
            if (f1 >= f3) {
                cout << f1 << " es >= a " << f3 << endl;
            } else {
                cout << f1 << " no es >= a " << f3 << endl;
            }
            if (f2 >= f3) {
                cout << f2 << " es >= a " << f3 << endl;
            } else {
                cout << f2 << " no es >= a " << f3 << endl;
            }
            break;
        }
        case 5: {
            if (f1 > f2) {
                cout << f1 << " es > a " << f2 << endl;
            } else {
                cout << f1 << " no es > a " << f2 << endl;
            }
            if (f1 > f3) {
                cout << f1 << " es > a " << f3 << endl;
            } else {
                cout << f1 << " no es > a " << f3 << endl;
            }
            if (f2 > f3) {
                cout << f2 << " es > a " << f3 << endl;
            } else {
                cout << f2 << " no es > a " << f3 << endl;
            }
            break;
        }
        case 6: {
            if (f1 < f2) {
                cout << f1 << " es < a " << f2 << endl;
            } else {
                cout << f1 << " no es < a " << f2 << endl;
            }
            if (f1 < f3) {
                cout << f1 << " es < a " << f3 << endl;
            } else {
                cout << f1 << " no es < a " << f3 << endl;
            }
            if (f2 < f3) {
                cout << f2 << " es < a " << f3 << endl;
            } else {
                cout << f2 << " no es < a " << f3 << endl;
            }
            break;
            
        }
    }
    
    return 0;
}


