/*

Cree una clase llamada complejo para realizar aritmética con numeros complejos. 
Utilice variables double para representar datos de tipo private parteImaginaria y parteReal. 
Las funciones miembro de asignarDatos, obtenerParteReal y obtenerParteImaginaria 
deben estar presentes. Ademas, proporcione funciones miembro de tipo public para cada uno 
de los siguientes:

a) Suma de dos numeros complejos: las parte real se suman juntas y la parte imaginarias se suman juntas.
b) Resta de dos numeros complejos: la parte real del operando derecho se resta de la parte real 
del operando izquierdo, y la parte imaginaria del operando derecho se resta de la parte imaginaria 
del operando izquierdo.
c) Impresión de numerous complejos de la forma a + bi, en donde a es la parte real y b es la parte 
imaginaria.
d) ¿Podrian programarce otras operaciones entre complejos?

*/


#include <iostream>

#include "numComplejos.h"

using namespace std;

int main(){

    // Primer Objeto de Número complejo 
    NumerosComplejos numComplejo_1 = NumerosComplejos();

    numComplejo_1.asignarDatos();
    numComplejo_1.impresionResult();
    
    // Segundo Objeto de Número complejo 
    NumerosComplejos numComplejo_2 = NumerosComplejos();

    numComplejo_2.asignarDatos();
    numComplejo_2.impresionResult();

    cout << "---------------------------------" << endl;
    cout << "OPERACIONES CON NÚMEROS COMPLEJOS" << endl;
    cout << "---------------------------------" << endl;

    // Tercer Objeto de número complejo: Suma del primero y segundo.
    cout << "   Suma de complejos: "; 
    NumerosComplejos numComplejo_3;

    numComplejo_3 = numComplejo_3.sumaComplejos(numComplejo_1, numComplejo_2);
    numComplejo_3.impresionResult();

    // Tercer Objeto: Resta del primero y segundo.
    cout << "   Resta de complejos: "; 
    numComplejo_3 = numComplejo_3.restaComplejos(numComplejo_1, numComplejo_2);
    numComplejo_3.impresionResult();


    // Tercer Objeto: Multiplicación del primero y segundo.
    cout << "   Multiplicación de complejos: "; 
    numComplejo_3 = numComplejo_3.multiplicaComplejos(numComplejo_1, numComplejo_2);
    numComplejo_3.impresionResult();

    // Cuarto y quinto  Objeto: Conjugados del primero y segundo.
    NumerosComplejos numComplejo_4;
    NumerosComplejos numComplejo_5;

    cout << "   Conjugado del primero:  ";
    numComplejo_4 = numComplejo_4.conjugado(numComplejo_1);
    numComplejo_4.impresionResult();

    cout << "   Conjugado del segundo:  ";
    numComplejo_5 = numComplejo_5.conjugado(numComplejo_2);
    numComplejo_5.impresionResult();

    // Sexto Objeto: División del primero y segundo.
    cout << "   División de complejos: "; 
    numComplejo_3 = numComplejo_3.divideComplejos(numComplejo_1, numComplejo_2);
    numComplejo_3.impresionResult();

}






