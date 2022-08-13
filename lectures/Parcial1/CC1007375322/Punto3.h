#include <string> 
using std::string;
//Se define el constructor de números complejos y las funciones miembro
class Complejo
{
public:
Complejo( double, double);
//funciones miembro básicas pedidas
void asignarDatos(double, double);
double  obtenerParteReal();
double  obtenerParteImaginaria();
// c) función miembro suma de dos números complejos
void  SumaComplejos(double, double);
// b) Resta de dos números complejos
void RestaComplejos(double, double);
// c) Imprimir un número complejo
void mostrarNumero();
//d) Claro que se pueden programar otras funciones, creemos las funciones norma, producto, división y conjugado.
 void Producto(double, double);
 void norma();
 void Division(double, double);
 void Conjugado();
 
private:
 double ParteReal;
 double ParteImaginaria;

}; 
