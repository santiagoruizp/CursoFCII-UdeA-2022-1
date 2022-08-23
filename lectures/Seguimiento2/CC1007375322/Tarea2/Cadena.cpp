#include "Cadena.h"

void RecibirCadenas(const string cadena1, const string cadena2){
    // Se imprimen las cadenas recibidas
    cout << "La primera cadena ingresada es: "<<cadena1<< endl;
    cout << "La segunda cadena ingresada es: "<<cadena2<< endl;

     // comparación de cadena1 y cadena2
    if ( cadena1 == cadena2 )
    cout << "Las cadenas son iguales\n";
    else 
    {
        if ( cadena1 > cadena2 )
    cout << "La primera cadena es mayor a la segunda alfabeticamente (cadena1 > cadena2)\n";
        else 
    cout << "La segunda cadena es mayor a la primera alfabeticamente (cadena2 > cadena1)\n";
    }
    // se crea una cadena nueva para guardar la cadena1 con las vocales en mayusculas
    string cadena3=cadena1;
    string voc= "aeiou";
    // se corre sobre el string
    for ( size_t i{0}; i < cadena3.length(); i++ ){
        // se comprueba si es vocal y cual es
        int ind=voc.find(cadena3.at(i));
        // si ind es postivo o cero, es una vocal e ind corresponde al indice en voc de la vocal
        if (ind>=0){
            //con toupper se convierte en mayuscula
            cadena3.at(i)= static_cast <char> (toupper(voc.at(ind)));
        }
    }
    cout<< "Primera cadena con vocales en mayusculas: "<<cadena3<< endl;
    // se hace una copia de la cadena2 para hacer mayusculas las consonantes
    string cadena4=cadena2;
    // se realiza proceso análogo, solo que ahora nos importan los ind negativos, es decir que no son vocales
    for ( size_t i{0}; i < cadena4.length(); i++ ){
        int ind=voc.find(cadena4.at(i));
        if (ind<0){
            cadena4.at(i)= static_cast <char> (toupper(cadena4.at(i)));
        }
    }
    cout<< "Segunda cadena con consonantes en mayusculas: "<<cadena4<< endl;
    //concatenamos las cadenas
    string cadenaconct=cadena3.append(cadena4);

    cout << "Las cadenas concatenadas: "<<cadenaconct<<endl;
    string cadenainv=cadenaconct;
    // ahora invertimos la cadena concatenada
    int k=cadenaconct.length()-1;
    // hacemos un for y recorremos la cadena y el k en sentido inverso
    for(size_t i{0}; i < cadenaconct.length(); i++){
        cadenainv.at(k)=cadenaconct.at(i);
        k--;
    }
    cout << "La cadena concatenada invertida es: "<<cadenainv<<endl;

};