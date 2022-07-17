/*
Tarea #1
Santiago Ruiz Piedrahita

Ejercicio 8 de la seccion 3.5 del texto guia
Heat Transfer

q = hA(T_s-T_a)


 */


#include <iostream>
using namespace std;

int main()
{
  const int AIRCONV = 8.7; // w/m^2ºC
  const int Pi = 3.141592;

    cout <<"El programa calcula la tasa de transferencia de calor de un area\nEntrar las unidades pedidas en el SI, metros para longitudes y grados centigrados para temperaturas\n"<<endl;
    
  float A; // area de la superficie
  float Ts; // Temperatura de la superficie
  float Ta; // Temperatura del ambiente
  float q; // Tasa transferencia de calor

  float l1; // Longitud
  float a1; // ancho

  float eM; // eje mayor
  float em; // eje menor

  int e; // eleccion

  int num = 1; // Numero para controlar while
  
  while(num==1)
  {

   cout <<"Elija el numero de una de las siguentes areas: \n1) Area rectangular \n2) Area eliptica \n3) Otra\n"<<endl;
  cin >> e;
  
  if (e == 1)
    {
      cout <<"Ingrese la longitud y el ancho del rectangulo en metros:"<<endl;
      cin >> l1 >> a1;
      A = l1*a1;
      num = 0;
    } 
    
  if (e == 2)
    {
      cout <<"Ingrese el eje mayor y el eje menor de la elipse en metros:"<<endl;
      cin >> eM >> em;
      A = eM*em*Pi;
      num = 0;
    }
  
  if (e == 3)
    {
      cout <<"Ingrese el area de la superficie:"<<endl;
      cin >> A;
      num = 0;
    }

  if (num==1)
    {
    cout<< "Esa no es una opcion valida en metro cuadrado\n"<<endl;
    }
  }

  cout<< "\nIngrese la temperatura de la superficie en centigrados:"<<endl;
  cin >> Ts;
  cout<< "\nIngrese la temperatura del ambiente en centigrados:"<<endl;
  cin >> Ta;

  q = AIRCONV*A*(Ts-Ta);

  cout<< "\nLa tasa de transferencia de calor es de: "<<q<< " W " <<endl;
  
  return 0; 
}
