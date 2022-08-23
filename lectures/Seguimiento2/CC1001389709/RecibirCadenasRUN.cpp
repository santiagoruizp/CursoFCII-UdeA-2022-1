

#include <iostream>
# include "RecibirCadenas.h"

using namespace std;

int main(){
   
   string str1, str2;
   
   cout<<"Ingrese una cadena de texto: "; 
   getline(cin, str1);
   
   cout<<"Ingrese otra cadena de texto: "; 
   getline(cin, str2);
   
   RecibirCadenas(str1, str2);

   return 0;
}
