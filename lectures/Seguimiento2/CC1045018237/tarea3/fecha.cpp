#include <iostream>
#include "fecha.h"

using namespace std;
using std::cout;

Fecha::Fecha( int m, int d, int a )
{
  establecerFecha( m, d, a); // establecemos la fecha en el constructor
  
} // fin constructor

Fecha &Fecha::establecerFecha( int mm, int dd, int aa )
{
  establecerMes(mm); // llamamos a la funcion establecer mes
  establecerDia(dd); // llamamos a la funcion establecer dia
  establecerAnio(aa); // llamamos a la funcion establecer año

  return *this; //permite las llamadas en cascada
  
} // final de la funcion establecer Fecha

Fecha &Fecha::establecerDia( int d )
{
  if ( mes == 2 && AnioBisiesto())
  {
    dia = (d <= 29 && d >= 1 ) ? d : 1;
  }
  else
  {
    dia = (d <= diasMes() && d >= 1 ) ? d : 1;
  } 
  return *this;
  }// fin establecer dia
  
    
Fecha &Fecha::establecerMes( int m)
{
  mes = m <= 12 && m >= 1 ? m : 1; //establecemos mes
  return *this;
} // fin establecer mes


Fecha &Fecha::establecerAnio(int a)
{
  anio = a >= 1900 ? a : 1900; // establecemos año

  return *this;
} // fin establecer año


unsigned int Fecha::obtenerDia() const
{
  return dia;
} // fin de la funcion getdia

unsigned int Fecha::obtenerMes() const
{
  return mes;
} // fin funcion getmes

unsigned int Fecha::obtenerAnio() const
{
  return anio;
} // fin de la funcion getanio

void Fecha::imprimir()
{
  cout << dia << '-' << mes << '-' << anio << '\n';  // mostrar los datos
}

void Fecha::diaSig()
{
  establecerDia( dia + 1 ); // incremeneta el dia en 1
  if ( dia == 1)
  {
    establecerMes( mes + 1 ); // incrementa el mes en uno

    if (mes == 1)
    {
      establecerAnio( anio + 1); // incrementa el año en 1
    }
    
  }
  
} // fin  de la funcion diaSig que es el dia siguiente

bool Fecha::AnioBisiesto()
{
  if (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0))
       
  {
    return true; // es un año bisiesto
  }
  else
  {
    return false; // no es una año bisisesto
  }
} // fin de la funcion año bisisesto

unsigned int Fecha::diasMes() 
{
  const int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  return mes = 2 && AnioBisiesto() ? 29 : dias[ mes - 1];
} // fin de la funcion diaMes




