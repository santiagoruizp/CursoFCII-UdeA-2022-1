#include <stdexcept>
#include <iostream>
#include "Cuenta.h"

using namespace std;

// Iniciamos el balance con el constructor
Cuenta::Cuenta( double Saldoinicial )
{
    if ( Saldoinicial >= 0.0 ) // si el saldo inicial es mayor o igula que 0.0, establecemos este valor
        Saldo = Saldoinicial;  // es el saldo de la cuenta
    else
       throw invalid_argument( "Error: Saldo inicial invalido" );
}

void Cuenta::abonar( double monto )
{
    Saldo = Saldo + monto; // suma el monto al saldo actual
}

bool Cuenta::cargar( double monto )
{
    if ( monto > Saldo )
    {
        cout << " El monto a cargar excedio el saldo de la cuenta. " << endl;
        return false;
    } // fin del if
    else // el monto no excede el saldo de la cuenta
    {
        Saldo = Saldo - monto;
        return true;
    } // fin del else 
    
}

void Cuenta::establecerSaldo( double nuevoSaldo ) // establecemos un nuevo saldo
{
    Saldo = nuevoSaldo;
}// fin de la función establecer saldo

double Cuenta::getSaldo() // retornamos el saldo de la cuenta
{
    return Saldo;
} // fin de la función getSaldo
