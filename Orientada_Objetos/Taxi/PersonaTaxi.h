//
//  Persona.h
//  PersonaTaxi
//
//  Created by Yolanda MartÃ­nez on 5/4/15.
//  Copyright (c) 2015 Yolanda MartÃ­nez. All rights reserved.
//

#ifndef PersonaTaxi_h
#define PersonaTaxi_h

class Persona
{
public:
    Persona();
    Persona(string, string);
    void setNombre(string nom) { nombre = nom; }
    void setNumCel(string num) { numCel = num; }
    
    string getNombre() { return nombre; }
    string getNumCel() { return numCel; }
private:
    string nombre;
    string numCel;
};

Persona :: Persona() {
    nombre = "-";
    numCel = "0";
}

Persona :: Persona(string sNom, string sNum){
    nombre = sNom;
    numCel = sNum;
}

#endif
