#include "punto1_inter.cpp"
#include <iostream>

using namespace std;

int main(){
	cout<<"CUENTA"<<endl;
	Cuenta per1(200000);
	per1.abonar(30000);
	//per1.cargar(10000);
	per1.mostrar();
	
	cout<<"CUENTA AHORROS"<<endl;
	CuentaAhorros per2(200000, 0.01); //saldo de la cuenta e interes del 1%
	per2.cargar(5000);
	//per2.abonar(30000);
	per2.abonar(per2.CalcularInteres()); //abono los intereses de la cuenta. 
	per2.mostrar();
	
	cout<<"CUENTA CHEQUES"<<endl;
	CuentaCheques per3(20000, 100); //saldo de la cuenta y cuota de servicio. 
	per3.abonar(4000);
	per3.cargar(2000);
	per3.mostrar();
	return 0;
}

