/*
La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada de elementos.
Funciona al dividir repetidamente a la mitad la porción de la lista que podría contener al elemento,
hasta reducir las ubicaciones posibles a solo una.
Para terminar, el algoritmo encuentra un elemento que coincide con la clave de búsqueda o reduce el subvector hasta un tamaño de cero.
Por favor, Cree un programa en c++ para implementar la búsqueda binaria.
*/
#include <iostream>
using namespace std; 
///////////////////////////////////////////////////////
void binaria( int A[], int n, int clave){
	int min=0, max=n,i=0;
	char cond; //condición para determinar si se encontró la clave. 
	
	while (i<=n){
		int mit=(max+min)/2; //posición del punto medio de array. 
		i++;
		if (A[mit]==clave){
		cout<<"Se encontró el número "<<clave<<" en la posición "<<mit+1<<endl;
			cond='V';
			break;
		}
		else if (A[mit]>clave){
			max=mit; 
		}
		else if (mit<clave){
			min=mit;
		}
	}
	if (cond!='V'){ //si ya se agotó el while y la condición no es verdadera. 
	
		cout<<"No se encontró el número "<<clave<<endl;
	}
}	
//////////////////////////////////////////////////////
int main(){
	int n=15;
	int A[n]={0,1,2,4,5,6,7,9,10,11,13,14,15,20,28};
	int clave=4;
	binaria(A,n,clave);
	return 0; 
}

