#ifndef CUENTA_H
#define CUENTA_H

#include "Cuenta.h"

class CuentaAhorros : public Cuenta
{
private:
    double saldo;
    double tasaInteres;

public:
    CuentaAhorros( const double &, const double & );
    ~CuentaAhorros();

    double calcularInteres();
};

#endif

