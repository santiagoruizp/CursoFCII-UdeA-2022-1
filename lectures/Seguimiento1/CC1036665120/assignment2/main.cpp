
#include <iostream>
#include <unistd.h>
#include <ctime>

#include "craps.h"

using namespace std;

/// este es el codigo que se va a ejecutar, el constructor 
int main()
{
JuegoCraps craps = JuegoCraps();
float apuesta = craps.dineroApostar();   
float dineroJugador = 100000; 
srand( ( unsigned int )time( nullptr ) );

do
{   
    float estado = craps.estadoJuego();
    dineroJugador = dineroJugador + craps.calcularDinero(estado, apuesta);
    sleep(1);//sleeps for 1 second
    cout << "Ya tienes unos : " << dineroJugador << " pesos." <<endl;
    craps.mostrarMensaje(estado);

} while (dineroJugador>0);

cout << "Lo siento. Se quedo sin fondos!" <<endl;

return 0; 
}

