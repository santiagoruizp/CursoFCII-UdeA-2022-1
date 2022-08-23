#include <iostream>
using std::cout;
using std::endl;

using namespace std;

#include "fecha.h"

int main()
{
    const int maxdias = 16;

    Fecha d(12, 24, 2004); // objeto d de la clase Fecha

    for (int loop = 1; loop <= maxdias; ++loop)
    {
        d.imprimir(); //llamamos la funcion imprimir
        d.diaSig(); // llamamos  a la funcion dia siguiente
    } // final del for

    cout << endl;

    return 0;
} // fin del main