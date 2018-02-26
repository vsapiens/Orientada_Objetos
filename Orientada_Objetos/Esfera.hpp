
#ifndef Esfera_hpp
#define Esfera_hpp

#include <stdio.h>
class Esfera
{
public:
    
    Esfera();
    
    double calcVolum();
    
    double calcArea();
    
    double getRadio();
    
    void setRadio(double);
    
private:
    
    double radio;
    
    double pi = 3.1415926535897;
    
};
Esfera::Esfera()
{
    radio = 1;
}
double Esfera::calcVolum()
{
    return (4*pi*radio*radio*radio)/3;
}
double Esfera::calcArea()
{
    return (4*pi*radio*radio);
}
double Esfera::getRadio()
{
    return radio;
}
void Esfera::setRadio(double Rad)
{
    radio = Rad;
}
#endif /* Esfera_hpp */
