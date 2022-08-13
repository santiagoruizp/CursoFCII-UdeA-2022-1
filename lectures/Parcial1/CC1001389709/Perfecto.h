#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void perfecto(int n){

   // Cualquier número tiene a lo sumo int(n/2+1) divisores
   int div[int(n/2)] = {0};
   
   // Suma de los divisores
   int sum = 0;

   // Se calculan los divisores. El mayor divisor es la mitad del número
   for (int i = 1; i <= int(n/2); i++){
   
      //Si es divisor se guarda en el arreglo div y se suma a sum
      if (n%i == 0){
         div[i] = i;
         sum += i;
      }      
   }

   // Si es perfecto se imprimen sus divisores   
   if (sum == n){
   
      cout<<"Divisores de "<<n<<": ";
      
      for (int j = 1; j <= int(n/2); j++){
         if (div[j]!=0)
            cout<<div[j]<<","<<setw(3);
      }
    
      cout<<endl<<"La suma de sus divisores es: "<<sum<<endl;
      cout<<"El número "<<n<<" es perfecto"<<endl<<endl; 
   }
   // Incluir estas lineas para determinar si el número ingresado es no perfecto
   //else
      //cout<<"El número "<<n<<" no es perfecto."<<endl<<endl; 
      
}
