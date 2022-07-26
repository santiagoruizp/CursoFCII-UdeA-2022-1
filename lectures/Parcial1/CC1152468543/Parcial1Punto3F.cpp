#include <iostream>
#include <stdlib.h>
#include "Parcial1Punto3O.h"
using namespace std;

complejo::complejo(float _parteReal, float _parteImaginaria){
	parteReal = _parteReal;
	parteImaginaria = _parteImaginaria;
}

float complejo::obtenerParteReal(){
	return parteReal;
}

float complejo::obtenerParteImaginaria(){
	return parteImaginaria;
}

void complejo::asignarDatos(){
	cout<<"Ingrese el valor de la parte real del número: " << endl;
	cin>>parteReal;
	cout<<"Ingrese el valor de la parte imaginaria del número: " << endl;
	cin>>parteImaginaria;
}

void complejo::imprimirNumero(){
	cout<<parteReal<<" + "<<parteImaginaria<<"i";
}

void complejo::sumarNumeros(complejo z1, complejo z2){
	parteReal = z1.parteReal + z2.parteReal;
	parteImaginaria = z1.parteImaginaria + z2.parteImaginaria;	
}

void complejo::restarNumeros(complejo z1, complejo z2){
	parteReal = z1.parteReal - z2.parteReal;
	parteImaginaria = z1.parteImaginaria - z2.parteImaginaria;	
}

void complejo::multiplicarNumeros(complejo z1, complejo z2){
	parteReal = z1.parteReal*z2.parteReal - z1.parteImaginaria*z2.parteImaginaria;
	parteImaginaria = z1.parteReal*z2.parteImaginaria + z2.parteReal*z1.parteImaginaria;
}
