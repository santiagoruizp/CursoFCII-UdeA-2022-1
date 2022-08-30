#include <iostream>
#include <stdexcept>

#include "CuentaCheque.h"
using namespace std;

// inicilizamos el constructor saldo y transacción
CuentaCheque::CuentaCheque( double Saldoinicial, double tarifa )
    :Cuenta( Saldoinicial )
{
    if (tarifa >= 0.0)
    {
        cuotaPorTransaccion = tarifa;
    }
    else
    {
        throw invalid_argument( " Cuota por transacción >= 0.0 ");
    }// fin del constructor CuentaCheque

    
}

void CuentaCheque::abonar( double monto) //abonamos un monto a la cuenta y cargar
{
    Cuenta::abonar( monto );
    cargarl();
} //fin funcion abonar actualizada

bool CuentaCheque::cargar( double monto )
{
    bool exito = Cuenta :: cargar ( monto );

    if (exito)
    {
        cargarl();
        return true;
    }
    else
    {
        return false;
    }
    
} // fin de la funcion cargar 

void CuentaCheque::cargarl()
{
    Cuenta::establecerSaldo( getSaldo() - cuotaPorTransaccion );
    cout << "$" << cuotaPorTransaccion << " transacción libre de cargo." << endl;
}