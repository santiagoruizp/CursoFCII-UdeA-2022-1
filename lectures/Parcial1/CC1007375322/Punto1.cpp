#include <iostream>
#include <cmath>

using namespace std;

double Trapezoidal(double, double, int);

double Simpson(double, double, int);

double funcion(double);

double errorporc(double,double,double);


int main()
{
  cout<<"Ingrese el intervalo a integrar [a,b] y el número n de particiones: "<<endl;
  double a,b;
  int n;
  cin>>a>>b>>n;
  double intTrap=Trapezoidal(a,b,n);
  double intSimp=Simpson(a,b,n);
  double errTrap=errorporc(a,b,intTrap);
  double errSimp=errorporc(a,b,intSimp);
  cout << "El error porcentual para el método del trapecio es del "<< errTrap<<"%  y para el método de Simpson es del "<<errSimp<< "%"<< endl;
  if(errTrap<errSimp)
    cout<<"por tanto el método del Trapecio es mejor"<<endl;
  else
    cout<<"por tanto el método de Simpson es mejor"<<endl;

  return 0;
  
}

double errorporc(double a, double b, double integral)
{
  double realint=(pow(b,4)-pow(a,4))/4;
  double error=abs(realint-integral)*100/realint;
  return error;
}

double funcion(double x)
{
  return pow(x,3);
}

double Simpson(double a, double b, int n)
{
  double h=(b-a)/n;
  double sumf0=funcion(a)+funcion(b);
  double sumf1=0;
  double sumf2=0;
  int j=1;
  double x=a;

  for (j;j<n;j++)
    {
      x=a+j*h;
      if(j%2==0)
	sumf2+=funcion(x);
      else
	sumf1+=funcion(x);
    }
  return (h/3)*(sumf0+2*sumf2+4*sumf1);

   
}

double Trapezoidal(double a, double b, int n)
{
  double h=(b-a)/n;
  double sumf=0;
  int j=1;
  double x=a;

  for (j;j<n;j++)
    {
      x=a+j*h;
      sumf+=funcion(x);

    }
  return (h/2)*(funcion(a)+funcion(b)+2*sumf);
}
