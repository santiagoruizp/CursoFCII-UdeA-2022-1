//
// Created by kevin on 23/08/22.
//

#ifndef CUENTAS_CUENTACHEQUE_H
#define CUENTAS_CUENTACHEQUE_H

#include "./Cuenta.h"

class CuentaCheque : public Cuenta{
public:
    CuentaCheque(double saldoCuenta, double cuotaPorTrans);
    void abonar(double saldoAbonar) override;
    void cargar(double) override;

private:
    double cuotaPorTrans;
};


#endif //CUENTAS_CUENTACHEQUE_H
