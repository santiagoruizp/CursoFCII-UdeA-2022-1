#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H

#include <string> 
using namespace std;

#include "../clasebase/cuenta.h"

class CuentaAhorros : public Cuenta
{
 public:
  CuentaAhorros (double = 0.0, double = 0.0);
  
  double calcularinteres () ;
  void setInteres (double) ; 
  
 private:
  double tasadeinteres; 
}; 
#endif