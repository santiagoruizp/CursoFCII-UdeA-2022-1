
#include <iostream>
#include "fecha.h"

using namespace std;

//------------------------------------------------------------------------------------------------------
// Se inicializa el arreglo de los días por mes
const int Fecha::diasPorMes[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//------------------------------------------------------------------------------------------------------
// Implementación del constructor
Fecha::Fecha( int mm, int dd, int aa )
{

  // Validación del mes
  if ( mm > 0 && mm <= 12 )
      mes = mm;
  else{
     mes = 1;
     cout << "\n   ⚠ Mes inválido ("<<mm<<") se establecio en 1.\n"; 
  }

  // Validación del año
  if (aa > 0 )
     anio = aa;
  else{
     anio = 1;
     cout << "\n   ⚠ Año inválido ("<<aa<<") se establecio en 1.\n"; 
  }
  
  // Validación del día
  dia = comprobarDia( dd ); 
  
  // Imprime objeto Fecha para mostrar cuándo se llama a su constructor
  cout << "Constructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl;
}

//------------------------------------------------------------------------------------------------------
// Implementación de la función imprimir. No puede cambiar atributos miembro de la clase
void Fecha::imprimir() const{

  cout << dia << '/' << mes << '/' << anio;
}

//------------------------------------------------------------------------------------------------------
// Imprime objeto Fecha para mostrar cuándo se llama a su destructor
Fecha::~Fecha(){

  /*cout << "Destructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl<<endl;*/

}

//------------------------------------------------------------------------------------------------------
// Función utilitaria para confirmar el valor de dia apropiado con base
// en mes y anio; maneja años bisiestos también
int Fecha::comprobarDia( int diaPrueba ) const{
  
  // Determina si diaPrueba es válido para el mes especificado
  if ( diaPrueba > 0 && diaPrueba <= *(diasPorMes + mes) )
    return diaPrueba;
  
  // Comprueba 29 de febrero para año bisiesto
  if ( mes == 2 && diaPrueba == 29 && ( anio % 400 == 0 ||
					( anio % 4 == 0 && anio % 100 != 0 ) ) ){
    return diaPrueba;
  }
  
  cout << "\n   ⚠ Dia invalido (" << diaPrueba << ") se establecio en 1.\n\n";
  return 1; // Deja el objeto en estado consistente si hay un valor incorrecto
}  
//------------------------------------------------------------------------------------------------------
// Implementación de la función de día siguiente. No puede cambiar atributos miembro de la clase  
void Fecha::diaSig(void) const{

   // Se crean varibles para almacenar el día, mes y año siguiente
   int diasiguiente, messiguiente = mes, aniosiguiente = anio;
   
   // Este primer if, else if es para los días particulares de febrero
   // Si se está en el día 28 de febrero de un año bisiesto, el día siguiente es el 29 de febrero
   if ( mes == 2 && dia == 28 && ( anio % 400 == 0 ||( anio % 4 == 0 && anio % 100 != 0 ) ) )
      diasiguiente = 29;
      
   // Si se está en el día 29 de febrero de un año bisiesto, el día siguiente es el 1 de marzo
   else if ( mes == 2 && dia == 29 && ( anio % 400 == 0 ||( anio % 4 == 0 && anio % 100 != 0 ) ) )
      diasiguiente = 1;
      
   else{
      // El día siguiente (dia +1) está dado por el módulo con el número de días del mes respectivo
      // Si resulta en el último día del mes sería diasiguiente = (dia+1)%(*(diasPorMes + mes)) = 0 por lo cual se define este primer if
      if ((dia+1)%(*(diasPorMes + mes))==0)
         diasiguiente = diasPorMes[mes];
      // Caso final diasiguiente = (dia+1)%(*(diasPorMes + mes))      
      else 
         diasiguiente = (dia+1)%(*(diasPorMes + mes));   
   }
   
   // Los días son crecientes a menos que se cambie de mes por lo cual se define este if para el mes siguiente
   if (diasiguiente < dia){
      // Si mes + 1 = 12, messiguiente = 0 por lo cual se define este primer if para evitar tal asignación
      if ((mes+1)%12 == 0)
         messiguiente = 12;
      // Caso final messiguiente = (mes+1)%12    
      else
         messiguiente = (mes+1)%12;
   }
   
   // Los meses son crecientes a menos que se cambie de año por lo cual se define este if para el año siguiente
   if (messiguiente < mes)
      aniosiguiente = anio + 1;
      
   // Se imprime el día siguiente
   cout <<"El día siguiente es: "<< diasiguiente << '/' << messiguiente << '/' << aniosiguiente <<endl;       
}
