#include <iostream>
#include <string>

using namespace std;

string getString()
{
    string myString;
    
    getline(cin, myString);
    
    return myString;
}


void findLastTwoWords(string myString)
{
    int iPosition;
    
    int iSpaceCounter = 0;
    
    unsigned long int iLength = myString.length();
    
    for(int iCounter = iLength-1; iCounter != 0 && iSpaceCounter != 2; iCounter--)
    {
        if(myString[iCounter] == ' ')
        {
            iSpaceCounter++;
        }
        
        if(iSpaceCounter == 2)
        {
            iPosition = iCounter;
        }
        
    }
    
    switch(iSpaceCounter)
    {
        case 1:
            
            cout<< myString<<endl;
            
            break;
            
        default:
            
            cout<< myString.substr(iPosition+1) <<endl;
            
            break;
    }
}

int main()
{
    
    string myString;
    
    myString = getString();
    
    findLastTwoWords(myString);
    
    return 0;
}
