#include <iostream>
#include <bits/stdc++.h>
#include <vector>

#include "BinarySearch.h"

int main() {
//    Creo el vector para probar el programa
    std::vector<int> vector{20,13,15,10,9,7,6};

//    Ordeno el vector con una funcion de la libreria bits/stdc++
    std::sort(vector.begin(), vector.end());
    std::cout<< "El vector ordenado es:" << std::endl;
//    Se imprime el vector en pantalla para comprobar que esta ordenado
    for (auto x : vector)
        std::cout << x << " ";
    std::cout << std::endl;

// Pruebo con un elemento que si este en el vector, la respuesta debe ser el índice del elemento en el arreglo ordenado
    try{
        int respuesta =  BinarySearch::binarySearch(vector, 15);
        std::cout<<"El indice del elemento es: "<< respuesta << std::endl;
    } catch (const char* msg){
        std::cout<< msg << std::endl;
    }

//    Pruebo con un elemento que no este en el vector, la respuesta debe ser el numero no está en el vector
    try{
        int respuesta =  BinarySearch::binarySearch(vector, 1);
        std::cout<<"El indice del elemento es: "<< respuesta << std::endl;
    } catch (const char* msg){
        std::cout<< msg << std::endl;
    }

//    Pruebo con un vector vacio, la respuesta debe ser que el vector esta vacio
    std::vector<int> vectorVacio{};
    try{
        int respuesta =  BinarySearch::binarySearch(vectorVacio, 15);
        std::cout<<"El indice del elemento es: "<< respuesta << std::endl;
    } catch (const char* msg){
        std::cout<< msg << std::endl;
    }


    return 0;
}
