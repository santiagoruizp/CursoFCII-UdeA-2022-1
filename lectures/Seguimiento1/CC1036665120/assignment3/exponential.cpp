/*
El factorial de un entero "n" no negativo se escribe como n! (n factorial) y se define de la siguiente manera:
n! = n · (n – 1) · (n – 2) · . . . · 1 ( para valores de n mayores o iguales a 1)
y n! = 1 ( para n = 0 o n = 1).

Esta clase devuleve el valor de e^x:

e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......
*/

#include <iostream>
#include <cmath>
#include <tuple>
#include "exponential.h"

using namespace std;


ExponentialSeries::ExponentialSeries(){

} 

// ------------------------------------------
// INGRESA LAS VARIABLES 
// ------------------------------------------

tuple<int, float> ExponentialSeries::getNumberFromUser()
{
    int n=0;
    float x=0; 
    cout << "Este programa calcula la Función exponencial a partir de una serie de Taylor:" << endl;
    cout << "e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  ......." << endl;
    cout << "Ingrese el exponente: "; 
    cin >> x;
    cout << "Ingrese la precisión de la serie: ";
    cin >> n;
    return {x, n};
}


// ------------------------------------------
// CALCULA EL FACTORIAL
// ------------------------------------------
double ExponentialSeries::factorial(int n)
{
    double result = 1;
    
    // calcula el factorial de un número n
    if (n == 0 or n == 1){
        result = 1;
    }else{
        for (int i = 1; i <= n; i++)
        {
        result = result * i;
        }
    }

    return result;
}

// ------------------------------------------
// CALCULA LA SERIE EXPONENCIAL
// e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......
// ------------------------------------------

double ExponentialSeries::calculateSeries(float x, int n)
{
    cout << "Los valores introducidos son: "<< endl;
    cout << "n = "<< n << endl;
    cout << "x = "<< x << endl;

    double result = 0;
    double factor = 0;
    for (int i = 0; i <= n; i++)
    {
        // Calcula cada uno de los términos de la serie y los va sumando
        factor = factorial(i);
        result = result + pow(x,i)/factor;
        cout << "Término " << i << " = " << result <<endl;
    }
    return result;
}

// ------------------------------------------
// MUESTRA MENSAJE DEL RESULTADO
// ------------------------------------------

void ExponentialSeries::showResult(float e)
{
    cout << "El resultado de la serie exponencial es: "<<  e << endl;

}

