#include <iostream>
#include "punto3.h"
using namespace std;
//////////////////////////////////////////////
Complejo::Complejo(double real, double imaginario ){ // constructor, define la función con dos parametros de doble presición 
	asignarDatos(real,imaginario);
}
////////////////////////////////////////////
void Complejo::asignarDatos(double parteReal, double parteImaginaria){ // definimos esta función con paramatros de doble presición
    a1=parteReal;          // reasignamos estos nuevos datos miembros
    b1=parteImaginaria;
}


double Complejo::obtenerParteReal(){
	return a1;
}

double Complejo::obtenerParteImaginaria(){
	return  b1;
}


void Complejo::mostrar(double c, double d){
cout <<"("<< c << " + " << d<<"  i )";
}

void Complejo::suma(double a2, double b2){
	double sumar=a1 + a2;
	double sumai=b1 + b2;
	cout<<"\nLa suma es:";
	mostrar(sumar, sumai);
}

void Complejo::resta(double a2, double b2){
	double restar=a1- a2;
	double restai=b1- b2;
	cout<<"\nLa resta es:";
	mostrar(restar, restai);
}


void Complejo::multiplicacion(double a2, double b2){
	double multir=a1*a2-b1*b2;
	double multii=a1*b2+a2*b1;
	cout<<"\nLa multiplicación es:";
	mostrar(multir, multii);
}

void Complejo::division(double a2, double b2){
	double divir=(a1*a2+b1*b2)/(a2*a2+b2*b2);
	double divii=(b1*a2-a1*b2)/(a2*a2+b2*b2);
	cout<<"\nLa división es:";
	mostrar(divir, divii);
}


