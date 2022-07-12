#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#include "exponential.h"

double expo::fact(int c)
{  
   int factorial=1;
   for ( int i = 1; i <= c; i++ )
   {
      factorial *=i;
   }
   return factorial;
}
double expo::taylor(double , int )
{
    double approx;
    double sum;
    double value=0;
    for (int i=1; i<=n; i++)
    {
        sum=((pow(x,i))/fact(i));
        value+=sum;
    }
    approx = 1+value;
    return approx;  
}
