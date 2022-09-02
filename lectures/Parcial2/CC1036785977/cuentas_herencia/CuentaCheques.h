#ifndef CUENTACHEQUES_H
#define CUENTACHEQUES_H

#include <string> 
using namespace std;

#include "../cuenta_clasebase/ClaseCuenta.h"

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques (double = 0.0, double = 0.0);
  
  void setCuota (double) ; 
  void cargar (double) ; //retiro redefinido 
 private:
  double cuota; 
}; 
#endif
