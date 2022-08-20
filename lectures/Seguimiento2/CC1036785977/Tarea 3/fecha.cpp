#include <iostream>
#include "fecha.h"

using namespace std;

Fecha::Fecha( int dd, int mm, int aa )
{
setAnio(aa)  ;
setMes(mm);
setDia(dd);
}

void Fecha::imprimir() const
{
  cout << dia << '/' << mes << '/' << anio;
}

void Fecha::setAnio(int an)
{
if ( an > 0 && an <= 3000 ) // valida el año
    anio = an;
  else
    {
      anio = 2022; // año se establece en el actual
      cout << "año invalido (" << an << ") se establecio en 2022.\n";
    }
}

void Fecha::setMes(int mm)
{
if ( mm > 0 && mm <= 12 ) // valida el mes
    mes = mm;
  else
    {
      mes = 1; // mes inválido se establece en 1
      cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }
}

void Fecha::setDia(int diaprueba)
{
  static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  // determina si diaPrueba es válido para el mes especificado
  if ( diaprueba > 0 && diaprueba <= diasPorMes[ mes ] )
    dia = diaprueba;
  
  // comprueba 29 de febrero para año bisiesto
  else if ( mes == 2 && diaprueba == 29 && ( anio % 400 == 0 ||
					( anio % 4 == 0 && anio % 100 != 0 ) ) )
  { 	
    dia = diaprueba;
  }
  else
  {
  cout << "Dia invalido (" << diaprueba << ") se establecio en 1.\n";
  dia = 1; // deja el objeto en estado consistente si hay un valor incorrecto
  }  
}
  
void Fecha::diaSig() 
{
  int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  if ( mes == 2 && ( anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 ) ) )
  { 	
    diasPorMes[2] = 29;
  }
  
  // verifiquemos prero que el caso de el dia no sea el ultimo del mes
  if ( dia < diasPorMes[ mes ] )
  {
  dia += 1;
  cout<<"\nDia Siguiente: \n";
  imprimir();
  }
  
  //verifiquemos que sea el ultimo dia del mes
  //sin diciembre
  else if ( dia == diasPorMes[ mes ] && mes != 12)
  {
  dia = 1;
  mes += 1;
  cout<<"\nDia Siguiente: \n";
  imprimir();
  }
  
  //con diciembre
  else if ( dia == diasPorMes[ mes ] && mes == 12)
  {
  dia = 1;
  mes = 1;
  anio += 1;
  cout<<"\nDia Siguiente: \n";
  imprimir();
  }  

}  
