#include <iostream>
#include "tarea3.h"
#include <vector>
using namespace std;

Fecha::Fecha( int dd, int mm, int aa)
{
  if ( mm > 0 && mm <= 12 ) // valida el mes
    month = mm;
  else
    {
      month = 1; // mes inválido se establece en 1
      cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }
  
  year = aa; // se pudo validar aa?
  day= comprobarDia( dd ); // valida el dia
  
  // imprime objeto Fecha para mostrar cuándo se llama a su constructor
  cout << "Constructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl;
}

void Fecha::imprimir() const
{
  cout << day << '/' << month << '/' << year;
}
// imprime objeto Fecha para mostrar cuándo se llama a su destructor
Fecha::~Fecha()
{
  cout << "Destructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl;
}
// imprime objeto Fecha para mostrar cuándo se llama a su destructor


// función utilitaria para confirmar el valor de dia apropiado con base
// en mes y anio; maneja años bisiestos también
int Fecha::comprobarDia( int diaPrueba ) const
{
  static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  // determina si diaPrueba es válido para el mes especificado
  if ( diaPrueba > 0 && diaPrueba <= diasPorMes[ month ] )
    return diaPrueba;
  
  // comprueba 29 de febrero para año bisiesto
  if ( month == 2 && diaPrueba == 29 && ( year % 400 == 0 ||
					( year % 4 == 0 && year % 100 != 0 ) ) ){
    return diaPrueba;
  }
  
  cout << "Dia invalido (" << diaPrueba << ") se establecio en 1.\n";
  return 1; // deja el objeto en estado consistente si hay un valor incorrecto
}

void Fecha::diasig(int &day, int &month, int &year, int &add_days)
   {  
      int i;
      int end, start;
      int count = 0;
      string leap;
      vector<int> Total_days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      
      for (i = 0; i < month; i++)
      {
         count = count + Total_days[i];
      }

      count = count + day + add_days;
      cout << "Updated date=";
      if (count <= 365)
      {
         for (i = 0; i < Total_days.size(); i++)
         {
            start = count - Total_days[i];
            if (start <= Total_days[i + 1])
            {
               end = i + 1;
               break;
            }
            else
               count = start;
         }
         cout << "[" << start << "|" << end << "|" << year << "]" << leap << endl;
      }
      else
      {
         count = count - 365;
         for (i = 0; i < 13; i++)
         {
            start = count - Total_days[i];
            if (start <= Total_days[i + 1])
            {
               end = i + 1;
               break;
            }
            else
               count = start;
         }
         cout << "[" << start << "|" << end << "|" << year + 1 << "]" << leap << endl;
      }
      leap = "";
   }
void Fecha::input()
{
      if (day <= 31 && month <= 12)
      {  
         cin >> day>>month>>year;
         int add_days;
         cout << "Dias a agregar=";
         cin >> add_days;
         diasig(day, month, year, add_days);
      }
}