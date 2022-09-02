#ifndef TURISMO_H
#define TURISMO_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
class Turismo
{
public:
Turismo( string ); //constructor

void leeProcesa( string ) ;
void nuevaListaSinDuplicados() ;
void seleccionar(const int) const ;
void estadistico() const ;
void contar(const int,const int, const int) const ;//dia,mes,año
void eliminarHotel(const int) const ;

void imprimir(const int [],const int [],const int [] ,const int [],const int [], int) const;

string getName() const;

private:
// se trabaja en arreglos tipo int
int fecha[20];
int dia[20];
int mes[20];
int año[20];
int hotel[20];
int cama[20];

string nameArchivo = "";
 
};

#endif
