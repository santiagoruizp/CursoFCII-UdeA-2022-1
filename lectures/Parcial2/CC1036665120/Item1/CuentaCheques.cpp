#include "CuentaCheques.h"

CuentaCheques::CuentaCheques( const double & saldo, const double & cuota ) : Cuenta(saldo)
{
    this->cuota = cuota;
}

CuentaCheques::~CuentaCheques()
{

}


// ---------------------------------
// ----------- FUNCIONES -----------
// ---------------------------------

void CuentaCheques::abonar(double dineroAbonar)
{
    if ( (dineroAbonar + this->saldo) >= this->cuota )
    {
        Cuenta::abonar(dineroAbonar);
        Cuenta::cargar(this->cuota);
    }else{
        std::cout << "No tiene el suficiente saldo para realizar esta transacción" << std::endl;
    }

}


void CuentaCheques::cargar(double dineroRetirar)
{
    if ( (dineroRetirar + this->cuota) >= this->saldo )
    {
        Cuenta::cargar(dineroRetirar);
        Cuenta::cargar(this->cuota);

    }else{
        std::cout << "El monto a cargar excedió el saldo de la cuenta." << std::endl;
    }
    

}
