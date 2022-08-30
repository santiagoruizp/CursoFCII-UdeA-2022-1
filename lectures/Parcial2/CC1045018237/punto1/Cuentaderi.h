#ifndef CUENTADERI_H
#define CUENTADERI_H

#include "Cuenta.h"  // clase base Cuenta

class CuentaAhorros : public Cuenta
{
public:
    CuentaAhorros( double, double ); // El constructor de CuentaAhorros. debe recibir el saldo inicial,
                                      // así como un valor inicial para la tasa de interés de CuentaAhorros.
    double calcularInteres();         // Devuelve el monto de interés

private:
    double tasaInteres; //

}; // finde la clase heredada CuentaAhorros

#endif