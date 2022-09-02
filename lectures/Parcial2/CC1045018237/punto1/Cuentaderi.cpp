#include <stdexcept>
#include <iostream>

#include "Cuentaderi.h"

using namespace std;

// el constructor inicializa el saldo y la tasa de interes
CuentaAhorros::CuentaAhorros( double Saldoinicial, double tasa )
   :Cuenta( Saldoinicial) // inicializamos la clase base
{
    if ( tasa >= 0.0 )
    {
        tasaInteres = tasa;
    }
    else
    {
        throw invalid_argument( " La tasa de interes es >= 0.0 ");
    }
}

//retornemos el monto del interes ganado
double CuentaAhorros::calcularInteres()
{
    return getSaldo() * tasaInteres;
}
    
    


