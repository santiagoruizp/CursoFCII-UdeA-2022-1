#include <cmath>
#include "potencial.h"
#include <iostream>
#include <fstream>

using namespace std; 

Particula::Particula(double a, double b, double x, double k0, double dx, double dt, double sigma){  
	this->a = a;
	this->b = b;
	this->x = x;
	this->k0 = k0; 
	this->dx = dx; 
	this->dt = dt;  
	this->sigma = sigma;
}


Particula::~Particula(){
}

double Particula::geta(){
	return a; 
}


double Particula::getb(){
	return b; 
}


double Particula::getdx(){
	return dx; 
}

void Particula::psi(double(*V)(double)){

	ofstream archivo;
	ofstream archivo1;
	ofstream archivo2;
	ofstream archivo3;
	ofstream archivo4;

	archivo.open("programa.txt",ios::out);
	archivo1.open("programa1.txt",ios::out); 
	archivo2.open("programa2.txt",ios::out); 
	archivo3.open("programa3.txt",ios::out); 
	archivo4.open("programa4.txt",ios::out);
	
	archivo3<<geta()<<endl;
	archivo3<<getb()<<endl;
	archivo3<<getdx()<<endl;
	
    	int max = (b-a)/dx;
	int i, n; 
	int cont=0;

	double psr[max][2]; //parte real
	double psi[max][2]; //parte imaginaria
	double p2[max]; //probabilidad
	double v[max]; //potencial

	
	for(i=0; i<max; i++){
		psr[i][0]=exp(-0.5*pow((x/0.5),2))*cos(k0*x);
		psi[i][0]=exp(-0.5*pow((x/0.5),2))*sin(k0*x);
		v[i]=V(x);
		archivo4<<v[i]<<endl;
		x+=dx;
	}
	
	p2[0]=0;
	p2[max-1]=0;	
	
	
	for (n=0 ; n < 10000 ; n++){
	
		for(i=1;i<max-1;i++){
			psr[i][1] = psr[i][0]-dt*(psi[i+1][0]+psi[i-1][0]-2.0*psi[i][0])/(dx*dx)+dt*v[i]*psi[i][0];
			p2[i]=psr[i][0]*psr[i][1]+psi[i][0]*psi[i][0]; //para tiempos semi-enteros
		}
		
		
		for(i=1;i<max-1;i++) {
			psi[i][1]=psi[i][0]+dt*(psr[i+1][1]+psr[i-1][1]-2.0*psr[i][1])/(dx*dx)-dt*v[i]*psr[i][1];
		}
		
		
		if(n==0 || n%10==0){ 
			for(i=0; i<max; i++){
				archivo<<p2[i]<<endl;	
				archivo1<<psr[i][1]<<endl;
				archivo2<<psi[i][1]<<endl;
			}
			cont++;
		}
			
		for(i=0;i<max;i++){
			psi[i][0]=psi[i][1];
			psr[i][0]=psr[i][1];
		}	
	}
	
	archivo3<<cont<<endl;
	archivo3.close();
	archivo.close();
	archivo1.close();
	archivo2.close();
	archivo4.close();
	
	
}
