/*Tarea1.
La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una lista ordenada de elementos.
Funciona al dividir repetidamente a la mitad la porción de la lista que podría contener al elemento,
hasta reducir las ubicaciones posibles a solo una.
Para terminar, el algoritmo encuentra un elemento que coincide con la clave de búsqueda o reduce el subvector hasta un tamaño de cero.
Por favor, Cree un programa en c++ para implementar la búsqueda binaria.*/


#include "BusquedaBinaria.h"

int main(){
    // se introduce el número a buscar
    int num;
    cout <<"Ingrese el número entero entre 0 y 198 que desea encontrar en la lista: "<<endl;
    cin >> num;
    // se usa la función para buscar el indice del número
    BusquedaBinaria(num);
    return 0;
}