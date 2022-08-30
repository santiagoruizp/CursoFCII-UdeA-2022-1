#include<iostream>
#include <string>

using namespace std;

class Cadenas
{
    public:

    void Evalua_mayor(string, string);//Para evaluar cual es mayor
    string lowercase(string);//transforma todos los caracteres a minusculas
    string SonantesUpper(string);//convierte sonantes a mayusculas
    string ConsonantesUpper(string);//convierte consonantes a mayusculas
    void cadenasOriginales(string, string);// imprime las cadenas originales
    string RecibirCadenas(string, string);// funcion de ingreso
    string concatena(string, string);//concatena las cadenas con los cambios respectivos
    string inversionCadena(string);//invierte la cadena concatenada
};