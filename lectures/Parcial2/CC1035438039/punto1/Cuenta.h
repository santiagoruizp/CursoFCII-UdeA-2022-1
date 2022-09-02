//
// Created by kevin on 23/08/22.
//

#ifndef CUENTAS_CUENTA_H
#define CUENTAS_CUENTA_H


class Cuenta {

public:
    explicit Cuenta(double saldoCuenta);
    virtual void abonar(double saldoAbonar);
    virtual void cargar(double saldoCargar);
    double getSaldoCuenta() const;

private:
    double saldoCuenta;

protected:
    static bool verificarSaldo(double);
    void setSaldoCuenta(double saldoCuenta);
    bool verificarTrans(double saldo);
};


#endif //CUENTAS_CUENTA_H
