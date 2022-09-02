#include <iostream>
#include "punto1.h"
using namespace std;

// Constructor clase Cuenta
Cuenta::Cuenta(double saldoCuenta_) {

	if (saldoCuenta_ < 0) {
		saldoCuenta = 0;
		cout << "El saldo ingresado no es valido" << endl;

	}
	else
		saldoCuenta = saldoCuenta_;
}

void Cuenta::abonar(double saldoAdicional){
	
	saldoCuenta += saldoAdicional; 
}

double Cuenta::cargar(double saldoRetirar) {

	if (saldoRetirar > saldoCuenta) {
		cout << "El monto a cargar excedio el saldo de la cuenta" << endl;
		return saldoCuenta;
	}
	else {
		saldoCuenta -= saldoRetirar;
		return saldoCuenta;
	}
	
}

double Cuenta::getSaldo() {
	return saldoCuenta;
}

//Constructor CuentaAhorros

CuentaAhorros::CuentaAhorros(double saldoCuenta_, double tasa_) : Cuenta(saldoCuenta_) {
	tasa = tasa_;
}

double CuentaAhorros::calcularInteres() {
	return  (tasa * getSaldo());
}

//Constructor CuentaCheques

CuentaCheques::CuentaCheques(double saldoCuenta_, double cuota_) : Cuenta(saldoCuenta_) {
	cuota= cuota_;
}

void CuentaCheques::abonar(double saldoAdicional) {
	Cuenta::abonar(saldoAdicional);
	cout << "El saldo con la cuota de manejo por abono es: " << (getSaldo() - cuota) << endl;
}

double CuentaCheques::cargar(double saldoRetirar) {
	double x = Cuenta::cargar(saldoRetirar);
		if (x == 1) {
			return (getSaldo() - cuota);
		}
		else {
			
			return 0;
		}

}