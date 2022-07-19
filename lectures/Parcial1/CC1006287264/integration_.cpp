#include <iostream>
using namespace std;
#include<math.h>

#define f(x) 1/(3 + pow(x,3))   // Función a integrar

void trapezoidalRule ();
void simpson();

int main(){
    int a;
    cout<< " Desea integrar con el metodo de simpson(0) o trapezoidal(1): ";
    cin >> a;
    if(a == 0)
{
  simpson();
}

else if(a == 1)
{
 trapezoidalRule();
}


}




void trapezoidalRule (){
double a, b;
int n;
cout << "Ingrese el valor de los limites: ";
cin >> a >> b;
cout << "Ingrese el numero de intervalos: ";
cin >> n;
double h = abs(b - a) / n; // distancia de cada intervalo
double fx = 0;
fx = fx + f(a) + f(b);
for (double i = a+h; i < b;){
fx = fx + (2 * f(i));
i = i + h;
}
fx = fx * h / 2;
cout << "\n Resultado usando el metodo trapezoidal " << fx << endl;
}

void simpson()
{
 float a, b, integration=0.0, h, k;
 int i, n;

 /* Input */
 cout << "Ingrese el valor de los limites: ";
 cin >> a >> b;
 cout<<"Ingrese el numero de intervalos: ";
 cin>>n;

 

// Tamaño de paso
 h = abs(b- a)/n;

 // se guarda el valor en integration en cada paso
 integration = f(a) + f(b);

 for(i=1; i<= n-1; i++)
 {
  k = a + i*h;
  

  if(i%2==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 4 * (f(k));
  }

 }

 integration = integration * h/3;

 cout << "\n Resultado usando el metodo simpson " << integration<< endl;
}

