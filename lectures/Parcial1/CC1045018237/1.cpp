// Evaluación de integrales utilizando la regla del trapezio
#include <stdio.h>
#include <math.h>

double Func(double x) { return 1/x; } //definimos la función del ejemplo manual

//===========================================================================
double qTrapz(double Func(double), double a, double b, int n) // definimos la función de la regla trapezoide y cada uno de sus parametros
//---------------------------------------------------------------------------
// intervalo de integración [a,b] 
// n son los puntos de integración
//---------------------------------------------------------------------------
{
   double h, s;
   int i;

   h = (b-a)/(n-1);                             /* este es el algoritmo que definimos en el ejemplo donde h es el cambio en la funcion */
   s = 0.5*(Func(a) + Func(b));       // Este s es T0 en el ejemplo
   for (i=1; i<=(n-2); i++) s += Func(a+i*h); // acá, evaluamos cada uno de los puntos interiores fi
   
   return h*s;
}

int main()
{
   double a, b;    // definimos los limites de la integral como de doble presición
   int n;          // los puntos de integracion o división de los intervalos será un entero
   
   a = 1; b = 2; n = 100; 
   printf("I = %f\n",qTrapz(Func,a,b,n)); // finalmente llamamos a la función
}
