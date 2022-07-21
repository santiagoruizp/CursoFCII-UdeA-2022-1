#include <iostream>
#include "Parcial1Punto3O.h"


//En este programa se crean dos objetos números complejos y a partir de estos, su suma y su resta se crean como dos objetos nuevos a partir de estos. La respectiva suma y resta se imprime con la función imprimirNumero

int main(){
	complejo test1 = complejo(1,1);
	complejo test2 = complejo(2,2);
	complejo suma = complejo(0,0);
	complejo resta = complejo(0,0);
	complejo producto = complejo(0,0);
	
	cout<<"Empezamos con los números complejos ";
	test1.imprimirNumero();
	cout<<" y ";
	test2.imprimirNumero();
	cout<<endl;
	suma.sumarNumeros(test1,test2);
	cout<<"La suma de estos números es ";
	suma.imprimirNumero();
	cout<<endl;
	resta.restarNumeros(test1,test2);
	cout<<"La resta de estos números es ";
	resta.imprimirNumero();
	cout<<endl;
	producto.multiplicarNumeros(test1,test2);
	cout<<"El producto entre estos números es ";
	producto.imprimirNumero();
	cout<<endl;

	return 0;
}

