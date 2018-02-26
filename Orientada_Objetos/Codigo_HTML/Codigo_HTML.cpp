/**
 Erick Francisco Gonzalez Martinez A01039859
 Programación Orientada a Objetos
 Proyecto Parcial #1
 Version 3.2.1
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string sStyle = "<style> body {background-color: black;} h1   {color: white;} h2   {color: white;} h3   {color: white;} p    {color: white;} </style>";

string sEndHtml = "</html>";

bool bRead = true;

//String que contiene los tipos de tags que se van a leer

string sType[7]
{
    "progName",
    "author",
    "date",
    "funcName",
    "desc",
    "param",
    "return",
};

/**
 @funcName checkType
 @desc Función que identifica el tag que se utilizará
 @author Erick Gonzalez
 @date 3 de Febrero del 2018
 @param Linea que se checara dependiendo del tipo
 */

int checkType(string sLine)
{
    int iNumber = 0 ;
    for(int iCounter = 0; iCounter < 7 ;iCounter++)
    {
        if(sLine == sType[iCounter])
        {
            iNumber = iCounter;
            return iNumber + 1;
        }
    }
    return iNumber;
}
/**
 @funcName checkBool
 @desc Función que determina si ya empezo el espacio de comentarios
 @param sWord: palabra que se va a checar
 @date 9 de Febrero del 2018
 */
void checkBool(string sWord)
{
    if(sWord == "/**")
    {
        bRead = true;
    }
    if(sWord[0] == '*')
    {
        bRead = false;
    }
    
}
/**
 @funcName readCppFile
 @desc Función lee los comentarios del programa y los guarda en el programa
 @author Erick Gonzalez
 @param none
 @date 2 de Febrero del 2018
 @return none
 */
void readCppFile()
{
    ifstream archEntrada;
    ofstream archSalida;
    string sComment, sComment2,sName, sWord, sType, sHTML;
    int iNumber = 0;
    
    cout<< "Introducir el nombre de su archivo \n";
    
    getline(cin, sName);
    
    string sStartHtml = "<!DOCTYPE html> <html> <head> <title> Documentación del archivo " + sName + " </title> </head> <body> <h1> Programa: " + sName +"</h1> <body>";
    
    sName += ".cpp";
    
    archEntrada.open(sName);
    
    cout<<sName<<endl;
    
    sName.erase(sName.length()-4, 4);
    
    sName += ".html";
    cout<<sName<<endl;
    
    archSalida.open(sName);
    archSalida<< sStartHtml<< sStyle;
    while(!archEntrada.eof())
    {
        
        sComment = "";
        sComment2 = "";
        
        archEntrada >> sWord;
        
        while(getline(archEntrada,sComment, '@') && bRead)
        {
            for(int iCounter = 0; iCounter< sComment.length();iCounter++)
            {
                if(sComment[iCounter] == '*')
                {
                    sComment.erase(sComment.begin()+iCounter, sComment.end());
                }
            }
            if(sWord == "*/")
            {
                break;
            }
        
            iNumber = 0;
            
            for(int iCounter = 0; iCounter < 6; iCounter++)
            {
                iNumber = checkType(sWord);
                
            }
            
            archEntrada>>sWord;
            checkBool(sWord);
            
            switch(iNumber)
            {
                    //Null
                case 0 :
                    if(sWord == "/**")
                    {
                        break;
                    }
                    checkBool(sWord);
                    sComment += sWord;
                    break;
                    //Program name
                case 1 :
                    sComment = " <hr><h1> Program Name: </h1> <p> " + sComment +" </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    
                    //Author
                    
                case 2 :
                    sComment = " <h3> Author: </h3> <p>" + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    //Date
                    
                case 3 :
                    sComment = " <h3> Date: </h3> <p> " + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    
                    //Function Name
                case 4 :
                    sComment = " <hr> <h2> Function Name: </h2> <p>" + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    //Description
                    
                case 5 :
                    sComment = " <h3> Description: </h3> <p> " + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    //Parameters
                case 6 :
                    sComment = " <h3> Parameters: </h3> <p> " + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
                    
                    //Return
                case 7 :
                    sComment = " <h3> Return: </h3> <p>" + sComment + " </p>";
                    archSalida<< sComment;
                    sComment = "";
                    break;
            }
        }
    }
    
    archSalida<< sEndHtml;
    
    archEntrada.close();
    
    archSalida.close();
}

/**
 @funcName main
 @desc Función llama y ejecuta las funciones del archivo
 @author Erick Gonzalez
 @date 2 de Febrero del 2018
 @param none
 @return 0 if the code executes
 */
int main()
{
  readCppFile();
    return 0;
}
