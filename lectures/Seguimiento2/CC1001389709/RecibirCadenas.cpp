
#include "RecibirCadenas.h"

void RecibirCadenas(string str1, string str2){

   // Se muestran las cadenas ingresadas
   cout<<"\nLas cadenas ingresadas fueron: \""<<str1<<"\" y \""<<str2<<"\""<<endl<<endl;
   
   // Comparación de str1 y str2
   cout<<"Comparación de las cadenas: "; 
   
   if ( str1 == str2 )
      cout <<str1<<" = "<<str2<<endl;
   else{
      if ( str1 > str2 )
         cout<<str1<<" > "<<str2<<endl;
      else 
         cout<<str1<<" < "<<str2<<endl;
   }
    
   // Vocales y consonantes
   string voc = "aeiou";
   //string VOC = "AEIOU"; 
   string cons = "bcdfghjklmnpqrstvwxyzñ"; 
   //string CONS = "BCDFGHJKLMNPQRSTVWXYZÑ";
    
   // Nueva string con vocales mayúsuclas
   string str1VOC = str1; 
   
   // Conversión de la cadena 1. Vocales mayúsculas
   for (int i = 0; i <= str1VOC.length()-1; i++){
   
      for (int j = 0; j <= voc.length()-1; j++){
      
         if ( str1VOC.at(i) == voc.at(j))
            str1VOC.at(i) = static_cast <char> (toupper(str1VOC.at(i)));
      }
   }
   cout<<endl<<"La primera cadena transformada es: "<<str1VOC<<endl;
   
   // Nueva string con consonantes mayúsuclas
   string str2CONS = str2; 
   
   // Conversión de la cadena 2. Consonantes mayúsculas
   for (int i = 0; i <= str2CONS.length()-1; i++){
   
      for (int j = 0; j <= cons.length()-1; j++){
      
         if ( str2CONS.at(i) == cons.at(j))
            str2CONS.at(i) = static_cast <char> (toupper(str2CONS.at(i)));
      }
   }
   cout<<endl<<"La segunda cadena transformada es: "<<str2CONS<<endl;
  

   // Cadena concatenada
   string concat = str1VOC + " " + str2CONS;
   cout<<endl<<"La cadena concatenda es: "<<concat<<endl;
   
   // Cadena concatenada invertida
   string INVconcat = concat;
   for (int i = 0; i <= concat.length()-1; i++)
      INVconcat.at(i) = concat.at(concat.length() - 1 - i);

   cout<<endl<<"La cadena concatenda invertida es: "<<INVconcat<<endl;
   
   
}


