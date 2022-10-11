#ifndef WAVE_H
#define WAVE_H

#include<iostream>
using namespace std;

class WaveSol
{
        
    public:
        WaveSol(double, double, double,
             double (*func1)(double), double (*func2)(double)); // constructor de la clase
        double (*f_x)(double); // funcion condicion de frontera
        double (*g_x)(double);
        void print(const double matriz[11][11]); // matriz solucion
        void resultado(); // Muestra resultados y genera archivo
        
    private:
        double h;
        double k;
        double r;
};
#endif