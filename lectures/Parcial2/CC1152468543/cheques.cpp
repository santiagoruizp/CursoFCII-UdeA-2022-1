#include <iostream>
using namespace std;

#include "Punto1.h"

CuentaCheques::CuentaCheques(double _saldoCuenta, double _cuota): Cuenta(_saldoCuenta){ //Se agregan los atributos de la clase base de forma automática
	cuota = _cuota;
};

void CuentaCheques::cargar(double carga){
		Cuenta::cargar(carga + cuota);
}

void CuentaCheques::abonar(double abono){
	Cuenta::abonar(abono - cuota);
}

