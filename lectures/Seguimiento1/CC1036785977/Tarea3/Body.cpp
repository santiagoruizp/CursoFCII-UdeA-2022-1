// Body

#include <iostream>
#include <cmath>
#include "Head.h"

using namespace std;

Exponencial::Exponencial(string nombre)
{
  NombreFun(nombre);
}

string Exponencial::NombreFun(string nombre)
{
 return nombre;
}


// Mensaje al usuario
void Exponencial::MostrarMensaje()
{
    cout << "El programa calcula el exponencial o el factorial de un numero\n";   
}

// Funcion que calcula el factorial de un entero no negativo
unsigned long Exponencial::Fact(int num) 
{
    int mm = 1;
  double factorial = 1;

  if (num == 0){ factorial=1; }
  else
  {
    while(mm<=num){
      factorial*=mm;
      mm++;
    }
  }

  return factorial;

}

// Calcula el exponencial de un numero por series de Fourier
double Exponencial::FunExp()
{

    int jj  = 0;
    double myexp = 0;
    

    
    while (jj<=N)
    {
       myexp = myexp + pow(x,jj)/Fact(jj);
       jj++;
         
    }

    return myexp;
}

// mensaje de la respuesta de la exponencial
void Exponencial::FunExponencial()
{
    cout << "Introduzca el valor de X y de N respectivamente para hallar su exponencial:\n";
    cin >> x >> N;

    cout<<"El resultado de Exp("<< x <<") es igual a: "<< FunExp() << endl;
}


// mensaje de respuesta al usuario del factorial
void Exponencial::Factorial()
{
    cout <<"\nIntroduzca el valor de X para hallar su factorial:\n";
    int y;
    cin >> y;
    cout<<"El resultado de "<<y<<"! es igual a: "<< Fact(y) << endl;
}

