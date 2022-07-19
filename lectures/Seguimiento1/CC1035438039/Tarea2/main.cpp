/*
Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. Una
vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. Si la
suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se
convierte en el “punto” del jugador. Para ganar, el jugador debe seguir tirando los dados hasta que salga otra
vez “su punto”. El jugador pierde si tira un 7 antes de llegar a su punto.
*/

#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time
#include <iomanip>


/*using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;*/

using namespace std;

double craps(double apuesta);
double apostar();
int tirarDados(); // tira los dados, calcula y muestra la suma

int main()
{
    double ganancias = 0.0;
    double saldoBanco = 1000000.0;
    double apuesta = apostar();

    while (apuesta>saldoBanco){
        cout << "No tiene tanto saldo en el banco" << endl;
        cout << fixed << setprecision(2) << "Usated dispone de: " << saldoBanco << endl;
        apuesta = apostar();
    }

    ganancias = craps(apuesta);
    saldoBanco += ganancias;

    if (saldoBanco == 0){
        cout << "Lo siento. Se quedo sin fondos!" << endl;
    }else{
        cout << fixed << setprecision(2) << "Su nuevo saldo es: " << saldoBanco << endl;
    }

    return 0; // indica que terminó correctamente
} // fin de main


// tira los dados, calcula la suma y muestra los resultados
int tirarDados()
{
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6; // tiro del primer dado
  int dado2 = 1 + rand() % 6; // tiro del segundo dado

  int suma = dado1 + dado2; // calcula la suma de valores de los dados

  // muestra los resultados de este tiro
  cout << "El jugador tiro " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; // devuelve la suma de los dados
} // fin de la función tirarDados

double apostar(){
    double apuesta;
    cout << "Ingrese la cantidad que desea apostar: " << endl;
    cin >> apuesta;

    return apuesta;
}

string mostrarMensajes(){
    string mensaje = "";
    int random = rand() % 10;
    if (random<3){
        mensaje = "usted se esta quebrando, no le parece?";
    }else if(random<5){
        mensaje = "hagale, no pasa nada, arriesguese!";
    }else if(random <7){
        mensaje = "La sacaste del estadio!";
    }else{
        mensaje="";
    }
    return mensaje;
}

double craps(double apuesta){
    // enumeración con constantes que representa el estado del juego
    enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
    //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"

    unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
    Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO

    // randomiza el generador de números aleatorios, usando la hora actual
    srand( time( 0 ) );

    string mensaje = "";
    int sumaDeDados = tirarDados(); // primer tiro del dado
    // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
    switch ( sumaDeDados )
    {
        case 7: // gana con 7 en el primer tiro
        case 11: // gana con 11 en el primer tiro
            estadoJuego = GANO;
            break;
        case 2: // pierde con 2 en el primer tiro
        case 3: // pierde con 3 en el primer tiro
        case 12: // pierde con 12 en el primer tiro
            estadoJuego = PERDIO;
            break;
        default: // no ganó ni perdió, por lo que recuerda el punto
            estadoJuego = CONTINUAR; // el juego no ha terminado
            miPunto = sumaDeDados; // recuerda el punto
            cout << "El punto es " << miPunto << endl;
            break; // opcional al final del switch
    } // fin de switch


    // mientras el juego no esté completo
    while ( estadoJuego == CONTINUAR ) // no ganó ni perdió
    {
        sumaDeDados = tirarDados(); // tira los dados de nuevo
        mensaje = mostrarMensajes();
        // determina el estado del juego
        if ( sumaDeDados == miPunto ) // gana al hacer un punto
        {estadoJuego = GANO;}
        else if ( sumaDeDados == 7 ) // pierde al tirar 7 antes del punto
        {estadoJuego = PERDIO;}
        string contunuaApostando;
        cout << "Desea subir su apuesta? (ingrese SI o NO)" << endl;
        cin >> contunuaApostando;
        contunuaApostando=="SI"? apuesta += apostar(): apuesta = apuesta;
        cout << fixed << setprecision(2) << "Su apuesta es de " << apuesta << endl;
        cout << mensaje << endl;
    } // fin de while

    // muestra mensaje de que ganó o perdió
    if ( estadoJuego == GANO ){
        cout << "El jugador gana" << endl;
        apuesta *= 2;
        cout << fixed << setprecision(2) << "Usted gano " << apuesta << endl;
    }
    else {
        cout << "El jugador pierde" << endl;
        apuesta *= -1;
    }
    return apuesta;
}