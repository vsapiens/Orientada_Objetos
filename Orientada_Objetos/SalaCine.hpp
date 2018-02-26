#ifndef SalaCine_hpp
#define SalaCine_hpp

#include <stdio.h>

class SalaCine
{
public:
    
    void setPelicula(string);
    void setLugares(int );
    
    int getLugares();
    string getPelicula();
    
    void compraBoleto(int );
    
private:
    
    int lugares;
    string pelicula;

};
string SalaCine::getPelicula()
{
    return pelicula;
}
int SalaCine::getLugares()
{
    return lugares;
}
void SalaCine::setPelicula(string sPeli)
{
    pelicula = sPeli;
}
void SalaCine::setLugares(int iLug)
{
    lugares = iLug;
}
void SalaCine::compraBoleto(int iLug)
{
    lugares -= iLug;
}
#endif /* SalaCine_hpp */
