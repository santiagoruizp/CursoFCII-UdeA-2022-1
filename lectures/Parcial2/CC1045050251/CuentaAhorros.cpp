#include <iostream>
using namespace std;

#include "CuentaAhorros.h"


CuentaAhorros::CuentaAhorros( double _saldo, double _interes ) : Cuenta( _saldo ){
  setInteres(_interes); 
}

void CuentaAhorros::setInteres(double interes)
{
	if (interes >= 0 && interes <= 100){ tasaInteres = interes;
	}
	else{ tasaInteres = 0;
	cout<<"Tasa de interes invalida restableida en 0.0 "<<endl;
	}
}

double CuentaAhorros::calcularInteres()
{
  return getSaldo()*(tasaInteres/100); 
}
