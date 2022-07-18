#include "ejercicio3.h"
#include <iostream>
using namespace std;

int main()
{

	complejo miprimercomplejo(2,3);  // Inicialización de la clase, recibe valor real y complejo respectivamente;
	miprimercomplejo.Impresion();
	miprimercomplejo.obtenerParteImaginaria();
	miprimercomplejo.obtenerParteReal();
	miprimercomplejo.asignarDatos();
	miprimercomplejo.Impresion();
	miprimercomplejo.Suma(5,6);
	miprimercomplejo.asignarDatos();
	miprimercomplejo.Resta(5, 6);
	miprimercomplejo.asignarDatos();
	miprimercomplejo.Multiplicacion(1,1);
	miprimercomplejo.Division(1, 1);
	
	
	

	return 0;

}