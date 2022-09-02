#include<iostream>
using namespace std;

#include "CuentaCorriente.h"

//constructor
CuentaCorriente::CuentaCorriente(const double &saldoInit, double costo) 
    : BaseCuenta(saldoInit)
{
    valorTransaccion=costo;
}
void CuentaCorriente::abonar(double valorAbonar)
{
    double valIngreso;
    valIngreso=valorAbonar-valorTransaccion;
    BaseCuenta::abonar(valIngreso);
    return;
}

void CuentaCorriente::cargar(double valorRetirar)
{
    double debitarCuenta;
    debitarCuenta=valorRetirar+valorTransaccion;
    if (debitarCuenta>getValSaldo())
        cout<<"No cuenta con suficientes fondos para efectuar la transccion"<<endl;
    else    
        BaseCuenta::cargar(debitarCuenta);
    return;
}