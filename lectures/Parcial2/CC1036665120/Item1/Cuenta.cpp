#include "Cuenta.h"

Cuenta::Cuenta(double saldoInicial)
{

this->saldo = validarSaldo(saldoInicial);
    
}

Cuenta::~Cuenta()
{
}


double Cuenta::validarSaldo(double & saldo)
{
    if (saldo < 0)
    {
        std::cout << "El saldo ingresado es inválido" << std::endl;
        return 0;

    }else{
        std::cout << "El saldo inicial de su cuenta es: $" << saldo << std::endl;
        return saldo;
    }
}


// ---------------------------------
// ----------- FUNCIONES -----------
// ---------------------------------

void Cuenta::abonar(double dineroAbonar)
{
    this->saldo += dineroAbonar;
    std::cout << "Se ha abonado: $" << dineroAbonar << std::endl;
    this->getSaldo();

}

void Cuenta::cargar(double dineroRetirar)
{
    if ( this->saldo > dineroRetirar )
    {
        this->saldo -= dineroRetirar;
        std::cout << "Se ha retirado: $" << dineroRetirar << std::endl;
        this->getSaldo();
    }else{
        std::cout << "El monto a cargar excedió el saldo de la cuenta." << std::endl;
    }

}

double Cuenta::getSaldo()
{
    std::cout << " ---- El saldo en su cuenta es: $" << this->saldo << " ---- "<< std::endl;
    return this->saldo;
}




