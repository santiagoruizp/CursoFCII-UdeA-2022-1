#include <iostream>
#include "Tarea3.h"
#include <cmath>
using namespace std;


calculo::calculo(float a, unsigned int b){
  x=a;
  N=b;
}

int calculo::factorial(unsigned n){
  unsigned long k=1;
  for (unsigned long i = 1; i <= n; i++){
    k*=i;
    
  }
  
  return k;

}

float calculo::exponencial(){
  
  float c=0;
  for (unsigned long i=0; i<=N ; i++){
    c+=pow(x,i)/factorial(i);
  }
  return c;
}

void calculo::imprime_factorial(unsigned int n){
  cout << "El factorial de "<< n << " es: " << factorial(n)<< endl;
  }
 
void calculo::imprime_exponencial(){
  cout << "La exponencial de " << x << " es: " << exponencial() << " con una precisión de "<< N << " terminos" << endl; 
 }
 
