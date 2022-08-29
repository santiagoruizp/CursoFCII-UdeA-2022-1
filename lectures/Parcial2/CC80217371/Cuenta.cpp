#include<iostream>

using namespace std;

#include "Cuenta.h"

BaseCuenta::BaseCuenta(const double &saldoInit)
{
    validarSaldo(saldoInit);
}

void BaseCuenta::validarSaldo(const double &saldoInit)// verifica que el saldo sea correcto
{
    if (saldoInit<0.0)
    {
        cout<<"Saldo inicial invalido "<<endl;
        saldo=0.0;
    }
    else
        saldo=saldoInit;
}

void BaseCuenta::abonar(double cantidad)
{
    saldo+=cantidad;
}

void BaseCuenta::cargar(double cantidad) // si es posible hace el retiro
{
    if (saldo>=cantidad)
        saldo-=cantidad;
    else
        cout<<"No con cuenta suficientes fondos para efectuar la transccion"<<endl;
}

void BaseCuenta::getSaldo()// imprime el saldo
{
    cout<<"Su saldo actual es: "<<saldo<<endl;
}

double BaseCuenta::getValSaldo()// para luego usar con las herencias
{
    return saldo;
}