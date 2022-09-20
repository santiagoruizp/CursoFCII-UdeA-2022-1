//Clase Cuenta
class Cuenta {
public:

	Cuenta(double);
	virtual void abonar(double);
	virtual double cargar(double);
	double getSaldo();


private:
	double saldoCuenta;
};

//Clase CuentaAhorros
class CuentaAhorros: public Cuenta{
public:

	//Funciones miembro

	CuentaAhorros(double,double);
	double calcularInteres();

	
private:
	double tasa; // Interes en porcentaje
};


//Clase CuentaCheques
class CuentaCheques: public Cuenta {
public:

	CuentaCheques(double, double);
	void abonar(double);
	double cargar(double);

private:
	double cuota; // Cuota que se cobra por transacción.
};
	