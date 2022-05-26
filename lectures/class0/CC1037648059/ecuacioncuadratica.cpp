#include "iostream"
#include<cmath>
using namespace std;
int main()
{
  double a,b,c,d;
  cout<<"Hola, ingresa los valores de la ecuacion cuadratica en el siguiente formato:"<<endl;
  cout<<endl;
  cout<<"a x**2 + b x + c = 0"<<endl;
  cout<<endl;
  cout<<"Ingrese el valor de a: "<<"\t";
  cin>>a;
  cout<<"Ingrese el valor de b: "<<"\t";
  cin>>b;
  cout<<"Ingrese el valor de c: "<<"\t";
  cin>>c;
  // printf("%d\n%d\n%d",a,b,c);
  d=b*b-4*a*c;
  cout<<endl;
  if(d>0)
    {
     cout<<"Las raices de la ecuacion son reales: "<<endl;
     cout<<endl;
     cout<<"x1="<<(-b+sqrt(d))/(2*a)<<endl;
     cout<<"x2="<<(-b-sqrt(d))/(2*a)<<endl;
    }
  else if(d<0)
    {
     cout<<"Las raices de la ecuacion son complejas: "<<endl;
     cout<<endl;
     cout<<"x1="<<(-b)/(2*a)<<" +i "<<sqrt(-d)/(2*a)<<endl;
     cout<<"x2="<<(-b)/(2*a)<<" -i "<<sqrt(-d)/(2*a)<<endl;
    }
  else if(d==0)
    {
      cout<<"Solo tiene una raiz esta ecuacion: "<<endl;
      cout<<endl;
      cout<<"x="<<(-b)/(2*a)<<endl;
    }
  
  
  
  


  return 0;
}
