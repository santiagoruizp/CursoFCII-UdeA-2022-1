#include <iostream>
#include "punto3entregar.h"
using namespace std;

//constructor
Complejo::Complejo(double real, double imaginario ){ 
	asignarDatos(real,imaginario);
}

void Complejo::asignarDatos(double parteReal, double parteImaginaria){ // definimos esta función con paramatros de doble presición
    real=parteReal;          
    imaginaria=parteImaginaria;
}

double Complejo::obtenerParteReal(){
	return real;
}

double Complejo::obtenerParteImaginaria(){
	return  imaginaria;
}

void Complejo::mostrar(double real_, double imaginaria_){
cout <<"("<< real_ << " + " << imaginaria_<<"  i )";
}

void Complejo::suma(double real2, double imaginaria2){
	double sumareal=real + real2;
	double sumaimaginaria= imaginaria + imaginaria2;
	cout<<"\n suma de complejos :";
	mostrar(sumareal, sumaimaginaria);
}

void Complejo::resta(double real2, double imaginaria2){
	double restareal = real- real2;
	double restaimaginaria= imaginaria - imaginaria2;
	cout<<"\n resta de complejos da:"<<endl;
	mostrar(restareal, restaimaginaria);
}

void Complejo::multiplicacion(double real2, double imaginaria2){
	double multiplicareal=real*real2-imaginaria*imaginaria2;
	double multiplicaimaginaria=real*imaginaria2+real2*imaginaria;
	cout<<"\n producto de complejos:"<<endl;
	mostrar(multiplicareal, multiplicaimaginaria);
}