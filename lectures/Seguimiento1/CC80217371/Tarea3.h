#include <iostream>
#include <string>
using namespace std;

class Exponencial 
{
public:
Exponencial(string);// Constructor
void mostrarMensaje(); // Mensaje de bienvenida
void recibirParametros(); // Solicita el ingreso de parametros
void mostrarResultados(); // entrega el valor
int factorial(int); // funcion que calcula n!
double expoFunction(double, int); // realiza la suma 'e' de la expasion en serie de Maclaurin 

private:
double val_x; // Valor de 'x' donde se desea evaluar la funcion
int N; // el numero de terminos de la serie (max N=13)
};