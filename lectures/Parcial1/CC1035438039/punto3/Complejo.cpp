//
// Created by kevin on 16/07/22.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Complejo.h"

Complejo::Complejo(double parteReal, double parteImaginaria) : parteReal(parteReal), parteImaginaria(parteImaginaria) {}

Complejo::Complejo() = default;

void Complejo::asignarDatos(double parteReal, double parteImaginaria) {
    this->parteReal = parteReal;
    this->parteImaginaria = parteImaginaria;
}

double Complejo::obtenerParteReal() const {
    return this->parteReal;
}

double Complejo::obtenerParteImaginaria() const {
    return this->parteImaginaria;
}

void Complejo::imprimirComplejo() const {
    if (this->parteImaginaria > 0){
        std::cout << this->parteReal << " + "  << this->parteImaginaria << "i" << std::endl;
    }else if(this->parteReal == 0 && this->parteImaginaria == 0){
        std::cout << "0" << std::endl;
    }
    else{
        std::cout << this->parteReal << " - "  << std::abs(this->parteImaginaria) << "i" << std::endl;
    }
}

double Complejo::norma() const {
    return std::sqrt(std::pow(this->parteReal,2) + std::pow(this->parteImaginaria,2));
}

AritmeticaCompleja::AritmeticaCompleja() = default;

Complejo AritmeticaCompleja::sumarDosComplejos(Complejo c1, Complejo c2) {
    double parteReal = c1.obtenerParteReal() + c2.obtenerParteReal();
    double parteImaginaria = c1.obtenerParteImaginaria() + c2.obtenerParteImaginaria();
    return {parteReal, parteImaginaria};
}

Complejo AritmeticaCompleja::restarDosComplejos(Complejo c1, Complejo c2) {
    double parteReal = c1.obtenerParteReal() - c2.obtenerParteReal();
    double parteImaginaria = c1.obtenerParteImaginaria() - c2.obtenerParteImaginaria();
    return {parteReal, parteImaginaria};
}

Complejo AritmeticaCompleja::multiplicarDosComplejos(Complejo c1, Complejo c2){
    double parteReal = (c1.obtenerParteReal() * c2.obtenerParteReal()) - (c1.obtenerParteImaginaria() * c2.obtenerParteImaginaria());
    double parteImaginaria = (c1.obtenerParteReal() * c2.obtenerParteImaginaria()) + (c1.obtenerParteImaginaria() * c2.obtenerParteReal());
    return {parteReal, parteImaginaria};
}


