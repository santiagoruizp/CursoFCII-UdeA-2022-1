/*
Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. Una
vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. Si la
suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se
convierte en el “punto” del jugador. Para ganar, el jugador debe seguir tirando los dados hasta que salga otra
vez “su punto”. El jugador pierde si tira un 7 antes de llegar a su punto.
*/


/*Tarea2.
a)Escriba una aplicación que juegue a ``craps" (ya la tenemos!).
b)Modifique el programa del item anterior para permitir apuestas. Empaquete como función la parte del programa que ejecuta un juego de craps. Inicialice la variable SaldoenBanco con 1000000 de pesos. Pida al jugador que introduzca una apuesta . Use un ciclo while para comprobar
 que esa apuesta sea menor o igual al SaldoenBanco y, si no lo es, haga que el usuario vuelva a introducir la apuesta hasta que se introduzca un valor válido. Después de esto, comience un juego de craps. Si el jugador gana, agregue la apuesta al SaldoenBanco e imprima el nuevo SaldoenBanco. Si el jugador pierde, reste la apuesta al SaldoenBanco , imprima el nuevo SaldoenBanco , compruebe si SaldoenBanco se ha vuelto cero y, de ser así, imprima el mensaje "Lo siento. Se quedo sin fondos!" A medida que el juego progrese, imprima varios mensajes para crear algo de ``charla", como "usted se esta quebrando, no le parece?" , o "hagale, no pasa nada, arriesguese!" , o "La sacaste del estadio. Ahora
es tiempo de cambiar sus fichas por  la plata!" .
*/

#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time

/*using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;*/

using namespace std;

int tirarDados(); // tira los dados, calcula y muestra la suma
bool JuegoCraps(); //Juego de craps empaquetado como función
int main()
{
  int SaldoenBanco=1000000;//Saldo inicial en pesos
  int apuesta,seguirjug=1;
  bool resultado;
  cout << "Introduzca una apuesta menor o igual a un millon que es su saldo inicial " << endl;
  cin >> apuesta;
  while ( SaldoenBanco > 0 && seguirjug==1 )
    {
      if(apuesta> SaldoenBanco )
	{
	  cout << "Valor de la apuesta mayor al saldo, introduzca nuevamente una apuesta acorde posible:  " << endl;
	  cin >> apuesta;
	}
      else
	{
	  resultado= JuegoCraps();
	  if(resultado)
	    {
	      SaldoenBanco+=apuesta;
	      cout << "Ha ganado, su nuevo saldo es: "<< SaldoenBanco << endl;
	    }
	  else
	    {
	      SaldoenBanco-=apuesta;
	      cout << "Ha perdido, su nuevo saldo es: "<<SaldoenBanco << endl;
	    }
	  if(SaldoenBanco<80000)
	    cout << "Usted se esta quebrando, no le parece"<< endl;
	  if(SaldoenBanco<500000 && SaldoenBanco>200000)
		   cout << "Hagale, no pasa nada, arriesguese!" << endl;
	  if(SaldoenBanco>2500000)
		   cout << "La sacaste del estadio. Ahora es tiempo de cambiar sus fichas por plata!"<< endl;
	  if(SaldoenBanco>0)
	    {
	      cout << "Aun tiene fondos, ¿desea seguir apostando? \n si desea hacerlo, introduzca 1, si no 0 " << endl;
	      cin >> seguirjug;
	      if(seguirjug==1)
		{
		  cout << "Introduzca el valor de su nueva apuesta"<<endl;
		  cin >> apuesta;

		}
	      else
		{
		  cout << "¡Felicidades! su saldo final es: "<< SaldoenBanco << endl;
		}
	    }
	  else
	    {
	      cout << "Lo siento. Se quedo sin fondos!"<< endl;
	    }
	  
	}
    }
  return 0;
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

bool JuegoCraps()
{
  // enumeración con constantes que representa el estado del juego
  enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"
  
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
  
  // muestra mensaje de que ganó o perdió la ronda
  if ( estadoJuego == GANO )
    cout << "El jugador gana" << endl;
  else
    cout << "El jugador pierde" << endl;
  return estadoJuego==GANO; // Devuelve el estado del Juego
}
