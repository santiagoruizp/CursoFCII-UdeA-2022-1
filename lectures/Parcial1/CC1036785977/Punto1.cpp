/*
Santiago Ruiz Piedrahita
Parcial #1 
Punto #1

El codigo hace integrales numericas por medio del metodo trapezoidal y simpson
*/
#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

// Definimos la funcion a integrar

double F(double x)
{
    return x*x;
}

// limites de integracion
float a = 1;
float b = 2;

// numero de la particion
int N = 100; // Para simpson N debe ser par

// Definimos la funcion trapezoidal
double trapezoidal(float a,float b, int N)
{
    float dx=(b-a)/N;    
    double sum = F(a)+F(b);
    
    for (int i = 1; i < N; i++) 
        sum += 2 * F(a + i * dx); 
    
    double integral = (dx*sum)/2;
    
    return integral;
}

// Definimos la funcion simpson
double simpson(float a,float b, int N)
{
    float dx=(b-a)/N;    
    double sum = F(a)+F(b);
    
    for (int i = 1; i < N; i+=2) 
        sum += 4 * F(a + i * dx); 
    
    for (int i = 2; i < N-1; i+=2) 
    sum += 2 * F(a + i * dx);
    
    double integral = (dx*sum)/3;
    
    return integral;
}

// funcion main
int main()
{
    cout<<"trapezoidal: "<<setprecision(20)<<trapezoidal(a,b,N)<<endl;
    cout<<"simpson: "<<setprecision(20)<<simpson(a,b,N)<<endl;
    cout<<"La diferencia entre los metodos es de: "<<abs(trapezoidal(a,b,N)-simpson(a,b,N))<<endl;
    return 0;
}



