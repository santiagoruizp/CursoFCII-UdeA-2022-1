#include <iostream>
#include <stdlib.h>

using namespace std;
//Clase base
class Cuenta{
	private:
		//Atributos
		double saldoCuenta;
	public: 
		//Constructor
		Cuenta(double);
		//Metodos
		void virtual abonar(double); 
		void virtual cargar(double); 
		double getSaldo(); 
};

//Constructor de la clase base
Cuenta::Cuenta(double _saldoCuenta){
	saldoCuenta = _saldoCuenta;
	if (saldoCuenta < 0){
		cout<<"Error, el saldo inicial es inválido. Se ha inicializado en cero."<<endl;
		saldoCuenta = 0;
	}
}

//Metodos de la clase base
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

//Clase derivada: CuentaAhorros.
class CuentaAhorros : public Cuenta{
	private:
		double interes;
		
	public:
		CuentaAhorros(double,double);//Constructor, primero se pone el double asociado con el atributo de la clase base.
		double calcularInteres();
};

CuentaAhorros::CuentaAhorros(double _saldoCuenta, double _interes): Cuenta(_saldoCuenta){ //Se agregan los atributos de la clase base de forma automática
	interes = _interes;
};

double CuentaAhorros::calcularInteres(){
	return interes*getSaldo();
}

class CuentaCheques : public Cuenta{
	private:
		double cuota;
		
	public: 
		CuentaCheques(double,double);//Constructor, primero se pone el double asociado con el atributo de la clase base.
		void cargar(double);
		void abonar(double);
};

CuentaCheques::CuentaCheques(double _saldoCuenta, double _cuota): Cuenta(_saldoCuenta){ //Se agregan los atributos de la clase base de forma automática
	cuota = _cuota;
};

void CuentaCheques::cargar(double carga){
		Cuenta::cargar(carga + cuota);
}

void CuentaCheques::abonar(double abono){
	Cuenta::abonar(abono - cuota);
}


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


