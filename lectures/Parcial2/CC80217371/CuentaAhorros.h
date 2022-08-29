#ifndef AHORROS_H
#define AHORROS_H

#include<iostream>
using namespace std;

#include "../CC80217371/Cuenta/Cuenta.h"

class CuentaAhorros : public BaseCuenta
{
    public:
        CuentaAhorros(const double &, double);
        void calcularInteres(double);

    private:
        double tasaInteres;
};
#endif