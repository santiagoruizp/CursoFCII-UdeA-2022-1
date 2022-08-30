#ifndef CUENTACHEQUE_H
#define CUENTACHEQUE_H

#include "Cuenta.h"

class CuentaCheque : public Cuenta
{
public:
   CuentaCheque( double, double );

   void abonar( double );
   bool cargar( double );

private:
   double cuotaPorTransaccion; // cuota que se cobra por transacción
   void cargarl();
};
#endif