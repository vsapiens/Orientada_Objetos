#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string sNumber;
    string sEntero;
    string sDecimal;
    vector<int> iArrBinary;
    cin>> iNumber;
    
    for (int iCounter = 0; iCounter < sNumber.length(); ++iCounter)
    {
        if (sNumber[iCounter] == '.')
        {
            sEntero = sNumber.substr(0, iCounter-1);
            sDecimal = sNumber.substr(iCounter+1);
            break;
        }
    }
    
    int iEntero = stoi(sEntero);
    int iDecimal = stoi(sDecimal);
    
    while ()
    {
        iArrBinary.push_back(iNumber % 2);
        iNumber /= 2;
    }
    
    for (int iCounter = iArrBinary.size() - 1; iCounter >= 0; --iCounter)
    {
        cout << iArrBinary[iCounter];
    }
    
    cout << endl;
    
    return 0;
}
