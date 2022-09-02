//
// Created by kevin on 23/08/22.
//

#include "Cuenta.h"

Cuenta::Cuenta(double saldoCuenta){
    if (verificarSaldo(saldoCuenta)){
        Cuenta::saldoCuenta = saldoCuenta;
    }
    else{
        Cuenta::saldoCuenta =  0.0;
        throw "El saldo inicial ingresado es invalido. El saldo de la cuenta se establecio en 0.0";
    }
}


void Cuenta::setSaldoCuenta(double saldoCuenta) {
    if (verificarSaldo(saldoCuenta)){
        Cuenta::saldoCuenta = saldoCuenta;
    }
    else{
        throw "El saldo ingresado es invalido.";
    }
}

double Cuenta::getSaldoCuenta() const {
    return saldoCuenta;
}

void Cuenta::abonar(double saldoAbonar){
    if (verificarTrans(saldoAbonar)){
        setSaldoCuenta(Cuenta::getSaldoCuenta() + saldoAbonar);
    }
    else{
        throw "El saldo a abonar es invalido";
    }
}

void Cuenta::cargar(double saldoCargar){
    double nuevoSaldo = Cuenta::getSaldoCuenta() - saldoCargar;
    if (verificarTrans(saldoCargar) && verificarSaldo(nuevoSaldo)){
        setSaldoCuenta(nuevoSaldo);
    }
    else{
        throw "El saldo a cargar es invalido o excede el saldo de la cuenta";
    }
}

bool Cuenta::verificarSaldo(double saldo) {
    /*Se verifica que un saldo(numero) sea mayor o igual que cero*/
    bool respuesta = saldo >= 0.0;
    return respuesta;
}

bool Cuenta::verificarTrans(double saldo) {
    /*Se realizará una transaccion siempre que los valores a cargar o abonar sean mayores que cero*/
    bool respuesta = saldo> 0.0;
    return respuesta;
}