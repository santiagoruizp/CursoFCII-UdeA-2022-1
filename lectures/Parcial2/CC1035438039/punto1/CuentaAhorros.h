//
// Created by kevin on 23/08/22.
//

#ifndef CUENTAS_CUENTAAHORROS_H
#define CUENTAS_CUENTAAHORROS_H

#include "./Cuenta.h"

class CuentaAhorros: public Cuenta{
public:
    explicit CuentaAhorros(double saldoCuenta, double tasaIntereses);
    double calcularIntereses();

private:
    double tasaIntereses{};

};


#endif //CUENTAS_CUENTAAHORROS_H
