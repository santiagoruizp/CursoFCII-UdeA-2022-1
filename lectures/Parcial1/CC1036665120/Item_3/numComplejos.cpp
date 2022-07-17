#include <iostream>
#include<cmath>

#include "numComplejos.h"

using namespace std;


NumerosComplejos::NumerosComplejos(){

} 

// -----------------------------------------
// Usuario asigna datos
// -----------------------------------------

double NumerosComplejos::verificarDatos(){

    double num=0;
    cin >> num;

    while (cin.fail())
    {
        if (cin.fail())
        {
            cout << "Debes ingresar un número." << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        cin >> num;
    }

    return num;
}

// -----------------------------------------
void NumerosComplejos::asignarDatos(){

    
    cout << "Ingrese la parte Real del número complejo:  "; 
    
    parteReal = verificarDatos();

    cout << "Ingrese la parte Imaginaria del número complejo:  "; 
    parteImaginaria = verificarDatos();

}


// -----------------------------------------
// Get and set 
// -----------------------------------------

void NumerosComplejos::asignarParteReal(double num){
    parteReal = num;
}


void NumerosComplejos::asignarParteImaginaria(double num){
    parteImaginaria = num;
}


double NumerosComplejos::obtenerParteReal(){
    return parteReal;
}

double NumerosComplejos::obtenerParteImaginaria(){
    return parteImaginaria;
}

// -----------------------------------------
// Operaciones entre Complejos
// -----------------------------------------

NumerosComplejos NumerosComplejos::sumaComplejos(NumerosComplejos num_1, NumerosComplejos num_2){

    double num_1_real = num_1.obtenerParteReal();
    double num_2_real = num_2.obtenerParteReal();

    double num_1_imaginaria = num_1.obtenerParteImaginaria();
    double num_2_imaginaria = num_2.obtenerParteImaginaria();

    NumerosComplejos num_3;

    num_3.asignarParteReal(num_1_real + num_2_real);
    num_3.asignarParteImaginaria(num_1_imaginaria + num_2_imaginaria);

    return num_3;
}

// -----------------------------------------

NumerosComplejos NumerosComplejos::restaComplejos(NumerosComplejos num_1, NumerosComplejos num_2){
    
    double num_1_real = num_1.obtenerParteReal();
    double num_2_real = num_2.obtenerParteReal();

    double num_1_imaginaria = num_1.obtenerParteImaginaria();
    double num_2_imaginaria = num_2.obtenerParteImaginaria();

    NumerosComplejos num_3;

    num_3.parteReal = num_1_real - num_2_real;
    num_3.parteImaginaria = num_1_imaginaria - num_2_imaginaria;

    return num_3;
}

// -----------------------------------------

NumerosComplejos NumerosComplejos::multiplicaComplejos(NumerosComplejos num_1, NumerosComplejos num_2){

    //  Sea la operación:  (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
    
    double num_1_real = num_1.obtenerParteReal();
    double num_2_real = num_2.obtenerParteReal();

    double num_1_imaginaria = num_1.obtenerParteImaginaria();
    double num_2_imaginaria = num_2.obtenerParteImaginaria();

    NumerosComplejos num_3;

    num_3.parteReal = (num_1_real * num_2_real) - (num_1_imaginaria * num_2_imaginaria);
    num_3.parteImaginaria = (num_1_real * num_2_imaginaria) + (num_1_imaginaria * num_2_real);

    return num_3;
}

// -----------------------------------------

NumerosComplejos NumerosComplejos::conjugado(NumerosComplejos num){

    double num_real = num.obtenerParteReal();
    double num_imaginaria = num.obtenerParteImaginaria();

    NumerosComplejos num_conjug;

    num_conjug.parteReal = num_real;
    num_conjug.parteImaginaria = -1 * num_imaginaria;

    return num_conjug;
}

// -----------------------------------------

NumerosComplejos NumerosComplejos::divideComplejos(NumerosComplejos num_1, NumerosComplejos num_2){

    // Sea la operación:  (a + bi) / (c + di) = ( (a + bi) * (c - di) ) / (c^2 + d^2)
    
    double num_1_real = num_1.obtenerParteReal();
    double num_2_real = num_2.obtenerParteReal();

    double num_1_imaginaria = num_1.obtenerParteImaginaria();
    double num_2_imaginaria = num_2.obtenerParteImaginaria();

    // Numero conjugado del divisor 
    NumerosComplejos num_2_conjug;
    num_2_conjug = num_2_conjug.conjugado(num_2);

    // Resultado de la división
    NumerosComplejos num_3;

    // Numerador y denominador 
    NumerosComplejos numerador = num_3.multiplicaComplejos(num_1, num_2_conjug);
    double denominador = pow(num_2_real, 2) + pow(num_2_imaginaria, 2);

    // División por parte real e imaginaria 
    num_3.parteReal = numerador.obtenerParteReal() / denominador;
    num_3.parteImaginaria = numerador.obtenerParteImaginaria() / denominador;

    return num_3;
}


// -----------------------------------------
// Impresión de números complejos
// -----------------------------------------
void NumerosComplejos::impresionResult(){
    
    cout << "Número complejo: ";
    cout << parteReal << " + i (" << parteImaginaria << ")" << endl;

}