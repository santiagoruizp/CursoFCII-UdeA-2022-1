#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "tarea3.h"
using namespace std; 
Exponencial::Exponencial(int N,float x)
{
 fact(N);
 serie(N, x);
}
float Exponencial::fact(int K){
#include <cmath>
	 return tgamma(K + 1);  
}
float Exponencial::serie(int N, float x){ 
float sum=0;
for (int c=0;c<=N;c++){
sum+=(pow(x,c))/(fact(c));
}
  return sum;
}
//void mostrar(float resul){
 //cout<<"EL valor de e^x es:"<<resul<<endl;
//}

