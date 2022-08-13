#include <iostream>

using namespace std;

class complejo
{
public:
	complejo(double, double); // el constructor
	void Suma(double, double); // Suma de números complejos
	void Resta(double, double); // Resta de números complejos
	void asignarDatos();
	void obtenerParteReal();
	void obtenerParteImaginaria();
	void Impresion();
	void Multiplicacion(double, double);
	void Division(double, double);

private:
	double parteImaginaria;
	double parteReal;

};

