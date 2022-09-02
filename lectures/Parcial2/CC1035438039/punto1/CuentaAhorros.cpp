//
// Created by kevin on 23/08/22.
//

#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(double saldoCuenta, double tasaIntereses) : Cuenta(saldoCuenta) {
    /*Se mira sila tasa de intereses entra entre 0 y 1, si no se pone en cero (se puede cambiar por cualquier valor inicial)*/
    CuentaAhorros::tasaIntereses = (tasaIntereses>=0 && tasaIntereses<=1)? tasaIntereses: 0.0;
}

double CuentaAhorros::calcularIntereses(){
    return CuentaAhorros::tasaIntereses * CuentaAhorros::getSaldoCuenta();
}