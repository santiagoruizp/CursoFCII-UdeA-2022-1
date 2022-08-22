/*
Escribir una funcion, "RecibirCadenas",  que recibe como parametros dos cadenas que puede contener espacios, la funcion deberá:

    Decir qué cadena es mayor y cuál es menor alfabéticamente
    Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a MAYÚSCULAS
    Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS
    Generar una nueva cadena concatenando las dos que ya fueron convertidas
    Generar una nueva cadena que contenga la cadena concatenada invertida

Incluya la función "RecibirCadenas"  en un programa ejecutable en C++, y use el programa para pedir al usuario que introduzca las dos cadenas con las que probara su función.

Al finalizar el programa, este deberá:
    Imprimir las dos cadenas originales
    Imprimir las dos cadenas con las conversiones
    Imprimir la cadena concatenada
    Imprimir la cadena concatenada invertida
*/
#include <iostream>
#include <string> //para trabajar con strings tipo c++

using namespace std;

void RecibirCadenas(string, string); //prototipo de función. 

///////////////////////////////
int main(){
	string A, B;
	cout<<"Ingrese la primera cadena: "<<endl;
	getline(cin, A);
	cout<<"Ingrese la segunda cadena: "<<endl;
	getline(cin, B);
		
	/*string A("Juan Felipe Zapata");
	string B("Universidad de Antioquia");*/

	RecibirCadenas(A,B);
	
return 0;
}

//////////////////////////////////////////////////////////

void RecibirCadenas(string A,string B){
	//  Imprimir las dos cadenas originales
	cout<<"\n* La primera cadena original es: \n"<<A<<endl;
	cout<<"\n* La segunda cadena original es: \n"<<B<<endl;


	//////////////////////////////////////////////////////////////////////////
	// Decir qué cadena es mayor y cuál es menor alfabéticamente
	if (A>B){
		cout<<"\n*  La cadena "<<A<<" es mayor alfabéticamente a \n"<<B<<endl;
	}
	else if (A<B){
		cout<<"\n* La cadena "<<A<<" es menor alfabéticamente a \n"<<B<<endl;
	}
	else {
		cout<<"\n* Las cadenas son iguales \n"<<endl;
	}
	
	//////////////////////////////////////////////////////////////////////////
	////Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a MAYÚSCULAS
	string C=A;
	 
	 for ( size_t i{0}; i < C.size(); i++ ){
	 	switch(C.at(i)){
	 		case 'a':
	 			C.at(i)='A';
	 			break;
	 		case 'e':
	 			C.at(i)='E';
	 			break;
	 		case 'i':
	 			C.at(i)='I';
	 			break;	 
	 		case 'o':
	 			C.at(i)='O';
	 			break;	 	
	 		case 'u':
	 			C.at(i)='U';
	 			break;	 								
	  	}
	  	
		
	}
	cout<<"\n* La cadena "<<A<<" con las vocales en mayúscula es: \n"<<C<<endl;
	////////////////////////////////////////////////////////////////////////////////
	//  Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS
	string D=B;
	//convertimos la cadena toda a mayúsculas y luego las vocales a minúsculas. 
	
	for ( size_t i{0}; i < D.size(); i++ ){
		D.at(i)=toupper(D.at(i));
	}
	 for ( size_t i{0}; i < D.size(); i++ ){
	 	switch(D.at(i)){
	 		case 'A':
	 			D.at(i)='a';
	 			break;
	 		case 'E':
	 			D.at(i)='e';
	 			break;
	 		case 'I':
	 			D.at(i)='i';
	 			break;	 
	 		case 'O':
	 			D.at(i)='o';
	 			break;	 	
	 		case 'U':
	 			D.at(i)='u';
	 			break;	 								
	  	}	
	}
	cout<<"\n* La cadena "<<B<<" con las consonantes en mayúscula es:  \n "<<D<<endl;
	
	//Generar una nueva cadena concatenando las dos que ya fueron convertidas
	
	string E=C+" "+ D;
	cout<<"\n* Las cadenas convertidas concatenadas quedan así:\n "<<E<<endl;
	
	// Generar una nueva cadena que contenga la cadena concatenada invertida
	string F=E;
		for ( size_t i{0}; i < E.size(); i++ ){
			F.at(E.size()-i-1)=E.at(i);
		}
		cout<<"\n* Las cadena concatenda invertida queda así:\n "<<F<<endl;
	
}
