#ifndef CORRIENTE_H
#define CORRIENTE_H

#include<iostream>
using namespace std;

#include "../CC80217371/Cuenta/Cuenta.h"

class CuentaCorriente : public BaseCuenta
{
    public:
        CuentaCorriente(const double &, double);
        void abonar(double);
        void cargar(double);

    private:
        double valorTransaccion;
};
#endif