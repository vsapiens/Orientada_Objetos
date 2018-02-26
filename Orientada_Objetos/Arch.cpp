#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream archEntrada;
    string sLine;
    archEntrada.open("Texto.txt");
    int iCounter = 1;
    while(!archEntrada.eof())
    {
        int  iNumber = 0, iSum = 0 ;
        getline(archEntrada, sLine);
        
        for(int iCounter = 0;iCounter < sLine.length() ; iCounter++)
        {
            if(sLine[iCounter] != 32)
            {
            iNumber = sLine[iCounter]-48;
            iSum += iNumber;
            }
        }
        
        cout<< iCounter << ": "<< iSum<<endl;
        iCounter++;
        
    }
    
    archEntrada.close();
    return 0;
};
