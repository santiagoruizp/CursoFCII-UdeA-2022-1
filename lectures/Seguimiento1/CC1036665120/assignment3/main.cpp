
#include "exponential.h"


/// este es el codigo que se va a ejecutar, el constructor 
int main()
{
ExponentialSeries e = ExponentialSeries();

// retorna el exponente y la presición de la serie 
auto [x, n] = e.getNumberFromUser();

// calcula la función exponencial
double exp = e.calculateSeries(x, n);  

// muestra el resultado
e.mostrarResultado(exp);
return 0; 
}