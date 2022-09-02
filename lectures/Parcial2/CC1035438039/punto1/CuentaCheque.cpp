//
// Created by kevin on 23/08/22.
//

#include "CuentaCheque.h"

CuentaCheque::CuentaCheque(double saldoCuenta, double cuotaPorTrans) : Cuenta(saldoCuenta){

    /*Se verifica que la cuota sea mayor a cero, si no se pone en cero, se puede poner en lugar de cero cualquier otro valor inicial*/
    CuentaCheque::cuotaPorTrans = (cuotaPorTrans > 0) ? cuotaPorTrans : 0.0;

}

void CuentaCheque::abonar(double saldoAbonar){
    if (Cuenta::verificarTrans(saldoAbonar)){
        Cuenta::setSaldoCuenta(Cuenta::getSaldoCuenta() + saldoAbonar - CuentaCheque::cuotaPorTrans);
    } else{
        throw "Saldo ingresado invalido";
    }
}

void CuentaCheque::cargar(double saldoCargar) {
    if (Cuenta::verificarTrans(saldoCargar)){
        double nuevoSaldo = Cuenta::getSaldoCuenta() - saldoCargar - CuentaCheque::cuotaPorTrans;
        Cuenta::setSaldoCuenta(nuevoSaldo);
    }
    else{
        throw "Saldo ingresado invalido";
    }
}




