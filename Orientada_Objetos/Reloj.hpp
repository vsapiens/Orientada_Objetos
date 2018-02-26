//
//  Header.h
//  Orientada_Objetos
//
//  Created by Erick González on 2/16/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Header_hpp
#define Header_hpp
class Reloj
{
public:
    
    Reloj();
    Reloj(int, int);
    
    
    void setHora(int);
    void setMinu(int);
    
    
    int getHora();
    int getMinu();
    
private:
    
    int hora,minu;
};

Reloj::Reloj()
{
    hora = 12;
    minu = 00;
}

Reloj::Reloj(int Hor, int Minuto)
{
    hora = Hor;
    minu = Minuto;
}
void Reloj::setHora(int Hor)
{
    hora = Hor;
}
void Reloj::setMinu(int Minuto)
{
    minu = Minuto;
}
int Reloj::getMinu()
{
    return minu;
}
int Reloj::getHora()
{
    return hora;
}

#endif /* Header_hpp */
