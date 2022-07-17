#include <iostream>
#include <cmath>
#include "Tarea3.h"
using namespace std;


Exponencial::Exponencial(string) // Inizializa
{
    val_x;
    N;    
}

void Exponencial::mostrarMensaje() // Muestra el mensaje de bienvenida
{
    cout << "Bienvenido, aqui puede evaluar la funcion exponencial" << endl;
}

void Exponencial::recibirParametros() // solicita los parmetros al usuario y estos son guardados
{
    cout << "Ingrese el valor (x) donde quiere evaluar: ";
    cin >> val_x;
    cout << "Ingrese la precision: ";
    cin >> N;
}

void Exponencial::mostrarResultados() // Entrega resultados
{
    cout << "El valor de " << N << "! es: " << factorial(N) << endl;
    cout << "La funcion e elevadado a la " << val_x << " es: " << expoFunction(val_x, N) << " con una precision de " << N << " terminos en la serie"; 
}

int Exponencial::factorial(int M) // hace el producto de los N terminos del factorial
    {
        int count, productorio = 1;        
        for (count=1;count<=M;count+=1)
            {
                productorio = productorio*count;
            }
        return productorio;
    }

double Exponencial::expoFunction(double val, int M) // hace la suma de los N+1 terminos de la serie
    {
    double e, e_x=0.0;
    int count;
    if (val==0)
        {
            e=1;
        }
    else
        {
            for (count=1;count<=M;count+=1)
            {
                e_x = e_x + pow(val,count)/factorial(count); 
            }
        }
    return e_x + 1;
    }