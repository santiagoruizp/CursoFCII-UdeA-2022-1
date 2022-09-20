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
class CuentaAhorros : public Cuenta{
	private:
		double interes;
		
	public:
		CuentaAhorros(double,double);//Constructor, primero se pone el double asociado con el atributo de la clase base.
		double calcularInteres();
};

class CuentaCheques : public Cuenta{
	private:
		double cuota;
		
	public: 
		CuentaCheques(double,double);//Constructor, primero se pone el double asociado con el atributo de la clase base.
		void cargar(double);
		void abonar(double);
};

