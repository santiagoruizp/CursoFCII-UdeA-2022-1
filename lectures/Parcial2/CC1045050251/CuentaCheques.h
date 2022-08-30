#ifndef cheques_h
#define cheques_h

#include <string> 
using namespace std;

#include "../clasebaseJuan.h"

class CuentaCheques : public Cuenta
{
 public:
  CuentaCheques (double = 0.0, double = 0.0);
  void setCuota (double) ; 
  void cargar (double) ; 
 private:
  double cuota; 
}; 
#endif