
#include<iostream>
#include "Binary.h"

using namespace std;

int main(){

   // Entero a ser buscado  
   int a;
   
   // Arreglo de prueba array1
   const int len = 14;
   int array[len] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    
   // Se recibe el entero a ser buscado
   cout<<"Ingrese el valor a buscar en una lista de enteros: ";
   cin>>a;

   // Se garantiza que la entrada sea correcta usando métodos del objeto cin
   while (!cin){
      cout<<"No válido, debe ser un entero. Ingrese de nuevo: ";
      cin.clear();
      cin.ignore(10000,'\n');
      cin>>a;
   }
   
   // Se busca tal entero con la función BinarySearch en el arreglo array
 
   int index = BinarySearch(array, len, a);
}
