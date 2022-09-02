class Cuenta{ //clase base
	public:
		Cuenta(double); //se le ingresa el saldo inicial
		virtual void abonar(double); //sumar dinero a la cuenta, recibe la cantidad a abonar
		virtual void cargar(double); //restar dinero a la cuenta; que el monto a sacar no exceda el monto de la cuenta. 
		double getSaldo(); //devuelve el monto actual de la cuenta. sirve para la herencia. 
		void mostrar(); //muestra en pantalla el saldo que se tiene. 
	private:
		double saldo=0; //saldo por default.
};

class CuentaAhorros: public Cuenta{
	 //tiene intereses sobre el dinero que contiene.
	public:
		CuentaAhorros(double, double ); //saldo de la cuenta y el interes
		double CalcularInteres();
	private:
		double interes=0; //es un porcentaje, debe estar entre 0 y 1. se establece por default en cero. 
};

class CuentaCheques: public Cuenta{
	//cobran cuota por transacción (abono o cargo)
	public:
		CuentaCheques(double, double ); //saldo de la cuenta y la cuota de servicios. 
		void abonar(double); //polimorfismo, se define fnunciones con el mismo nombre que la clase base. 
		void cargar(double);
		
	private:
		double cuota=0; //cuota de saldo que se cobra por transacción. 
		
};

