/*Tarea2.
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
    Imprimir la cadena concatenada invertida*/



#include "Cadena.h"
int main(){
    // se crean dos cadenas y se pregunta al usuario por ellas, puede contener espacios
    string cadena1,cadena2;
    cout << "Escriba la primera cadena: ";
    getline(cin,cadena1); 
    cout << "\n\nEscriba la segunda cadena: ";
    getline(cin,cadena2);
    // se llama a la función RecibirnCadenas
    RecibirCadenas(cadena1,cadena2);
}

