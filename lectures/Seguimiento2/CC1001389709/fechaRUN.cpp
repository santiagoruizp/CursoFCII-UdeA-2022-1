
#include "fecha.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

   // Ejemplos del funcionamiento del código
   Fecha fecha1(2, 29, 2000);
   fecha1.diaSig();
   
   Fecha fecha2(12, 31, 2009);
   fecha2.diaSig();
   
   Fecha fecha3(4, 30, 2009);
   fecha3.diaSig();  
   
   Fecha fecha4(2, 27, 2001);
   fecha4.diaSig();
   
//-------------------------------------------------------------------------------------
// Descomentar estas líneas para introducir una fecha por consola

/*
   int d,m,a;

   cout<<"Programa para manejo de fechas. Ingrese una fecha."<<endl;
     
   cout<<"Ingrese el día: ";
   cin>>d;
   // Se garantiza que la entrada sea correcta usando métodos del objeto cin
   while (!cin){
      cout<<"No válido, debe ser un entero. Ingrese de nuevo: ";
      cin.clear();
      cin.ignore(10000,'\n');
      cin>>d;
   }
   
   
   cout<<"Ingrese el mes: ";
   cin>>m;
   // Se garantiza que la entrada sea correcta usando métodos del objeto cin
   while (!cin){
      cout<<"No válido, debe ser un entero. Ingrese de nuevo: ";
      cin.clear();
      cin.ignore(10000,'\n');
      cin>>m;
   }
   
   
   cout<<"Ingrese el año: ";
   cin>>a;
   // Se garantiza que la entrada sea correcta usando métodos del objeto cin
   while (!cin){
      cout<<"No válido, debe ser un entero. Ingrese de nuevo: ";
      cin.clear();
      cin.ignore(10000,'\n');
      cin>>a;
   }
   
  
   Fecha fecha(m, d, a);
   fecha.diaSig();
*/ 
//-------------------------------------------------------------------------------------

   return 0;
   
}
