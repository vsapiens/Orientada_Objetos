#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int iIdentification,iQuantity;
double dPrize;
char cAnswer;


void readData()
{
    ofstream fileFactura;
    fileFactura.open("Factura.txt");
    do{
        cout<<"Teclea la clave "<<endl;
        cin>> iIdentification;
        cout<<"Teclea la cantidad "<<endl;
        cin>>iQuantity;
        cout<<"Teclea el precio "<<endl;
        cin>>dPrize;
        cout<< "¿Otro artículo? (s/n)"<<endl;
        cin>>cAnswer;
        fileFactura<< iIdentification << " " << iQuantity<< " "<< dPrize<<endl;
        
    } while(cAnswer == 's' || cAnswer == 'S');
    
    fileFactura.close();
}
void sendFile()
{
    int iNewIdentification,iNewQuantity;
    double dNewPrize;
    
    ofstream fileFacturaNueva;
    
    ifstream fileFacturaAnterior;
    
    fileFacturaNueva.open("Factura_Cliente.txt");
    
    fileFacturaAnterior.open("Factura.txt");
    
    fileFacturaNueva<< setw(40) <<"Factura" << '\n' <<"   Clave   "<<"Cantidad   "<< "Precio Unitario   "<<"Precio"<<endl;
    
    while(fileFacturaAnterior >> iNewIdentification >> iNewQuantity >> dNewPrize)
    {
        fileFacturaNueva<<setw(7) <<iNewIdentification<< setw(8) << iNewQuantity << setw(15) << dNewPrize<< setw(10)<< " $"<<iNewQuantity * dNewPrize << ".00"<<endl ;
    }
    fileFacturaAnterior.close();
    
    fileFacturaNueva.close();
    
    
}
int main()
{
    readData();
    sendFile();
        return 0;
}

