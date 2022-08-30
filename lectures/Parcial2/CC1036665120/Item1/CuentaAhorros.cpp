#include "CuentaAhorros.h"


CuentaAhorros::CuentaAhorros(const double & saldo, const double & tasa) : Cuenta(saldo)
{
    this->tasaInteres = tasa;

}

CuentaAhorros::~CuentaAhorros()
{

}

// ---------------------------------
// ----------- FUNCIONES -----------
// ---------------------------------

double CuentaAhorros::calcularInteres()
{
    return this->tasaInteres * this->getSaldo();
}