#include <iostream>

using std::cout;
using std::endl;

bool numperfecto (int); //generamos la función booleana que recibe número entero 

int main()
{
    cout << "Para los enteros desde 1 a 1000:\n"; // mostramos este mensaje en pantalla

    for ( int j =2; j <= 1000; ++j )  // recorremos los números desde 2 hasta 1000
       if ( numperfecto (j) )        // si cumple con la condión de ser perfecto se muestra el número en pantalla
       cout << j << " es un numero perfecto\n";

    cout << endl;

    return 0;
}

bool numperfecto (int value)
{
    int factorSum = 1;

    for ( int i = 2; i <= value / 2; ++i) 
      if (value % i== 0) // comprobamos si un número es divisor
          factorSum += i; // si lo es, y la suma de estos divisores es el número

    return factorSum == value ? true : false; // si cumple las dos anteriores condiciones se toma como número perfecto


}