#ifndef BANCA_H
#define BANCA_H


#include<iostream>

using namespace std;

class BaseCuenta
{
    public:
        BaseCuenta(const double &);// inicializa
        void validarSaldo(const double &);
        void abonar(double);
        void cargar(double);
        void getSaldo();
        double getValSaldo();

    private:
        double saldo;
};

#endif