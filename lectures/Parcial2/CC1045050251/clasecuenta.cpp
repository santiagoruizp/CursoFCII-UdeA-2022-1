
#include <iostream>
using namespace std;

#include "clasebaseJuan.h"

Cuenta::Cuenta( double saldo)
{
  SaldoActual( saldo ); 
}

void Cuenta::SaldoActual ( double _saldo )
{
  if (_saldo>=0){ saldo = _saldo;}
  else { saldo = 0;
  cout<<"El saldo invalido Saldo establecido en 0.0" << endl;
  }
}

//para hacer una consignacion
void Cuenta::abonar( double abono)
{
  if (abono>=0){
  SaldoActual(getSaldo()+abono);
  }

  else {
  cout<<"abono ingresado invalido abono establecido en 0.0" << endl;
  }
}

//para hacer un retiro
bool Cuenta::cargar( double retiro){
  if (retiro>=0){
    if (retiro<=getSaldo()){
    SaldoActual(getSaldo()-retiro);
    return 1;}

    else{ cout<<"El monto a retirar excede el saldo de la cuenta. retiro establecido en 0.0" << endl;
    return 0;}
  }

  else {
  cout<<"El retiro ingresado es invalido  retiro establecido en 0.0" << endl;
  return 0;
  }
}

double Cuenta::getSaldo() const{return saldo;}

void Cuenta::mostrarSaldo () const{
  cout<<"su saldo es de " << getSaldo() << endl;	
}
