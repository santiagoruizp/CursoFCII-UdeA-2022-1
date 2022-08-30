#ifndef CUENTACHEQUES_H
#define CUENTACHEQUES_H

#include "CuentaAhorros.h"

class CuentaCheques : public Cuenta
{
private:
    double saldo;
    double cuota; 
    
public:
    CuentaCheques( const double &, const double & );
    ~CuentaCheques();

    void cargar(double);
    void abonar(double);

};

#endif


