//
// Created by kevin on 5/08/22.
//

#include <iostream>
#include <algorithm>
#include "BinarySearch.h"

BinarySearch::BinarySearch() = default;

int BinarySearch::binarySearch(const std::vector<int>& vector, int toSearch) {

//    Comprobando si el vector tiene elementos; si esta vacio arroja un error indicando que esta vacio
    if(vector.empty()){
        throw "El vector esta vacio.";
    }

//    Se comprueba si el elemento a buscar si esta en el vector: si no esta arroja error indicando que el numero a buscar no esta en el vector
//  para hacer la comprobacion se usa una funcion de la libreria algorithm, tambien se puede hacer con un ciclo normal
    bool found = (std::find(vector.begin(), vector.end(), toSearch) != vector.end());
    if(found == 0){
        throw "El numero a buscar no esta en el vector.";
    }

//   La variable response es la que cargara con la respuesta hasta el final, la respuesta sera el indice del elemento en el arreglo ordenado
    int response;
//    Se halla el elemento del medio
    int middle = vector[(vector.size()-1)/2];
//    Si el elemento es el del medio, la respuesta sera el indice de este elemento
    if (middle == toSearch){
        response = (int)(vector.size()-1)/2;
    }
//    Si el elemento es mayor que el del medio, se llama de manera recursiva a la funcion de busqueda con solo la mitad superior del arreglo
    else if (middle > toSearch){
        std::vector<int> vector1(vector.begin(), vector.begin() + vector.size() / 2);
//        Al llamar la funcion con la mitad superior del arreglo, este se ira reduciendo en tamaño hasta encontrar el elemento.
        response = binarySearch(vector1, toSearch);
    }
//    Si el elemento es menor que el del medio, se llama de manera recursiva a la funcion de busqueda con solo la mitad inferior del arreglo
    else{
        std::vector<int> vector1((vector.begin() + vector.size() / 2)+1, vector.end());
        response = binarySearch(vector1, toSearch) + (int)(vector.size()-1)/2 + 1;
    }

    return response;
}
