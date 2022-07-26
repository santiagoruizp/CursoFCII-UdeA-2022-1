//
// Created by kevin on 15/07/22.
//

#ifndef UNTITLED1_INTEGRALSOLVER_H
#define UNTITLED1_INTEGRALSOLVER_H


class IntegralSolver {
public:
    IntegralSolver();

    static double trapezoide(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones);

    static double simpson(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones);

    void imprimirValorTrapezoide(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones);

    void imprimirValorSimpson(double (*f)(double), double limiteInferior, double limiteSuperior, int numeroDivisiones);
};


#endif //UNTITLED1_INTEGRALSOLVER_H
