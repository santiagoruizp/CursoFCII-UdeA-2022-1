
// ------------------------------------------
// JUEGO CRAPS
// ------------------------------------------
/*
Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. 
Una vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. 
- Si la suma es 7 u 11 en el primer tiro, el jugador gana. 
- Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”), el jugador pierde (es decir, la “casa” gana). 
- Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se convierte en el “punto” del jugador. 
Para ganar, el jugador debe seguir tirando los dados hasta que salga otra vez “su punto”. 
El jugador pierde si tira un 7 antes de llegar a su punto.
*/


#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time
#include <list>
#include <unistd.h>

#include "craps.h"

using namespace std;


JuegoCraps::JuegoCraps(){

} 


// ------------------------------------------
// INICIALIZA EL DINERO A APOSTAR
// ------------------------------------------
float JuegoCraps::dineroApostar(){

float SaldoenBanco = 100000;

cout << "¡Bienvenid@ al Juego Craps!" <<endl;
cout << "¿Cuánto dinero deseas apostar?" << endl; 
cin >> SaldoenBanco;

while (SaldoenBanco > 100000 or SaldoenBanco < 100 or cin.fail())
{
  if (cin.fail())
  {
    cout << "Por favor, debes apostar dinero. Ingresa un número." << endl;
    cin.clear();
    cin.ignore(256,'\n');
  }else if (SaldoenBanco > 100000)
  {
    cout << "Tu apuesta no es válida. Debes ingresar un valor menor o igual a $100mil: " << endl; 
  } else if (SaldoenBanco < 100)
  {
     cout << "¿Qué clase de apuesta es esa?. Debes apostar más de $100 " << endl; 
  }
  
  cin >> SaldoenBanco;
  
}
cout << "El dinero que apostarás es: " << SaldoenBanco <<endl;
cout << "-----------------------------" <<endl; 

return SaldoenBanco;
}


// ------------------------------------------
// LANZA LOS DADOS
// ------------------------------------------
int JuegoCraps::tirarDados(){
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6; // tiro del primer dado
  int dado2 = 1 + rand() % 6; // tiro del segundo dado
  
  int suma = dado1 + dado2; // calcula la suma de valores de los dados
  
  // muestra los resultados de este tiro
  cout << "Tiraste: " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; // devuelve la suma de los dados
}




// ------------------------------------------
// DETERMINA EL ESTADO DEL JUEGO
// ------------------------------------------
float JuegoCraps::estadoJuego(){
  // enumeración con constantes que representa el estado del juego
  enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  
  unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO
  
  // primer tiro del dado
  cout << "Presiona ENTER para tirar los dados " <<endl;
  cin.clear();
  cin.ignore(256,'\n');
  int sumaDeDados = tirarDados(); 
  
  
  // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
  switch ( sumaDeDados )
    {
    case 7: // gana con 7 en el primer tiro
    case 11: // gana con 11 en el primer tiro
      estadoJuego = GANO;
      //estadoJuego = Estado::GANO; // si se usa la linea 27 con la clase
      break;
    case 2: // pierde con 2 en el primer tiro
    case 3: // pierde con 3 en el primer tiro
    case 12: // pierde con 12 en el primer tiro
      estadoJuego = PERDIO;
      cout << "Upps has perdido!" << endl;
      break;
    default: // no ganó ni perdió, por lo que recuerda el punto
      estadoJuego = CONTINUAR; // el juego no ha terminado
      miPunto = sumaDeDados; // recuerda el punto
      cout << "Tira otra vez! Debes sacar " << miPunto << " para ganar!"<< endl;
      break; 
    } 
  

  // mientras el juego no esté completo
  while ( estadoJuego == CONTINUAR ) 
    { // no ganó ni perdió
      cin.ignore();
      sumaDeDados = tirarDados(); // tira los dados de nuevo
      
      // determina el estado del juego
      if ( sumaDeDados == miPunto ) 
	        // gana al hacer un punto
          estadoJuego = GANO;
      else if ( sumaDeDados == 7 ) 
          // pierde al tirar 7 antes del punto
	        estadoJuego = PERDIO;
    }
  
  // muestra mensaje de que ganó o perdió y retorna el estado
  int estado = 2; 
  if (estadoJuego == GANO )
  {
   cout << "¡¡GANASTE!!" << endl;
   estado = 1;
  }else{
    cout << "HAS PERDIDO..." << endl;
    estado = 0;
  }

return estado;
}

// ------------------------------------------
// CALCULA EL DINERO QUE TIENE EL JUGADOR
// ------------------------------------------
float JuegoCraps::calcularDinero(float estado, float apuesta){

  sleep(1); //espera 1 segundo en mostrar el mensaje
  float dinero = 0;
  if (estado==1.0) // si gana, suma la apuesta
  {
    dinero = apuesta;
    cout << "Has ganado " << dinero << " pesos!"<<endl;
  }else{         // si pierde, resta la apuesta
    dinero = -1*apuesta;
    cout << "Se te fueron " << dinero << " pesos."<<endl;
  }
  return dinero;
  
}

// ------------------------------------------
// MUESTRA MENSAJES DE CANTIDAD DE DINERO
// ------------------------------------------
void JuegoCraps::mostrarMensajeDinero(float dineroJugador){

if (dineroJugador>0)
{
  cout << "Ya tienes unos : " << dineroJugador << " pesos." <<endl;

}else{
  cout << "Ya tienes $0 pesos." <<endl;
  cout << "Lo siento. Se quedo sin fondos!" <<endl;
}

}


// ------------------------------------------
// MUESTRA MENSAJES DE CONVERSACIÓN
// ------------------------------------------
void JuegoCraps::mostrarMensaje(int estado){

list<string> mensajesPositivos = { 
  "A este ritmo te volveras millonari@!",
  "Pero si sos expert@ en tirar dados virtuales!",
  "Continúe, arriesguese!",
  "La sacaste del estadio. Ahora es tiempo de cambiar sus fichas por la plata!"};

list<string> mensajesNegativos = {
  "Yo a usted no le prestaría plata...",
  "¿Siempre has tenido tan mala suerte?",   
  "Usted se esta quebrando, ¿no le parece?" , 
  "Que espectáculo tan triste D: "
  };

// Elige un mesaje al azar depediendo si perdió o ganó dinero
int posicion= rand() % 4;

if (estado==1)
{
  // Create iterator pointing to first element
  list<string>::iterator it_pos = mensajesPositivos.begin();

  // Advance the iterator by 2 positions,
  advance(it_pos, posicion);
  cout << *it_pos <<endl; 

}if(estado==0){
  // Create iterator pointing to first element
  list<string>::iterator it_neg = mensajesNegativos.begin();

  // Advance the iterator by 2 positions,
  advance(it_neg, posicion);
  cout << *it_neg <<endl; 
}

cout << "-----------------------------" <<endl; 

}

