//
//  Complejo.hpp
//  Orientada_Objetos
//
//  Created by Erick González on 2/2/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Complejo_hpp
#define Complejo_hpp

class Complejo
{
private:
    int real, imag;
    
public:
    Complejo();
    Complejo(int r, int i);
    
    friend Complejo operator+(Complejo, Complejo);
    friend Complejo operator-(Complejo, Complejo);
    friend Complejo operator =(Complejo, Complejo);
    
    int getReal() { return real; }
    void setReal(int r) { real = r; }
    int getImag() {return imag; }
    void setImag(int i) { imag = i; }
    void muestra();
    Complejo suma(Complejo c2);
    Complejo resta(Complejo c2);
    
};

Complejo operator+(Complejo c1, Complejo c2)
{
    
    Complejo c3(c1.getReal() + c2.getReal(),c1.getImag() + c2.getImag());
    
    return c3;
}
Complejo operator=(Complejo c1, Complejo c2)
{
    
    c1.setReal(c2.getReal());
    c1.setImag(c2.getImag());
    
    return c1;
}
Complejo operator-(Complejo c1, Complejo c2)
{
    Complejo c3(c1.getReal() - c2.getReal(),c1.getImag() - c2.getImag());
    
    return c3;
}
Complejo::Complejo()
{
    real = 0;
    imag = 0;
}

Complejo::Complejo(int r, int i)
{
    real = r;
    imag = i;
}

void Complejo::muestra() {
    cout << "("<< real<<", "<<imag<<")";
}

Complejo Complejo::suma(Complejo c2) {
    Complejo resp;
    
    resp.real = real + c2.real;
    resp.imag = imag + c2.imag;
    
    return resp;
}
Complejo Complejo::resta(Complejo c2) {
    Complejo resp;
    
    resp.real = real - c2.real;
    resp.imag = imag - c2.imag;
    
    return resp;
}

#endif /* Complejo_hpp */
