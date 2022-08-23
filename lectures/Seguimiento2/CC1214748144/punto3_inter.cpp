/*Tarea3.
UTILIZANDO LAS TECNICAS DISCUTIDAS EN NUESTRO CURSO, POR FAVOR:
a) Defina una clase llamada "Fecha".
b) En la clase Fecha definida, debe incluir una función "diaSig()" que incremente una fecha en un día.
Pruebe su función para asegurarse que incrementa de manera correcta los dias en un nuevo mes y en un nuevo año.
c) Escriba un programa que pruebe su clase (se refiere a un main)*/
#include <iostream>
#include "punto3.h"

using namespace std;


int sdia, smes, sanio; //variables globales para guardar  el siguiente día, mes y año respectivamente. 
static const int dias[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //numero de días por mes en un año no bisiesto. 

Fecha::Fecha(int Dia=1, int Mes=1, int Anio=2000){ //se ingresan valores por default por si el usuario pone datos erroneos para que el programa se siga ejecutando.

	if(Anio>=0){  
		anio=Anio;	
	}
	else{
		cout<<"\n* Año inválido, se pone el año por default \n "<<endl;
	}
	
	if (Mes>=1 && Mes<=12){
		mes=Mes;
	}
	else{
		cout<<"\n* Mes inválido, se pone el mes por default \n"<<endl;
	}
	
	if( anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 ) ){ //si es año bisiesto 
		if (mes==2 && Dia==29){
			dia=Dia;
		}
		else{
			if(Dia >=1 && Dia <=dias[mes]){ //si es año no bisiesto. 
			dia=Dia;
		}
		else{
			cout<<"\n* Día inválido, se pone el día por default \n"<<endl;
		}
			
		}
	
	} 
	
	else{
		if(Dia >=1 && Dia <=dias[mes]){ //si es año no bisiesto. 
			dia=Dia;
		}
		else{
			cout<<"\n* Día inválido, se pone el día por default\n"<<endl;
		}
	}
	
}

Fecha::~Fecha(){
}


void Fecha::diaSig(){
	//si es un día en el que no se cambia de mes ni de año.	
	
	if( anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 ) ){ //si es año bisiesto 
		if(mes==2 && dia!=29){
			sdia=dia+1;
			smes=mes;
			sanio=anio;
		}	
		else{
			if(dia!=dias[mes]){ //si es año no bisiesto. 
				sdia=dia+1;
				smes=mes;
				sanio=anio;
			}
		
		}
	
	} 
	
	else{
		if(dia!=dias[mes]){ //si es año no bisiesto. 
			sdia=dia+1;
			smes=mes;
			sanio=anio;
		}
	}
	
	
	//si es un día para cambiar de mes pero no de año. 
	
		
		
	if( anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 ) ){ //si es año bisiesto 
		if(mes==2 && dia==29){
			sdia=1;
			smes=mes+1;
			sanio=anio;
		}
		else{
			if (dia==dias[mes] && mes!=12){
				sdia=1;
				smes=mes+1;
				sanio=anio;
			}
		}	
	
	} 
	
	else{
		if (dia==dias[mes] && mes!=12){
			sdia=1;
			smes=mes+1;
			sanio=anio;
		}
	}
	
	
	
	//si el un día para cambiar de mes y de año. 
		if(dia==31 && mes==12){
			sdia=1;
			smes=1;
			sanio=anio+1;
		}
}



void Fecha::mostrar(){
	cout<<"El día siguiente a: "<<endl;
	cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
	cout<<"Es: "<<endl;
	cout<<sdia<<"/"<<smes<<"/"<<sanio<<endl;
}


int Fecha::getdia() const {
	return dia;
}


int Fecha::getmes()  const {
	return mes;
}

int Fecha::getanio() const {
	return anio;
}



