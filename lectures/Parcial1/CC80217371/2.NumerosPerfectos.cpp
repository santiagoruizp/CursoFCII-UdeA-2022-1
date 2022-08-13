#include <iostream>
#include <vector>
using namespace std;

int suma(vector<int> const &input) // hace la suma de los elementos dentro del array 
{
  int sumatoria=0;
    for (int i = 0; i < input.size(); i++) {
        sumatoria += input.at(i);
    }
  return sumatoria;
}

vector<int> factores(int N) // genera los dividores del numero
{
  int i = 1, B = N, modul;  
  vector<int> multiplos;

  while (B >= 2) {// evalua si son o no multiplos  	
    modul=N%i;
    if (modul==0){
    multiplos.push_back(i);
    }
    i++; 
    B=N/i;     
  }
  return multiplos;
}

int main() 
{  
  vector<int> multiplos;  
  int N=1000;
  
  for (int i=2; i < N ; i++ )
  {
    multiplos=factores(i);
    int sum=suma(multiplos);

    if (sum==i)
      {
        cout << "Los divisores propios de " << i <<" son: ";
        for (int i = 0; i < multiplos.size(); i++) 
          {//imprime los elementos del arreglo
            cout << multiplos.at(i) << " ";
          }
        cout << "y su suma es: "<<sum<<", por lo tanto es un numero perfecto "<< endl;   
      }
  }    
  return 0;
}

