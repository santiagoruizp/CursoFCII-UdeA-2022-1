/* Tarea3.
El factorial de un entero "n" no negativo se escribe como n! (n factorial) y se define de la siguiente manera:
n! = n · (n – 1) · (n – 2) · . . . · 1 ( para valores de n mayores o iguales a 1)
y
n! = 1 ( para n = 0 o n = 1).

Usando las tecnicas de programcion orienta a objetos (POO) que hemos estudiado, cree una clase que nos devuleva el valor de e^x:

e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......

Su clase debe tener almenos las siguientes caracteristicas:
dos variables privadas: el valor de "x" y "N"la presicion (el numero de terminos de la serie).
Debe tener un constructor.
Ademas debe tener dos funciones mas:
a) una que lea un entero no negativo, que calcule su factorial.
b) una que calcule el valor de e^x.
Finalmente debe tener una funcion que muestre el valor de e^x
*/



#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Exponencial
{
public:
  Exponencial(double,int);
  double fact( int ); //Calcula factorial
  double exponencial( double,int ); //Calculo float
  void mostrarResult(double);
 
 
private:
float x; 
int N; 

};

int main()
{
  int N;
  double x;
  cout<< "Ingrese el valor de x: "<<endl;
  cin>>x;
  cout << "Ingrese el número de terminos de la serie N: "<<endl;
  cin>>N;
  Exponencial calculo(x,N);
  return 0;
}



double Exponencial::fact(int num)
{
  int mm = 1;
  double factorial = 1;

  if (num == 0){ factorial=1; }
  else{
    
    while(mm<=num){
      factorial*=mm;
      mm++;
    }
    
  }

  return factorial;
}

double Exponencial::exponencial(double x, int N)
{
  int n=0;
  double sumserie=0;
  while(n<=N)
    {
      sumserie+=pow(x,n)/fact(n);
      n++;
    }
  return sumserie;
}
void Exponencial::mostrarResult(double result)
{
  cout << "El valor de la exponencial e^x es: "<<result << endl;
}

Exponencial::Exponencial(double x, int N)
{
  mostrarResult(exponencial(x,N));
}
