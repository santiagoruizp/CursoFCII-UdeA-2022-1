#include <iostream>
#include <cmath>
using namespace std;

// Función a calcular integral
double Funcion(double x) {
    return sin(x);
}

//REGLA DEL TRAPECIO: RECIBE LIMITES DE INTEGRACIÓN Y NUMERO DE ITERACIONES EN EL CALCULO DE LA INTEGRAL
double Trapecio(double a, double b, unsigned int n) {
    const double h = (b - a) / n;
    double integral = (Funcion(a) + Funcion(b)) / 2;
    for (int i = 1; i < n; i++) {

        integral += Funcion(a + i * h);
    }

    integral *= h;
    return integral;

}


//REGLA DE SIMPSION: RECIBE LIMITES DE INTEGRACIÓN Y NUMERO DE ITERACIONES EN EL CALCULO DE LA INTEGRAL
double Simpson(double a, double b, unsigned int n) {
    const double h = (b - a) / n;
    double integral = (Funcion(a) + Funcion(b));
    for (int i = 1; i <= (n); i++) {
        if (i % 2 == 0)
            integral += 2 * Funcion(a + i * h);
        else
            integral += 4 * Funcion(a + i * h);
    }

    integral *= (h / 3);
    return integral;

}

int main() {

    cout << "La integral usando la regla de Simpson es: "  << Simpson(0, M_PI, 10000) << endl;
    cout << "La integral usando la regla del Trapecio es: " << Trapecio(0, M_PI, 10000) << endl;
    return 0;
}