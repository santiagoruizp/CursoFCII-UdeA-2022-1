#include <iostream>
#include "punto1.h"
using namespace std;

int main() {

	// Inicializacion de los objetos
	Cuenta clase1(20.5);
	CuentaAhorros clase2(26.2, 0.1);
	CuentaCheques clase3(23, 1);

	// Verificacion de las clases

	cout << "Prueba de la clase Cuenta:"<< endl;
	cout << "El saldo actual de la cuenta es: " << clase1.getSaldo() << endl;
	clase1.abonar(10.1);
	cout << "El saldo despues de abonar es: " << clase1.getSaldo() << endl;
	clase1.cargar(300.);
	cout << "El saldo despues de cargar es: " << clase1.getSaldo() << endl;
	clase1.cargar(10.4);
	cout << "El saldo despues de cargar es: " << clase1.getSaldo() << endl;

	cout << "Prueba de la clase CuentaAhorros:" << endl;
	cout << "El saldo actual de la cuenta es: " << clase2.getSaldo() << endl;
	clase2.abonar(10.1);
	cout << "El saldo despues de abonar es: " << clase2.getSaldo() << endl;
	clase2.cargar(300.);
	cout << "El saldo despues de cargar es: " << clase2.getSaldo() << endl;
	clase2.cargar(10.4);
	cout << "El saldo despues de cargar es: " << clase2.getSaldo() << endl;
	cout << "El saldo con interes es: " << clase2.calcularInteres() << endl;

	cout << "Prueba de la clase CuentaCheques:" << endl;
	cout << "El saldo actual de la cuenta es: " << clase3.getSaldo() << endl;
	clase3.abonar(10.1); 
	cout << "El saldo despues de cargar es: " << clase3.cargar(10.4) << endl;



	return 0;
}