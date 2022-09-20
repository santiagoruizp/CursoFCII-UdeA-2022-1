#ifndef cuenta_h
#define cuenta_h

#include <iostream>
using namespace std;

class Cuenta{
 public:
 
  Cuenta( double = 0.0 ); 
  void SaldoActual ( double) ;
  void abonar( double) ; 
  bool cargar (double) ; //retiro
  double getSaldo () const ; 
  void mostrarSaldo () const ; 


  private:
  double saldo; 
};

#endif