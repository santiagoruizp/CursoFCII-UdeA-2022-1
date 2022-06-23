//
// Created by kevin on 22/06/22.
//

#include "Exponencial.h"

#include <cmath>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;

Exponencial::Exponencial(double x, int n) : x(x), N(n) {};

double Exponencial::getX() const {
    return x;
}

void Exponencial::setX(double x) {
    Exponencial::x = x;
}

int Exponencial::getN() const {
    return N;
}

void Exponencial::setN(int n) {
    N = n;
}

int Exponencial::calcularFactorial( int n ){
    int factorial;
    if(n==0){
        factorial = 1;
    }else{
        factorial = 1;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
    }
    return factorial;
}

double Exponencial::calcularExponencial(){
    double valorFinal = 0 ;
    for (int i = 0; i < Exponencial::getN(); ++i) {
        valorFinal += pow(Exponencial::getX(),(i)) / Exponencial::calcularFactorial(i);
    }
    return valorFinal;
}

void Exponencial::getValor() {
    double valor = Exponencial::calcularExponencial();
    cout << setprecision(5) << fixed << valor;
}