// Head

/*
Tarea3.
Santiago Ruiz Piedrahita

Se crea una clase que nos devuleve el valor de e^x:
*/

#include <string> 
using std::string;

class Exponencial
{
public:

Exponencial(string);
string NombreFun(string);
void MostrarMensaje(); 
unsigned long Fact(int num); 
double FunExp();
void FunExponencial();
void Factorial();


private:

float x;
unsigned int N;

};
