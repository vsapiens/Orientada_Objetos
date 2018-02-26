#include <iostream>
#include <string>
using namespace std;

string getString()
{
    string sPhrase;
    
    getline(cin,sPhrase);
    
    return sPhrase;
};

void reverseString(string sPhrase)
{
    string sReverseString;
    for(int iCounter = 0; iCounter < sPhrase.length(); iCounter++)
    {
     if(sPhrase[iCounter] == ' ')
     {
        
     }
    }
};


int main()
{
    string sPhrase;
    sPhrase = getString();
    reverseString(sPhrase);
    return 0;
}
