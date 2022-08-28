#include <iostream>
using namespace std;

#include "ClaseCuenta.h"

Cuenta::Cuenta( double saldo)
{
  setSaldo( saldo ); 
}

void Cuenta::setSaldo ( double ss )
{
  if (ss>=0){
  saldo = ss;
  }
   
  else {
  saldo = 0;
  cout<<"El saldo ingresado es invalido: Saldo iniciado en "<< saldo << endl;
  }
}

void Cuenta::abonar( double abono)
{
  if (abono>=0){
  setSaldo(getSaldo()+abono);
  }
   
  else {
  cout<<"El abono ingresado es invalido: El abono es de 0.0" << endl;
  }
}

bool Cuenta::cargar( double retiro)
{
  if (retiro>=0){
    if (retiro<=getSaldo()){
    setSaldo(getSaldo()-retiro);
    return 1;
    }
    else{
    cout<<"El monto a cargar excede el saldo de la cuenta: El cargo es de 0.0" << endl;
    return 0;
    }
  }
  else {
  cout<<"El cargo ingresado es invalido: El cargo es de 0.0" << endl;
  return 0;
  }
}

double Cuenta::getSaldo () const
{
  return saldo;
}

void Cuenta::imprimirSaldo () const
{
  cout<<"Su saldo es de " << getSaldo() << endl;	
}

