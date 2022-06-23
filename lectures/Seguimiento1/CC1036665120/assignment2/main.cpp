#include <unistd.h>

#include "craps.h"

using namespace std;

/// este es el codigo que se va a ejecutar, el constructor 
int main()
{
JuegoCraps craps = JuegoCraps();

// Ingresa el dinero a apostar
float apuesta = craps.dineroApostar();   
float dineroJugador = 100000; 
srand( ( unsigned int )time( nullptr ) );

do
{   
    // Realiza cada partida
    float estado = craps.estadoJuego();

    // Calcula el dinero
    dineroJugador = dineroJugador + craps.calcularDinero(estado, apuesta);
    sleep(1); //Espera un segundo

    // Muestra cuanto dinero se tiene 
    craps.mostrarMensajeDinero(dineroJugador);

    // Conversación
    craps.mostrarMensaje(estado);

} while (dineroJugador>0);

return 0; 
}

