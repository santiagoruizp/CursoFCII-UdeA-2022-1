#ifndef TURISMO_H
#define TURISMO_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
class Turismo
{
public:
Turismo(string ); //constructor

 
void imprimir(const vector<string>&); // funcion  para imprimir vector
void leeProcesa(ifstream&, string); // funcion para leer el archivo
void nuevaListaSinDuplicados(const vector<string>&); // lista utilizada
void seleccionar(const vector<string>&); // 
void estadistico(const vector<string>&); // 
void contar(const vector<string>&); // 
//void eliminarHotel( vector<string>&); // 


string getName() const;
vector<string> getleeProcesa() const ;
vector<string> getnuevalista() const ;


vector<string> lista;

private:


string nameArchivo = "";
ifstream infile; 
vector<string> muestraListado, sinDuplicados; 
vector<string> new_vect,list;


 
};

#endif