/*Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. Una
vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. Si la
suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se
convierte en el “punto” del jugador. Para ganar, el jugador debe seguir tirando los dados hasta que salga otra
vez “su punto”. El jugador pierde si tira un 7 antes de llegar a su punto.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std; 
///////////////////////////////////////////////
int tirarDados()
{
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6; // tiro del primer dado
  int dado2 = 1 + rand() % 6; // tiro del segundo dado
  
  int suma = dado1 + dado2; // calcula la suma de valores de los dados
  
  // muestra los resultados de este tiro
  cout << "El jugador tiró " << dado1 << " + " << dado2 << " = " << suma << endl;
  return suma;
  }
//////////////////////////////////////////////////
int Apuesta()
{
srand(time(NULL));
  // enumeración con constantes que representa el estado del juego
  enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  //enum class Estado {CONTINUAR, GANO, PERDIO}; // note el "class"
  unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO
  // randomiza el generador de números aleatorios, usando la hora actual
  int sumaDeDados = tirarDados(); // primer tiro del dado
  // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
  switch ( sumaDeDados )
    {
    case 7: // gana con 7 en el primer tiro
    case 11: // gana con 11 en el primer tiro
      estadoJuego = GANO;
      return 1; 
      break;
    case 2: // pierde con 2 en el primer tiro
    case 3: // pierde con 3 en el primer tiro
    case 12: // pierde con 12 en el primer tiro
      estadoJuego = PERDIO;
      return 0; 
      break;
    default: // no ganó ni perdió, por lo que recuerda el punto
      estadoJuego = CONTINUAR; // el juego no ha terminado
      miPunto = sumaDeDados; // recuerda el punto
      //cout << "El punto es " << miPunto << endl;
      break; // opcional al final del switch
    } // fin de switch
//////////////////////////////////////////////////////////////////////////////////////////////////
  while ( estadoJuego == CONTINUAR ) // no ganó ni perdió
    {
      sumaDeDados = tirarDados(); // tira los dados de nuevo  
      // determina el estado del juego
      if ( sumaDeDados == miPunto ){ // gana al hacer un punto
	estadoJuego = GANO;
	return 1; }
      else if ( sumaDeDados == 7 ){ // pierde al tirar 7 antes del punto
	  estadoJuego = PERDIO;
	  return 0;}
}
 return 0; // indica que terminó correctamente
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/*
a)Escriba una aplicación que juegue a ``craps" (ya la tenemos!).
b)Modifique el programa del item anterior para permitir apuestas. Empaquete como función la parte del programa que ejecuta un juego de craps. Inicialice la variable SaldoenBanco con 1000000 de pesos. Pida al jugador que introduzca una apuesta . Use un ciclo while para comprobar
 que esa apuesta sea menor o igual al SaldoenBanco y, si no lo es, haga que el usuario vuelva a introducir la apuesta hasta que se introduzca un valor válido. Después de esto, comience un juego de craps. Si el jugador gana, agregue la apuesta al SaldoenBanco e imprima el nuevo SaldoenBanco. Si el jugador pierde, reste la apuesta al SaldoenBanco , imprima el nuevo SaldoenBanco , compruebe si SaldoenBanco se ha vuelto cero y, de ser así, imprima el mensaje "Lo siento. Se quedo sin fondos!" A medida que el juego progrese, imprima varios mensajes para crear algo de ``charla", como "usted se esta quebrando, no le parece?" , o "hagale, no pasa nada, arriesguese!" , o "La sacaste del estadio. Ahora
es tiempo de cambiar sus fichas por  la plata!" .*/
int main(){
srand(time(NULL));
float ap;
float SaldoenBanco =1000000;
float gp;
int op=1;
while (op==1 && SaldoenBanco !=0){

switch(op){
case 1: 
	cout<<"\nIngrese el valor que quiere apostar"<<endl<<"Hágale, no pasa nada, arriesguese!"<<endl;
	cin>>ap;


	while(ap>SaldoenBanco){
		cout<<"\nIngrese un valor que sea menor a:"<<SaldoenBanco<<endl;
		cin>>ap;
	}
	gp=Apuesta();
	if (gp==1){
		cout<<"\nEl jugador ganó"<<endl;
		SaldoenBanco+=ap;
		cout<<"\nEl nuevo saldo en el banco es de:"<<SaldoenBanco<<endl;
		cout<<"\nLa sacaste del estadio. Ahora es tiempo de cambiar sus fichas por  la plata!"<<endl;}
	else {
		cout<<"\nEl jugador perdió"<<endl;
		SaldoenBanco-=ap;
		cout<<"\nEl nuevo saldo en el banco es de:"<<SaldoenBanco<<endl;
		cout<<"\n Usted se esta quebrando, no le parece?"<<endl;}
	cout<<"\nSi desea seguir apostando ingrese 1, si quiere dejar de apostar ingrese 0"<<endl;	
	cin>>op; 
	break;
case 0:
op=0;
cout<<"Gracias por jugar";
break;
default:
cout<<"Ingrese alguno se los número permitidos"<<endl;
}}

if (SaldoenBanco==0){
cout<<"Lo siento. Se quedó sin fondos!";}
}

