#include<iostream>

using namespace std;

#include"CuentaAhorros.h"

int main()
{
    CuentaAhorros cuentaAhorroCliente(200.0,10.0);
    cuentaAhorroCliente.abonar(150.00);
    cuentaAhorroCliente.cargar(80);
    cuentaAhorroCliente.getSaldo();   

    return 0;
}