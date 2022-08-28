#ifndef CUENTA_H
#define CUENTA_H

#include <string> 
using namespace std;

class Cuenta
{
 public:
  Cuenta( double = 0.0 ); // Constructor
  
  void setSaldo ( double) ;
  void abonar( double) ; // ingreso
  bool cargar (double) ; //retiro
  double getSaldo () const ; // devuelve el saldo
  void imprimirSaldo () const ; // devuelve un mensaje con el saldo
   
  private:

  double saldo; 
};

#endif
