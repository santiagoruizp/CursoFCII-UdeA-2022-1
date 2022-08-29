#include <iostream>
#include "punto1.h"
using namespace std;
/////////////////////////////////////////////////////////
Cuenta::Cuenta(double Saldo=0){      
	if (Saldo>=0){
		saldo=Saldo;
	}
	else{
		cout<<"\n EL saldo inicial es inválido, se pone saldo inicial por default: 0\n"<<endl;
	}  	
}
	
CuentaAhorros::CuentaAhorros(double Saldo=0, double Interes=0):Cuenta(Saldo){
	if(Interes>1 || interes<0){
		cout<<"El porcentaje de interes debe estar entre 0 y 1"<<endl;
	}
	else {
		interes=Interes;
	}
}

CuentaCheques::CuentaCheques(double Saldo=0, double Cuota=0):Cuenta(Saldo){
	if(Cuota<0){
		cout<<"Valor para cuota no válido "<<endl;
	}
	else{
		cuota=Cuota;
	}
}

////////////////////////////////////////////////////
void Cuenta::abonar(double monto=0){
	if(monto<0){
		cout<<"cantidad no válida, se toma el valor por default"<<endl;
		
	}
	else{
		saldo+=monto;	
	}

}

void Cuenta::cargar(double monto=0){

	if(monto<0){
		cout<<"cantidad no válida, se toma el valor por default"<<endl;
		
	}
	else{
		if (saldo-monto<0){
				cout<<"El monto a cargar excedio el saldo de la cuenta."<<endl;
			}
			else{
				saldo-=monto;
			}
	}
	
}

double Cuenta::getSaldo(){
	return saldo;
}

void Cuenta::mostrar(){
	cout<<"\n Saldo actual de la cuenta: \n"<<endl;
	cout<<"*---------------------------*"<<endl;
	cout<<getSaldo()<<endl;
	cout<<"*---------------------------*"<<endl;
}



double CuentaAhorros::CalcularInteres(){
	return (interes*Cuenta::getSaldo()); //en monto de interes obtenido por una cuenta.
}

void CuentaCheques::cargar(double mont){
	Cuenta::cargar(mont);
	if((Cuenta::getSaldo()-cuota)<0){
		cout<<"EL monto a cargar excedió el saldo de la cuenta"<<endl;
	}
	else{
		Cuenta::cargar(cuota);
	}
}

void CuentaCheques::abonar(double mont){
	Cuenta::abonar(mont);	
	if((Cuenta::getSaldo()-cuota)<0){
		cout<<"No se pudo llevar a cabo la transacción "<<endl;
	}
	else{
		Cuenta::cargar(cuota);
	}
}  
