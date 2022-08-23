#include<iostream>
#include<string>
#include "tarea2.h"

using namespace std;



/*void Evalua_mayor(string, string);
string RecibirCadenas(string, string);
string lowercase(string);
string SonantesUpper(string);
string ConsonantesUpper(string);*/

string Cadenas::RecibirCadenas(string stringOne, string stringTwo)
{    
    cadenasOriginales(stringOne,stringTwo); //Funcion solicitada

    // Muestra que cadena es mayor, aparece cometado pues en principio no se pide que se muestre al usuario
    //Evalua_mayor(stringOne,stringTwo);
    string variaCadena1=SonantesUpper(stringOne); // nueva cadena con cambio sonantes a mayusculas
    string variaCadena2=ConsonantesUpper(stringTwo); // nueva cadena con cambio consonantes a mayusculas
    string concStr1Str2=concatena(variaCadena1, variaCadena2); // nueva cadena concatena las dos anteriores variaciones
    string cadenainvertida=inversionCadena(concStr1Str2); // nueva cadena, inversion de la cadena concatenada

    cout<<"\nVariacion de la primer cadena ingresada: "<<variaCadena1<<endl;
    cout<<"Variacion de la segunda cadena ingresada: "<<variaCadena2<<endl;
    cout<<"La concatenacion de las cadenas anteriores es : "<<concStr1Str2<<endl;
    cout<<"La cadena concatenda e invertida es : "<<cadenainvertida<<endl;
}


void Cadenas::cadenasOriginales(string str1, string str2)//Muestra las cadenas ingresadas originalmente
{
    cout<<"\n\nLa primer cadena ingresada es: "<<str1<<endl;
    cout<<"La segunda cadena ingresada es: "<<str2<<endl;
}


void Cadenas::Evalua_mayor(string str1, string str2)//convierte en minuscula para luego comparar
{
    string strlower1=lowercase(str1);
    string strlower2=lowercase(str2);

    if (strlower1==strlower2)
        cout<<"Las cadenas ingresadas son iguales "<<endl;
    else
        {
            if (strlower1>strlower2)
                cout<<"La primer cadena ingresada es mayor "<<endl;
            else
                cout<<"La segunda cadena ingresada es mayor"<<endl;
        }
}
string Cadenas::lowercase(string str)/*convierte en minuscula todos los caracteres, 
facilita el proceso de comparacion y conversion a mayuscalas dependiente de caso*/
{
int i;
    string strlower;
    for (i=0;i<str.length();i++)
        {
            str[i]=tolower(str[i]);
            strlower+=str[i];
        }
    return strlower;
}

string Cadenas::SonantesUpper(string str)//Convierte las sonantes a mayusculas
{
    string cadena=lowercase(str);
    int logCadena = cadena.length();
    string cadenaSonUp;
    int i;
    for (i=0;i<logCadena;i++)
        {
            if (cadena[i]=='a' || cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u')
                cadena[i]=toupper(cadena[i]);

            cadenaSonUp+=cadena[i];
        }
    return cadenaSonUp;
}

string Cadenas::ConsonantesUpper(string str) //Convierte las consonantes a mayusculas
{
    string cadena=lowercase(str);
    int logCadena = cadena.length();
    string cadenaConsonUp;
    int i;
    for (i=0;i<logCadena;i++)
        {
            if (cadena[i] =='a' || cadena[i] =='e' || cadena[i] =='i' || cadena[i] =='o' || cadena[i] =='u')//descarta las sonantes
                cadena[i]=cadena[i];
            else
                cadena[i]=toupper(cadena[i]);
                
            cadenaConsonUp+=cadena[i];
        }
    return cadenaConsonUp;
}

string Cadenas::concatena(string str1, string str2)//concatena las dos cadenas
{
    string CadenaConcatenda= str1 + " " + str2;
    return CadenaConcatenda;
}

string Cadenas::inversionCadena(string str) //invierte las cadenas (e.g numero--> oremun)
{
    int i;
    const int cadenaLen = str.length()+1;
    string inversion;
    for (i=cadenaLen; i>0; i--)
        inversion+=str[i-1];

    return inversion;
}
