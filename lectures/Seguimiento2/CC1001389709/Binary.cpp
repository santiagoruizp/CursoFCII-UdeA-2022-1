
#include "Binary.h"

// Implementacón de la función
int BinarySearch(int *arr, const int len, int s){

   // Índice para recorrer el arreglo
   int index;
   // Entero recursivo para acotar los elementos de búsqueda en el arreglo
   int lenrec = len;

   // Se aborda el caso en que el entero ingresado supere los valores menor y mayor del arreglo
   if (arr[0] > s || arr[len-1] < s)
      cout<<"Valor no encontrado en el arreglo"<<endl;
   
   else{
       
       // Se inicia la búsqueda en la mitad del arreglo
       index = static_cast <int> (len/2); 
      
      // Ciclo a recorrer hasta hallar el valor buscado
      while (arr[index] != s){
         
         // En caso de que el valor buscado esté "a la izquierda" de la posición actual en el arreglo
         if (arr[index] > s){
            lenrec = index;
            index = static_cast <int> (index/2);
         }
         
         // En caso de que el valor buscado esté "a la derecha" de la posición actual en el arreglo
         else
            index += static_cast <int> (abs(lenrec-index)/2);         
      }
      
      // Se imprime la posición del valor buscado en el arreglo 
      cout<<"El valor ingresado se encuentra en la posición "<<index+1<<", es decir array["<<index<<"] = "<<s<<"."<<endl;
   }
    
   // Se retorna la posición del valor buscado en el arreglo 
   return index;     
}
