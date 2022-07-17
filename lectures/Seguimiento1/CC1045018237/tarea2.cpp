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

using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;

using namespace std;




 // enumeración con constantes que representa el estado del juego
enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"

void mensajes();
int craps();
int tirarDados(); // tira los dados, calcula y muestra la suma es una funcion, no recibe parametro y devuelve un entero




int main()  //juego de craps como función
{
  int saldoBanco = 1000;
  int resultado;
  int apuesta = 0;
  char jugarNuevamente;

  srand ( time ( 0 ) );

  do {
    cout << "tienes $" << saldoBanco
         << "en el Banco. \nhaz tu apuesta:";
    cin >> apuesta;

    while ( apuesta <= 0 || apuesta > saldoBanco) {
      cout << "ingresa una cantidad valida para apostar";
      cin >> apuesta;
    }


    resultado = craps();


    if ( resultado == PERDIO ) {
      saldoBanco -= apuesta;
      cout << " su saldo bancario es $" << saldoBanco << "\n";


      if ( saldoBanco == 0 ) {
	cout << "lo siento. Gracias por jugar.\n";
	break;

      }


   }
   else {
     saldoBanco += apuesta;
     cout << "tu nuevo balance es $" << saldoBanco  << "\n";

   }

   cout << "te gustaria volver a probar suerte?";
   cin >> jugarNuevamente;
 } while ( jugarNuevamente == 'y' || jugarNuevamente == 'Y' );

 cout << endl;

 return 0;
}
    
    






int craps()
{

  
  unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO
  
  // randomiza el generador de números aleatorios, usando la hora actual
  srand( time( 0 ) );

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
      
      // determina el estado del juego
      if ( sumaDeDados == miPunto ) // gana al hacer un punto
	estadoJuego = GANO;
      else if ( sumaDeDados == 7 ) // pierde al tirar 7 antes del punto
	  estadoJuego = PERDIO;
    } // fin de while
  
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO )
    cout << "El jugador gana" << endl;
  else
    cout << "El jugador pierde" << endl;
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


//vamos iniciar con los mensajes//
void mensajes()
{
  switch (1 + rand() % 9) {
  case 1:
    cout << "oh, se esta yendo a la quiebra,verdad?";
    break;
  case 2:
    cout << "oh, vamos, arriesguese";
    break;
  case 3:
    cout << "creo que vas a quebrar el banco";
  case 4:
    cout << "has ganado mucho, cobra tus fichas";
  case 5:
    cout << "tienes mucha suerte, esta como raro";
  case 6:
    cout << "apuesta todo";
  case 7:
    cout << "¿Puedo pedir prestado dinero?";
  case 8:
    cout << "probemos suerte en otra mesa";
  case 9:
    cout << "TRAMPOSO";

    break;
  }

  cout << endl;
}
  
     
