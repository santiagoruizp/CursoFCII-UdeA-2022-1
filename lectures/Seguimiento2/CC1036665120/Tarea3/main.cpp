/*
a) Defina una clase llamada "Fecha".
b) En la clase Fecha definida, debe incluir una función "diaSig()" que incremente una fecha en un día.
Pruebe su función para asegurarse que incrementa de manera correcta los dias en un nuevo mes y en un nuevo año.
c) Escriba un programa que pruebe su clase (se refiere a un main).
*/


#include "fechaSiguiente.h"

int main()
{


    // 28 de Febrero de un año NO bisiesto
    std::cout << "28 de Febrero de un año NO bisiesto: ";
    fechaSiguiente pruebaFecha( 28, 2, 2003 );
    pruebaFecha.diaSig();
    pruebaFecha.imprimir();

    // 28 de Febrero de un año bisiesto
    std::cout << "28 de Febrero de un año bisiesto: ";
    fechaSiguiente pruebaFecha2( 28, 02, 2000 );
    pruebaFecha2.diaSig();
    pruebaFecha2.imprimir();

    // 29 de Febrero de un año bisiesto
    std::cout << "29 de Febrero de un año bisiesto: ";
    fechaSiguiente pruebaFecha3( 29, 02, 2000 );
    pruebaFecha3.diaSig();
    pruebaFecha3.imprimir();
    

    // 31 de Diciembre
    std::cout << "31 de Diciembre: ";
    fechaSiguiente pruebaFecha4( 31, 12, 2000 );
    pruebaFecha4.imprimir();
    pruebaFecha4.diaSig();
    pruebaFecha4.imprimir();

    
    // Datos incorrectos
    std::cout << "Datos incorrectos: ";
    fechaSiguiente pruebaFecha5( 37, 13, -2003 );
    pruebaFecha5.diaSig();
    pruebaFecha5.imprimir();


    return 0;
}
