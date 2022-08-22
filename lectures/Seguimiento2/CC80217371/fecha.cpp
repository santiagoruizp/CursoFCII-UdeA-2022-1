#include <iostream>
#include "fecha.h"

using namespace std;

Fecha::Fecha( int dd, int mm, int aa ) //Evalua si los valores ingresados son validos
{
  if ( mm > 0 && mm <= 12 ) // valida el mes
    mes = mm;
  else
    {
      mes = 1; // mes inválido se establece en 1
      cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }

  anio = aa; // se pudo validar aa?
  dia = comprobarDia( dd ); // valida el dia
}

void Fecha::imprimir() const //Muestra los valores
{
  cout <<"La fecha ingresada es: "<< dia << '/' << mes << '/' << anio;
}
// función utilitaria para confirmar el valor de dia apropiado con base
// en mes y anio; maneja años bisiestos también
int Fecha::comprobarDia( int diaPrueba ) const
{
  static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  // determina si diaPrueba es válido para el mes especificado
  if ( diaPrueba > 0 && diaPrueba <= diasPorMes[ mes ] )
    return diaPrueba;
  
  // comprueba 29 de febrero para año bisiesto
  if ( mes == 2 && diaPrueba == 29 && ( anio % 400 == 0 ||
					( anio % 4 == 0 && anio % 100 != 0 ) ) ){
    return diaPrueba;
  }
  
  cout << "Dia invalido (" << diaPrueba << ") se establecio en 1.\n";
  return 1; // deja el objeto en estado consistente si hay un valor incorrecto
}
    
void Fecha::diaSig(int d,int m,int a)// muestra la fecha del dia sig
{
  static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  static const int diasPorMesBis[ 13 ] =  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int dSig, mSig=m, aSig=a;
  bool bisiesto;
  bisiesto=aBisiesto(a);
    
  const int* ptDiasxMes=diasPorMes;
  if (bisiesto)//dependiendo del tipo de si es bisiesto o no, toma uno de los arreglos
    ptDiasxMes=diasPorMesBis;
    
  dSig=d+1;  
  if ((dSig)>*(ptDiasxMes+m))
    {
      dSig=1;
      mSig=m+1;
      if (mSig>12)
        {
          mSig=1;
          aSig=a+1;
        }
    }
  cout<<"\nLa fecha correspondiente al dia siguiente es: "<<dSig<<"/"<<mSig<<"/"<<aSig<<endl;
  
  return;
}

bool Fecha::aBisiesto(int a) // Evalua si es o no bisiesto
{
  bool bisiesto;
  if (a%4==0)//coteja si el año es bisiesto o no
    {
      bisiesto=true;
      if (a%100==0)
        {
          if (a % 400!=0)
          bisiesto=false;
        }      
    }
  else bisiesto=false;
  return bisiesto;
}