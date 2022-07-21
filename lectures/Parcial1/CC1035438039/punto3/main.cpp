#include <iostream>
#include <iomanip>
#include "Complejo.h"

int main() {
    Complejo complejo1;
    complejo1.asignarDatos(5,3);
    std::cout << "El primer complejo es: ";
    complejo1.imprimirComplejo();
    std::cout << std::setprecision(3) << "De norma: " << complejo1.norma() << std::endl;

    Complejo complejo2;
    complejo2.asignarDatos(6,5);
    std::cout << "El segundo complejo es: ";
    complejo2.imprimirComplejo();
    std::cout << "De norma: " << complejo2.norma() << std::endl;

    std::cout << std::endl;

    Complejo resultadoSuma = AritmeticaCompleja::sumarDosComplejos(complejo1, complejo2);
    std::cout << "El resultado de la suma es: ";
    resultadoSuma.imprimirComplejo();
    std::cout << "De norma: " << resultadoSuma.norma() << std::endl;

    Complejo resultadoResta = AritmeticaCompleja::restarDosComplejos(complejo1, complejo2);
    std::cout << "El resultado de la resta es: ";
    resultadoResta.imprimirComplejo();
    std::cout << "De norma: " << resultadoResta.norma() << std::endl;

    Complejo resultadoMultiplicacion = AritmeticaCompleja::multiplicarDosComplejos(complejo1, complejo2);
    std::cout << "El resultado de la multiplicacion es: ";
    resultadoMultiplicacion.imprimirComplejo();
    std::cout << "De norma: " << resultadoMultiplicacion.norma() << std::endl;

    return 0;
}
