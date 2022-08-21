#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> RecibirCadenas(string cadena1, string cadena2);

int main() {
    string cadena1;
    string cadena2;

    cout << "Ingrese la primera cadena: " << endl;
    getline(cin, cadena1);
    cout << "cadena1 es: " << cadena1 << endl;

    cout << "Ingrese la segunda cadena: " << endl;
    getline(cin, cadena2);
    cout << "cadena2 es: " << cadena2 << endl;

    try{
        std::vector<std::string> vector = RecibirCadenas(cadena1, cadena2);
        for (auto x : vector) {
            cout << x << endl;
        }
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }

    return 0;
}


std::vector<std::string> RecibirCadenas(string cadena1, string cadena2){

//    response sera el vector con todos los strings que pide el problema
    std::vector<std::string> response;

//    validaciones de errores, solo se permiten cadenas que no sean vacias
    if(cadena1.empty() || cadena2.empty()){
        throw "No se puede ingresar cadenas vacias";
    }


// Se ponen las cadenas en minusculas y se realiza la comparacion con las cadenas en minusculas para poder que sea una comparacion alfabetica
    string cadena1Comparacion;
    for(char c : cadena1){
        cadena1Comparacion += tolower(c);
    }
    string cadena2Comparacion;
    for(char c : cadena2){
        cadena2Comparacion += tolower(c);
    }
//    Comparacion de las cadenas en minusculas para ver cual va "primero" en el alfabeto
    if ( cadena1Comparacion == cadena2Comparacion )
        response.push_back("cadena1 == cadena2");
    else
    {
        if ( cadena1Comparacion > cadena2Comparacion )
            response.push_back("cadena1 > cadena2");
        else
            response.push_back("cadena1 < cadena2");
    }


//  se ponen todas las vocales de la primera cadena en mayusculas
    string cadena_vocales (cadena1);
    string::const_iterator iterador_vocales = cadena_vocales.begin();
    std::vector<char> vocales{'a', 'e', 'i', 'o', 'u'};
//    Se usa un iterador que recorre cada caracter de la cadena1
    while ( iterador_vocales != cadena_vocales.end() )
    {
//        Se comprueba cuales caracteres son vocales
        bool found = (std::find(vocales.begin(), vocales.end(), *iterador_vocales) != vocales.end());
//        Cuando sean vocales se ponen en mayusculas
        if(found == 1){
//            Se halla indice en el que esta la vocal
            int index = cadena_vocales.find(*iterador_vocales);
//            Se pone la letra en mayusculas
            char upper = char(toupper(*iterador_vocales));
//            Se reemplaza en la cadena nueva con las vocales en mayusculas
            cadena_vocales.replace( index, 1, 1, upper);
        }
        iterador_vocales++; // avanza el iterador al siguiente char
    }
    response.push_back(cadena_vocales);


//    Se ponen todos los caracteres que sean consonantes de la cadena 2 en mayusculas, funciona muy parecido al anterior solo que con consonantes
    string cadena_consonantes (cadena2);
    string::const_iterator iterador_consonantes = cadena_consonantes.begin();
    std::vector<char> consonantes{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    while ( iterador_consonantes != cadena_consonantes.end() )
    {
        bool found = (std::find(consonantes.begin(), consonantes.end(), *iterador_consonantes) != consonantes.end());
        if(found == 1){
            int index = cadena_consonantes.find(*iterador_consonantes);
            char upper = char(toupper(*iterador_consonantes));
            cadena_consonantes.replace( index, 1, 1, upper);
        }
        iterador_consonantes++; // avanza el iterador al siguiente char
    }
    response.push_back(cadena_consonantes);


//  Se concatenan las cadenas que piden
    string concatenada (cadena_vocales + ' ' + cadena_consonantes);
    response.push_back(concatenada);


//  Se invierte la cadena concatenada, se puede hacer con el metodo reverse o con el iterador de mas abajo
//    string concatenada_inversa (concatenada);
//    reverse(concatenada_inversa.begin(), concatenada_inversa.end());

    string concatenada_inversa;
    string::reverse_iterator iterador3 = concatenada.rbegin();
    while ( iterador3 != concatenada.rend() ){
        concatenada_inversa += *iterador3;
        iterador3++;
    }
    response.push_back(concatenada_inversa);


    return response;
}
