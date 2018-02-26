#ifndef Evento_hpp
#define Evento_hpp

#include <stdio.h>
#include "Reloj.hpp"
class Evento
{
    
public:
    Evento();
    Evento(Reloj, int, string);
    void setInicio(Reloj);
    void setDuracion(int);
    void setAsunto(string);
    
    Reloj getInicio();
    int getDuracion();
    string getAsunto();
    
    
private:
    int duracion;
    string asunto;
    Reloj inicio;
};
Evento::Evento()
{
    inicio.setHora(8);
    inicio.setMinu(0);
    duracion = 30;
    asunto = "Evento";
}
Evento::Evento(Reloj Tiemp, int Dur, string Asunt)
{
    inicio =  Tiemp;
    duracion = Dur;
    asunto = Asunt;
}

void Evento::setInicio(Reloj inicio)
{
    this->inicio = inicio;
    
}
void Evento::setDuracion(int duracion)
{
    this->duracion =  duracion;
}
void Evento::setAsunto(string asunto)
{
    this->asunto = asunto;
}
Reloj Evento::getInicio()
{
    return inicio;
}
int Evento::getDuracion()
{
    return duracion;
}
string Evento::getAsunto()
{
    return asunto;
}

#endif /* Evento_hpp */
