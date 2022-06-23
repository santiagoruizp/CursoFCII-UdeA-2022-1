/*
Usando las tecnicas de programcion orienta a objetos (POO) que hemos estudiado, cree una clase que nos devuleva el valor de e^x:
e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......
Su clase debe tener almenos las siguientes caracteristicas:
dos variables privadas: el valor de "x" y "N"la presicion (el numero de terminos de la serie).
Debe tener un constructor.
Ademas debe tener dos funciones mas:
a) una que lea un entero no negativo, que calcule su factorial.
b) una que calcule el valor de e^x.
Finalmente debe tener una funcion que muestre el valor de e^xe	|
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std; 
////////////////////////////////////////////////////////////////////////////////
class Exponencial{
 private: //características
  int N; 
  float x; 
public: // acciones
  Exponencial(int, float);//los constructores ayudan a inicializar las características
  float fact(int);
  float serie(int,float);
  void mostrar(float);
};

/////////////////////////////////////

Exponencial::Exponencial(int N,float x)
{
 fact(N);
 serie(N, x);
}

float Exponencial::fact(int K){
	 return tgamma(K + 1); 
}
 
float Exponencial::serie(int N, float x){ 
float sum=0;
for (int c=0;c<=N;c++){
sum+=(pow(x,c))/(fact(c));
}
  return sum;
}

void mostrar(float resul){
 cout<<"EL valor de e^x es:"<<resul<<endl;
}
///////////
int main(){
float x;
int N;
float R;
cout<<"Ingrese el número al que le quiere conocer la exponencial"<<endl;
cin>>x;
cout<<"Ingrese hasta dónde quiere realizar la suma"<<endl;
cin>>N;
  Exponencial exp1(N,x);
  R=exp1.serie(N,x);
  cout<<R<<endl;
   //exp1.mostrar(R);
  return 0; 
}
