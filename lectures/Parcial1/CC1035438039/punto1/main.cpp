#include <iostream>
#include <iomanip>
#include <cmath>

#include "IntegralSolver.h"

double f(double x){
    return std::exp(-x);
}

int main() {
    IntegralSolver integralSolver;
    integralSolver.imprimirValorTrapezoide(f, 0.0, 1.0, 10000);
    integralSolver.imprimirValorSimpson(f, 0.0, 1.0, 1000);
    return 0;
}
