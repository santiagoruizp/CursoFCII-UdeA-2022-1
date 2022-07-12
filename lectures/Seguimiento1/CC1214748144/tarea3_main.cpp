
#include "tarea3_inter.cpp" 
#include <iostream>
using namespace std;
int main()
{
float x;
int N;
cout<<"Ingrese el número del cuál desea conocer su exponencial"<<endl;
cin>>x;
cout<<"Ingrese hasta que número se va a realizar la suma"<<endl;
cin>>N;
  Exponencial Exp1(x,N);  
  Exp1.mostrar();
  return 0; 
} 
