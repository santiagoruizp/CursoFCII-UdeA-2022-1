//
// Created by kevin on 15/07/22.
//
#include <iostream>
#include <iomanip>
#include "IntegralSolver.h"

IntegralSolver::IntegralSolver() = default;

double IntegralSolver::trapezoide(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones) {
    double h = ( limiteSuperior - limiteInferior )/numeroDivisiones;
    double suma = ( f(limiteInferior) + f(limiteSuperior) )/2.0;
    for (int i = 0; i < numeroDivisiones; ++i) {
        suma += f( limiteInferior + (i*h) );
    }
    return h*suma;
}

void IntegralSolver::imprimirValorTrapezoide(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones) {
    std::cout <<
        std::setprecision(5) <<
        "El valor de la integral con metodo trapezoide en ("<< limiteInferior << "," << limiteSuperior << ") y con " <<  numeroDivisiones <<" divisiones es: " <<
        this->trapezoide(f, limiteInferior, limiteSuperior, numeroDivisiones) <<
        std::endl;
}

double IntegralSolver::simpson(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones) {
    double h = ( limiteSuperior - limiteInferior ) / ( 2.0*numeroDivisiones );
    double suma =  f(limiteInferior) + f(limiteSuperior) + 4.0*f(limiteInferior+h);
    for (int i = 0; i < numeroDivisiones; ++i) {
        suma += 2.0*f( limiteInferior + (2.0*i*h) ) + 4.0*f( limiteInferior + h + (2.0*i*h) );
    }
    return h*suma / 3.0;
}

void IntegralSolver::imprimirValorSimpson(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones) {
    std::cout <<
              std::setprecision(5) <<
              "El valor de la integral con metodo Simpson en ("<< limiteInferior << "," << limiteSuperior << ") y con " <<  numeroDivisiones <<" divisiones es: " <<
              this->simpson(f, limiteInferior, limiteSuperior, numeroDivisiones) <<
              std::endl;
}