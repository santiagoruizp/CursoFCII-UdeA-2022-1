#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

#include "EDP_Expo.h"

double func1(double); //prototipo funcion condicion de frontera 
double func2(double); //prototipo funcion condicion de frontera para la velocidad

double func1E2(double); // Prototipo ejemplo 2
double func2E2(double); // Prototipo ejemplo 2

int main()
{
    double h, k, c, r; // Parametros de entrada
    h=0.1;  // particion del intervalo en x
    k=0.05; // particion del intervalo en x
    c=4.0;  // contante que acompaña la doble derivada espacial
    //c=1.0;  // contante que acompaña la doble derivada espacial Ejemplo 2
    r=(c*k)/h;
    WaveSol solucion(h, k, r, &func1, &func2); // Inicializa la clase WaveSol
    solucion.resultado(); // Muestra el resultado en pantalla, y devuelve un archivo solucion
    //WaveSol solucionE2(h, k, r, &func1E2, &func2E2);
    //solucionE2.resultado();
    return 0;

}

double func1(double x) // Las funciones f y g son parameros de entrada, condiciones de frontera
{
    const double Pi=3.141592653589793;
    return sin(Pi*x)+sin(2*Pi*x);
}

double func2(double x)
{
    const double Pi=3.141592653589793;
    return 0;
}

// Ejemplo 2 condiciones de frontera
double func1E2(double x)
{
    const double Pi=3.141592653589793;
    return sin(2*Pi*x);
}

double func2E2(double x)
{
    const double Pi=3.141592653589793;
    return 2*Pi*sin(2*Pi*x);
}