#include <iostream>
using namespace std;

#include "Punto1.h"

int main(){

	cout<<"Usando la clase base"<<endl;
	CuentaAhorros dinero(1000000,1);
	dinero.getSaldo();
	dinero.abonar(500000);
	dinero.getSaldo();
	dinero.cargar(2000000);
	dinero.cargar(500000);
	dinero.getSaldo();
	cout<<"Usando la primera clase derivada"<<endl;
	CuentaCheques cuentika(1000000,1000);
	cuentika.cargar(999500);
	cuentika.getSaldo();
	

}
