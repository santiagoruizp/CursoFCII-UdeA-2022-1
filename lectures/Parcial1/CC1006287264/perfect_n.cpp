#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#include "perfect.h"

int perfect_n::perfect(int c )
{  
   int m = 0; // variable de loop
   int total = 0;
   for(m=1; m<c; m=m+1) // For loop 
   {
    if(c % m == 0) 
    total = total + m; // Si es divisible se acumula en la suma
    
   }

    if(total == c)
    
    cout << "Numero perfect: "<< c <<"\n";
    
    return c;
}

void perfect_n::printDivisors(int k)
{
    int i;
    for (i = 1; i * i < k; i++) {
        if (k % i == 0)
            cout<<i<<" ";
    }
    if (i - (k / i) == 1) {
        i--;
    }
    for (; i >= 1; i--) {
        if (k % i == 0)
            cout<<k / i<<" ";
    }
    return ;
}



double perfect_n::evaluate_n(int n )
{

int j = 1;

int total = 0;

//cin >> n;
for(j=1; j<=n; j=j+1) // Outer FOR loop
{  

   
   total= perfect(j);
   
   
   
} // outer loop ends
//cout << "this fucking shit";
printDivisors(perfect(j));
return 0;
 
}
