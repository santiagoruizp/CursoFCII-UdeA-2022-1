#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H

#include <string> 
using namespace std;

#include "../cuenta_clasebase/ClaseCuenta.h"

class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros (double = 0.0, double = 0.0);
  
  double calcularInteres () ;
  void setInteres (double) ; 
  
 private:
  double tasaInteres; 
}; 
#endif
