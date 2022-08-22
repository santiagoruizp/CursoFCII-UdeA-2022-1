// Nota: Se uso como base el programa fecha del profesor
// se añadieron dos funciones: bisiesto y dia siguiente
#include <iostream>

using namespace std;

#include "fecha.h"

int main()
{
    int dd, mm, aa;
    
    cout<<"ingrese una fecha con el formato: (dd, mm, aa): ";
    // el ususario ingresa una fecha separada por espacios 
    // (e.g. 2 2 2004, que equivale a 2 de febrero de 2004)
    cin>>dd>>mm>>aa;

    Fecha fecha( dd, mm, aa );
    fecha.imprimir();
    fecha.diaSig(dd, mm, aa); 
  
  return 0;
}
