#include <iostream>
#include <cstring>

using namespace std;
void display(char palabra1[11], char palabra2[11], char palabra3[11])
{
cout<<palabra1<<" "<<palabra2<<" "<<palabra3<<endl;
}

void ordenar(char pal1[11], char pal2[11], char pal3[11])
{
    if(strcmp(pal1, pal2)> 0 && strcmp(pal1, pal3)> 0)
    {
        if(strcmp(pal3, pal2)> 0)
        {
            display(pal2, pal3, pal1);
        }
        else
        {
            display(pal3, pal2, pal1);
        }
    }
    else if (strcmp(pal1, pal2)< 0 && strcmp(pal1, pal3)< 0)
    {
        if(strcmp(pal3, pal2)> 0)
        {
            display(pal1, pal2, pal3);
        }
        else
        {
            display(pal1, pal3, pal2);
        }
    }
    else if(strcmp(pal1, pal2) < 0 && strcmp(pal1, pal3)> 0)
    {
        display(pal3, pal1, pal2);
    }
    else if(strcmp(pal1, pal2) > 0 && strcmp(pal1, pal3)< 0)
    {
        display(pal2, pal1, pal3);
    }
    
    //Cases if repeated
    else if(strcmp(pal1, pal2) == strcmp(pal1, pal3) && strcmp(pal2, pal3) == strcmp(pal1, pal3))
    {
        display(pal1, pal2, pal3);
    }
    else if(strcmp(pal1, pal2) == 0 || strcmp(pal2, pal3) == 0 || strcmp(pal1, pal3) == 0)
    {
        if(strcmp(pal1, pal2) == 0 && strcmp(pal2,pal3) > 0)
        display(pal3, pal1, pal2);
        
        else if(strcmp(pal1, pal3) == 0 && strcmp(pal1,pal2) > 0)
        display(pal2, pal3, pal1);
        
        else if(strcmp(pal2, pal3) == 0 && strcmp(pal2,pal1) > 0)
            display(pal1, pal3, pal2);
        
        else if(strcmp(pal1, pal2) == 0 && strcmp(pal2,pal3) > 0)
            display(pal1, pal2, pal3);
        
        else if(strcmp(pal1, pal2) == 0 && strcmp(pal2,pal3) < 0)
            display(pal1, pal2, pal3);
        
        else if(strcmp(pal1, pal3) == 0 && strcmp(pal1,pal2) < 0)
            display(pal1, pal3, pal2);
        
        else if(strcmp(pal1, pal3) == 0 && strcmp(pal1,pal2) < 0)
            display(pal2, pal1, pal3);
        
        else if(strcmp(pal2, pal3) == 0 && strcmp(pal2,pal1) < 0)
            display(pal1, pal2, pal3);
    }
}


void casos()
{
    int iCasos = 0;
    char pal1[11], pal2[11], pal3[11];
    int iCounter = 0;
    cin>> iCasos;
    while(iCounter != iCasos)
    {
    cin>>pal1>>pal2>>pal3;
    ordenar(pal1, pal2, pal3);
    iCounter++;
    }
}

int main()
{
    casos();
    return 0;
}
