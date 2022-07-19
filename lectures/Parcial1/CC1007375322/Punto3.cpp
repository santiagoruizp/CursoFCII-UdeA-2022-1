#include <iostream>

#include<cmath>
#include "Punto3.h"

using namespace std;

//Se definen Funciones a usar

Complejo::Complejo(double real, double imaginaria)
{
  asignarDatos(real,imaginaria);
}

void Complejo::asignarDatos(double real, double imaginaria)
{
  ParteImaginaria= imaginaria;
  ParteReal= real;
}

double Complejo::obtenerParteReal()
{
  return ParteReal;
}

double Complejo::obtenerParteImaginaria()
{
  return ParteImaginaria;
}
void Complejo::mostrarNumero()
{
  cout << ParteReal<< " + i "<< ParteImaginaria<<endl;
}

void Complejo::SumaComplejos(double bReal, double bImaginario)
{
  double sumReal=ParteReal+bReal;
  double sumImag=ParteImaginaria+bImaginario;
  Complejo c(sumReal,sumImag);
  cout << "La suma es:  "<< endl;
  c.mostrarNumero();
}
void Complejo::RestaComplejos(double bReal, double bImaginario)
{
  double resReal=ParteReal-bReal;
  double resImag=ParteImaginaria-bImaginario;
  Complejo c(resReal,resImag);
  cout << "La resta es:  "<< endl;
  c.mostrarNumero();
}

void Complejo::Producto(double bR, double bIm)
{
  double ProdReal=ParteReal*bR-ParteImaginaria*bIm;
  double ProdImag=ParteReal*bIm+ParteImaginaria*bR;
  Complejo c(ProdReal,ProdImag);
  cout << "El Producto es:  "<< endl;
  c.mostrarNumero();
}

void Complejo::Division(double bR, double bIm)
{
  double norm=pow(bR,2)+pow(bIm,2);
  double divReal=(ParteReal*bR+ParteImaginaria*bIm)/norm;
  double divImag=(ParteImaginaria*bR-ParteReal*bIm)/norm;
  Complejo c(divReal,divImag);
  cout << "La división es:  "<< endl;
  c.mostrarNumero();
}

void Complejo::norma()
{
  double norm=sqrt(pow(ParteReal,2)+pow(ParteImaginaria,2));
  cout<< "La norma es: "<<norm<< endl;
}

void Complejo::Conjugado()
{
  Complejo c(ParteReal,-1*ParteImaginaria);
  cout << "El conjugado  es:  "<< endl;
  c.mostrarNumero();
}
