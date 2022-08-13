#include <iostream>
#include "ejercicio3.h"
#include<limits>
using namespace std;

//Constructor: Inicializa el número complejo en (0,0)
complejo::complejo(double a, double b) {
	parteReal = a;
	parteImaginaria = b;
}


// Modifica el número complejo
void complejo::asignarDatos() {
	cout << "Ingrese parte real del numero complejo: " << endl;
	while (!(cin >> parteReal)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ingrese solo valores numericos " << endl;
	}

	cout << "Ingrese parte imaginaria del numero complejo: " << endl;
	while (!(cin >> parteImaginaria)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ingrese solo valores numericos " << endl;
	}
}
// Suma de complejos: Suma el número complejo inicializado con otro.
void complejo::Suma(double c, double d){
	cout << "La suma entre " << c << " + " << d << "i  y " << parteReal << " + "<< parteImaginaria << "i es: ";
	parteReal += c;
	parteImaginaria += d;
	
	Impresion();
	
}

// Suma de complejos: Suma el número complejo inicializado con otro.
void complejo::Resta(double c, double d){

	cout << "La resta entre " << c << " + " << d << "i  y " << parteReal << " + " << parteImaginaria << "i es: ";
	parteReal -= c;
	parteImaginaria -= d;

	Impresion();
	
}

void complejo::Multiplicacion(double c, double d) {

	cout << "La multiplicacion entre " << c << " + " << d << "i  y " << parteReal << " + " << parteImaginaria << "i es: ";
	double z1 = parteReal;
	double z2 = parteImaginaria;
	parteReal = z1*c- z2*d;
	parteImaginaria = z1 * d + z2 * c;

	Impresion();

}


void complejo::Division(double c, double d) {

	cout << "La divison entre " << c << " + " << d << "i  y " << parteReal << " + " << parteImaginaria << "i es: ";
	double z1 = parteReal;
	double z2 = parteImaginaria;
	parteReal = (z1 * c + z2 * d) / (z1 * z1 + z2 * z2);
	parteImaginaria = (z1 * d - z2 * c) / (z1 * z1 + z2 * z2);

	Impresion();

}



void complejo::Impresion(){

	cout << parteReal << " + " << parteImaginaria << "i" << endl;
}

void complejo::obtenerParteImaginaria() {
	cout << "La parte Imaginaria es: " << parteImaginaria << endl;
}

void complejo::obtenerParteReal(

) {
	cout << "La parte real es: " << parteReal << endl;
}