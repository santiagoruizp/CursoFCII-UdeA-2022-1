
#include "tarea2.h"

using namespace std;

int main()
{
    string cadena1, cadena2;
    cout<<"Ingrese una primer cadena de caracteres: ";
    getline(cin, cadena1);
    cout<<"Ingrese una segunda cadena de caracteres: ";
    getline(cin, cadena2);
    Cadenas variacionCadenas;
    variacionCadenas.RecibirCadenas(cadena1, cadena2);

    return 0;
}

