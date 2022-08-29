#include<iostream>

using namespace std;

#include"CuentaCorriente.h"

int main()
{
    CuentaCorriente cuentaCorrienteCliente(200.0,10.0);
    cuentaCorrienteCliente.abonar(150.00);
    cuentaCorrienteCliente.cargar(80);
    cuentaCorrienteCliente.getSaldo();   

    return 0;
}