/*
Tarea2.
Escribir una funcion, "RecibirCadenas",  que recibe como parametros dos cadenas que puede 
contener espacios, la funcion deberá:

    Decir qué cadena es mayor y cuál es menor alfabéticamente
    Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a 
    MAYÚSCULAS
    Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a 
    MAYÚSCULAS
    Generar una nueva cadena concatenando las dos que ya fueron convertidas
    Generar una nueva cadena que contenga la cadena concatenada invertida

Incluya la función "RecibirCadenas"  en un programa ejecutable en C++, y use el programa para 
pedir al usuario que introduzca las dos cadenas con las que probara su función.

Al finalizar el programa, este deberá:
    Imprimir las dos cadenas originales
    Imprimir las dos cadenas con las conversiones
    Imprimir la cadena concatenada
    Imprimir la cadena concatenada invertida

*/


#include <iostream>
#include <string.h>

using namespace std;



void RecibirCadenas( const string &cadena1,  const string &cadena2){

    // ------------------------------------------------------
    // --------------- COMPARAR LAS CADENAS -----------------
    // ------------------------------------------------------
    int compararAlfa(cadena1.compare( cadena2 ));

    if (compararAlfa > 0)
    {
        cout << "La cadena: '" << cadena1 << endl;
        cout << "' es mayor alfabéticamente que: '" << cadena2 << "'" << endl;
    }else{
        cout << "La cadena: '" << cadena2 << endl;
        cout << "' es mayor alfabéticamente que: '" << cadena1 << "'" << endl;
    }


    // ------------------------------------------------------
    // ---------- CONVERTIR VOCALES A MAYÚSCULAS ------------
    // ------------------------------------------------------
    string cadena1_mayus = "";
    string::const_iterator iterador1 = cadena1.begin(); 
  
    // itera a través del objeto string
    while ( iterador1 != cadena1.end() )
    {
        if ( *iterador1 == 'a' ||  *iterador1 == 'e' || *iterador1 == 'i' ||
            *iterador1 == 'o' || *iterador1 == 'u'){ 

	        cadena1_mayus.push_back(toupper( *iterador1 )); // lo convierte a mayúscula

        }else{

            cadena1_mayus.push_back( *iterador1 );

        }
        iterador1++; // avanza el iterador al siguiente char
    
    } 

    cout << "La cadena 1 con vocales mayúscuas: '" << cadena1_mayus << endl;


    // ------------------------------------------------------
    // -------- CONVERTIR CONSONANTES A MAYÚSCULAS ----------
    // ------------------------------------------------------
    string cadena2_mayus = "";
    string::const_iterator iterador2 = cadena2.begin(); 
  
    // itera a través del objeto string
    while ( iterador2 != cadena2.end() )
    {
        if ( islower( *iterador2 ) && isalpha( *iterador2 ) && !(*iterador2 == 'a' ||  *iterador2 == 'e' || *iterador2 == 'i' ||
            *iterador2 == 'o' || *iterador2 == 'u')){ 

	        cadena2_mayus.push_back(toupper( *iterador2 )); // lo convierte a mayúscula

        }else{

            cadena2_mayus.push_back( *iterador2 );

        }
        iterador2++; // avanza el iterador al siguiente char
    
    } 

    cout << "La cadena 2 con consonantes mayúscuas: '" << cadena2_mayus << endl;
    
    
    // ------------------------------------------------------
    // -------- CONCATENAR CADENAS CONVERTIDAS  -------------
    // ------------------------------------------------------
    string cadena3_concat = cadena1_mayus.append(cadena2_mayus);

    cout << "Las cadenas convertidas concatenadas: '" << cadena3_concat << endl;


    // ------------------------------------------------------
    // ------------- INVERTIR CADENA CONCATENADA  -----------
    // ------------------------------------------------------
    string cadena4_invert = "";
    string::const_iterator iterador3 = cadena3_concat.end(); 

        // itera a través del objeto string
    while ( iterador3 != cadena3_concat.begin() )
    {
        iterador3--; // retocede el iterador al anerior char
        cadena4_invert.push_back( *iterador3 );
    } 

    cout << "La cadena 3 invertida: '" << cadena4_invert << endl;

}


int main(){
    
    string cadena1;
    string cadena2;

    cout << "Ingresa la primera cadena: ";
    getline(cin, cadena1);

    cout << "Ingresa la segunda cadena: ";
    getline(cin, cadena2);
    
    cout << "La cadena 1 es: '" << cadena1 << endl;
    cout << "La cadena 2 es: '" << cadena2 << endl;

    RecibirCadenas( cadena1,  cadena2 );

    return 0;

}

