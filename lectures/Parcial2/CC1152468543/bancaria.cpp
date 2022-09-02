//Metodos de la clase base

#include <iostream>
using namespace std;

#include "Punto1.h"

Cuenta::Cuenta(double _saldoCuenta){
	saldoCuenta = _saldoCuenta;
	if (saldoCuenta < 0){
		cout<<"Error, el saldo inicial es inválido. Se ha inicializado en cero."<<endl;
		saldoCuenta = 0;
	}
}

void Cuenta::abonar(double abono){
	saldoCuenta+=abono;
}
void Cuenta::cargar(double carga){
	//bool sentence;
	if(carga > saldoCuenta){
		cout<<"El monto a cargar exedió el saldo de la cuenta"<<endl;
	//	sentence=false;
	}
	else{
		saldoCuenta=saldoCuenta-carga;
	//	sentence=true;
	}
//	return sentence;
}
double Cuenta::getSaldo(){
	cout<<"El saldo actual es: "<<saldoCuenta<<endl;
	return saldoCuenta;
}
