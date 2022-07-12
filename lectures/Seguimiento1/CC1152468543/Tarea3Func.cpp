

#include <iostream>
#include "Tarea3Objetos.h"
#include <cmath>

using namespace std;

//Constructor.
Tarea3::Tarea3(float _x, int _N){
	x = _x;
	N=_N;
}

int Tarea3::Factorial(int n){
	unsigned producto=1;
	int i=1;
	while(i <= n)
	{		
		producto = i*producto;
		i = i+1;		
	}

	return producto;
}

float Tarea3::Exponencial(){
	float sum=1;
	int i=1;
	
	while(i<=N){
		
		sum = sum + pow(x,i)/(Tarea3::Factorial(i));
		i=i+1;
	}
	
	return sum;
}

void Tarea3::MostrarExponencial(){
	cout << "El valor de la exponencial de " << x << " es: " << Tarea3::Exponencial() << endl;
}

