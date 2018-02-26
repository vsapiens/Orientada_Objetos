//
//  Fecha.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/25/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h
class Fecha
{
public:
    Fecha();
    Fecha(int dd, int mm, int aa){this->dd = dd;this->mm = mm;this->aa = aa;};
    int getDay(){return dd;};
    int getMonth(){return mm;};
    int getYear(){return aa;};
    
    void setDay(int dd){this->dd = dd;};
    void setMonth(int mm){this->mm = mm;};
    void setYear(int aa){this->aa = aa;};
    
    void muestra();
private:
    int aa, mm, dd;
};
Fecha::Fecha()
{
    dd = 1;
    mm = 1;
    aa = 2018;
}
void Fecha::muestra()
{
    string Mes;
    switch(mm)
    {
        case 1:
            Mes = "Enero";
            break;
        case 2:
            Mes = "Febrero";
            break;
        case 3:
            Mes = "Marzo";
            break;
        case 4:
            Mes = "Abril";
            break;
        case 5:
            Mes = "Mayo";
            break;
        case 6:
            Mes = "Junio";
            break;
        case 7:
            Mes = "Julio";
            break;
        case 8:
            Mes = "Agosto";
            break;
        case 9:
            Mes = "Septiembre";
            break;
        case 10:
            Mes = "Octubre";
            break;
        case 11:
            Mes = "Noviembre";
            break;
        case 12:
            Mes = "Diciembre";
            break;
    }
    cout<<dd<<"-"<<Mes<<"-"<<aa<<endl;
}

#endif /* Fecha_h */
