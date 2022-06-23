/*
Usando las tecnicas de programcion orienta a objetos (POO) que hemos estudiado, cree una clase que nos devuleva el valor de e^x:
e^x = 1 + (x/1!) + (x^2/2!) +  (x^3/3!) +  .......
Su clase debe tener almenos las siguientes caracteristicas:
dos variables privadas: el valor de "x" y "N"la presicion (el numero de terminos de la serie).
Debe tener un constructor.
Ademas debe tener dos funciones mas:
a) una que lea un entero no negativo, que calcule su factorial.
b) una que calcule el valor de e^x.
Finalmente debe tener una funcion que muestre el valor de e^xe	|
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std; 
////////////////////////////////////////////////////////////////////////////////
class Exponencial{
 private: //características
  int N; 
  float x; 
public: // acciones
  Exponencial(int, float);//los constructores ayudan a inicializar las características
  float fact(int);
  float serie(int,float);
  void mostrar(float);
};
