
// Tarea 2 Alejandro Restrepo Giraldo CC: 1001389709


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
#include <stdlib.h>


/*using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;*/

using namespace std;

int tirarDados(); // tira los dados, calcula y muestra la suma
int JuegoCraps();





int main()
{
  // Saldo y entero para almacenar la apuesta
  int SaldoenBanco = 1000000;
  // se declara la apuesta como unsigned int debido a que debe ser un valor positivo y del orden de 10⁵ 
  unsigned int apuesta;
  // Centinela para iniciar el juego o terminarlo
  int i;
  // Contadores para mensajes
  int victorias = 0, derrotas = 0;
  
  cout<<"Bienvenido al juego de craps!!!"<<endl;
  cout<<"Esto es un juego de apuestas. Ingresa 1 para jugar: ";
  cin>>i;
  
  while (i == 1){
  
  // Se introduce la apuesta
  cout<<"Introduzca una apuesta: ";
  cin>>apuesta;
  
  // Estas líneas para evitar un error en el ciclo while. Apuesta no debe ser mayor que el valor máximo de unsigned int
  if (apuesta > 4294967295){
    cout<<"Nadie tiene tanto dinero para apostar. Reinicie el juego";
    exit(0);
  }
  
  // Se comprueba que la apuesta no sea mayor que el saldo
  while (apuesta > SaldoenBanco){
    cout<<"Saldo insuficiente. Introduzca una apuesta de acuerdo a sus posibiidades:";
    cin>>apuesta;
  }
  
  // Inicio del juego de craps
  int result = JuegoCraps();
  
  // De acuerdo al resultado se cambia el saldo
  if (result == 1){
    SaldoenBanco += apuesta;
    victorias++;
    cout<<"Ganaste, tu nuevo saldo es "<<SaldoenBanco<<"$"<<endl<<endl;
    cout<<"Ahora eres más rico!!!"<<endl;
  }
  
  if (result == 2){
    SaldoenBanco -= apuesta;
    derrotas++;
    cout<<"Perdiste, tu nuevo saldo es $"<<SaldoenBanco<<endl<<endl;
  }
  
  //Interacción con el usuario
  if (SaldoenBanco >= 2000000){
    cout<<"Tienes más de el doble que cuando empezaste!!!. Podrías perderlo todo o duplicarlo."<<endl;
  }
  if (2000000 > SaldoenBanco && SaldoenBanco >= 1500000){
    cout<<"Wow, vas muy bien sigue jugando."<<endl;
  }
  if (300000 < SaldoenBanco && SaldoenBanco <= 500000){
    cout<<"Tienes casi la mitad de dinero que cuando empezaste, pero la riqueza es solo suerte aquí. Ánimo!!!."<<endl;
  }
  if (50000 <= SaldoenBanco && SaldoenBanco <= 300000){
    cout<<"Si eres casado tu esposa te matará."<<endl;
  }
  if (SaldoenBanco <= 50000){
    cout<<"Estás quebrado. Posiblemente no te alcance ni con que ir a casa. Tranquilo, dirigete a la caseta de crédito en nuestras instalaciones para acceder a préstamos con perversos intereses."<<endl;
  }
  if (SaldoenBanco == 0){
    cout<<"Lo has perdido todo imprudente."<<endl;
    break;
  }


 
  
  cout<<endl<<"¿Quiere jugar más?. Introduzca 1 si va a continuar: ";
  cin>>i;
  }
  
  // Balance de la apuesta
  cout<<endl<<"Balance de la apuesta: Ganó "<<victorias<<" veces y perdió "<<derrotas<<" veces"<<endl;
  
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




int JuegoCraps(){
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
  
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO )
    cout << "El jugador gana" << endl;
  else
    cout << "El jugador pierde" << endl;
    
  return estadoJuego;

}

















