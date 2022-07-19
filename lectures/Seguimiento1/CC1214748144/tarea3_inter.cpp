#include <iostream>
#include <cmath>
#include "tarea3.h"

using namespace std;

Exponencial::Exponencial(float _x, int _N)
{  
  x=_x;
  N=_N;
}


int Exponencial::factorial(int n)
{

if (n==0){
return 1;
}

  int fact = 1;
  if (n>0){
    for (int i=1;i<=n;i++){
      fact=i*fact;
    }
    return fact;
  }
   return 0;
}

float Exponencial::exp(float,int){
  float valExp = 1;
  for (int j=1; j<=N;j++){
    valExp+=(pow(x,j))/factorial(j);
  }
  return valExp;
}

void Exponencial::mostrar(){
  
  cout << "El valor de la exponencial para x = "<< x <<" con una suma en serie hasta N = "<<N<<" es: \n "<< exp(x,N)<<endl;
}
