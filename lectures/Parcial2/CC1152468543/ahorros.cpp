#include <iostream>
using namespace std;

#include "Punto1.h"


CuentaAhorros::CuentaAhorros(double _saldoCuenta, double _interes): Cuenta(_saldoCuenta){ //Se agregan los atributos de la clase base de forma automática
	interes = _interes;
};

double CuentaAhorros::calcularInteres(){
	return interes*getSaldo();
}
