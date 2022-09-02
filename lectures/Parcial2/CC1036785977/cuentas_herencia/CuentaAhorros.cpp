#include <iostream>
using namespace std;

#include "CuentaAhorros.h"

// constructor
CuentaAhorros::CuentaAhorros( double ss, double inte ) : Cuenta( ss )
{
  setInteres(inte); // en porcentaje 0% - 100% 
}

double CuentaAhorros::calcularInteres()
{
  return getSaldo()*(tasaInteres/100); // monto de interes
}

void CuentaAhorros::setInteres(double interes)
{
	if (interes >= 0 && interes <= 100){
	tasaInteres = interes;
	}
	else{
	tasaInteres = 0;
	cout<<"Tasa de interes invalida, establecida en "<<tasaInteres<<endl;
	}
}


