#include<iostream>
using namespace std;

#include "CuentaAhorros.h"

//constructor
CuentaAhorros::CuentaAhorros(const double &saldoInit, double tasa) 
    : BaseCuenta(saldoInit)
{
    tasaInteres = tasa;
}
void CuentaAhorros::calcularInteres(double tasa) 
{
    double ValtasaInteres, interesesGen;
    ValtasaInteres=tasaInteres*0.01;
    interesesGen = ValtasaInteres * BaseCuenta::getValSaldo();
    BaseCuenta::abonar(interesesGen);
    cout<<"Los intereses generados a una tasa "<<tasaInteres<<"% "
        <<" es: "<<interesesGen<<endl;    
    return;
}
