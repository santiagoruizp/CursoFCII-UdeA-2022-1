#ifndef ahorros_h
#define ahorros_h

#include <string> 
using namespace std;

#include "../clasebaseJuan.h"

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
