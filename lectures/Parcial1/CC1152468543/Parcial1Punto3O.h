#include <iostream>
#include <stdlib.h>
using namespace std;

class complejo{
	private:
	float parteImaginaria;
	float parteReal;
	
	public:
	
	complejo(float,float);
	
	float obtenerParteReal();
	float obtenerParteImaginaria();
	void asignarDatos();
	void imprimirNumero();
	void sumarNumeros(complejo, complejo);
	void restarNumeros(complejo, complejo);
	
//A la pregunta de si podrían programarse más operaciones, la respuesta es obviamente que sí. Multipliquemos por ejemplo dos números complejos

	void multiplicarNumeros(complejo, complejo);
};

