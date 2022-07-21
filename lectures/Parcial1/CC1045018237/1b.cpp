// regla de simpson
#include <stdio.h>
#include <math.h>

double Func(double x) { return 1/x; } //definimos la función del ejemplo manual




double qSimpson(double Func(double), double a, double b, int n)
//---------------------------------------------------------------------------
// intervalo de integración [a,b]
// para n intervalos
//---------------------------------------------------------------------------
{
double h, s1, s2;
int i;
if (n % 2 == 0) n++;
 //  si el incremento de n es par
h = (b-a)/(n-1);
s1 = s2 = 0e0;
for (i=2; i<=n-3; i+=2) { s1 += Func(a + i*h); }
for (i=1; i<=n-2; i+=2) { s2 += Func(a + i*h); }
return (h/3)*(Func(a) + 4*s2 + 2*s1 + Func(b));
}

int main()
{
   double a, b;    // definimos los limites de la integral como de doble presición
   int n;          // los puntos de integracion o división de los intervalos será un entero
   
   a = 1; b = 2; n = 100; 
   printf("I = %f\n",qSimpson(Func,a,b,n)); // finalmente llamamos a la función
}