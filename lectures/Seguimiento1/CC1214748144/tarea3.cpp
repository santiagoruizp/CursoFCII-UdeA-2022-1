#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "tarea3.C"
using namespace std; 
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
