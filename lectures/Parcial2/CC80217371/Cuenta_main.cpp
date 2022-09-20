#include<iostream>

using namespace std;

#include "Cuenta.h"

int main()
{
    BaseCuenta miCuenta(100.00);
    miCuenta.abonar(200.00);
    miCuenta.getSaldo();

    return 0;
}