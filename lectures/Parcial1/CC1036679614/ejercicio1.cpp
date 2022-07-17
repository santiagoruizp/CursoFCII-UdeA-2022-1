#include <iostream>
#include <cmath>
using namespace std;

// Función a calcular integral

double Funcion(double x) {
    return (x);
}

double Trapecio(double a, double b, unsigned int n) {
    const double h = (b - a) / n;
    double integral = (Funcion(a) + Funcion(b)) / 2;
    for (int i = 1; i < n; i++) {

        integral += Funcion(a + i * h);
    }

    integral *= h;
    return integral;

}

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

    cout << Simpson(0, 1, 10000);
    return 0;
