#ifndef PARABOLICAS_H
#define PARABOLICAS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;
class Parabolicas
{
public:
Parabolicas( string ); //constructor

double funcion(const double);

void regresivas(const double, const double, const double, const double, const double);

void crankNicolson(const double, const double, const double, const double, const double);
 
};

#endif


