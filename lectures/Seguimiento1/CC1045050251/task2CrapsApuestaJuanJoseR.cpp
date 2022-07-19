#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std; 


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

int Jugar(){

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
      estadoJuego = GANO;
      return 1; 
      break;
    case 11: // gana con 11 en el primer tiro
      estadoJuego = GANO;
      return 1; 
      break;
    case 2: // pierde con 2 en el primer tiro
      estadoJuego = PERDIO;
      return 0; 
      break;
    case 3: // pierde con 3 en el primer tiro
      estadoJuego = PERDIO;
      return 0; 
      break;
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

int main(){
    srand(time(NULL));
    float apuesta;
    float SaldoenBanco =1000000;
    float resultado;
    int opcion=1;

    while (opcion==1 && SaldoenBanco !=0){
        switch(opcion){
            case 1: 
            cout<<"\nIngrese el valor a apostar"<<endl<<" sin miedo arriesguese!"<<endl;
            cin>>apuesta;

            while(apuesta>SaldoenBanco){
            cout<<"\nIngrese un valor menor a:"<<SaldoenBanco<<endl;
            cin>>apuesta;}

            resultado=Jugar(); //tira los dados y decide GANA PIERDE CONTINUA
            if (resultado==1){
            cout<<"\n ganasté"<<endl;
            SaldoenBanco+=apuesta;
            cout<<"\nEl nuevo saldo en el banco es de:"<<SaldoenBanco<<endl;
            cout<<"\nMuy bien!. Ahora es tiempo de cambiar sus fichas por  la plata!"<<endl;}
            else {
            cout<<"\nperdiste!"<<endl;
            SaldoenBanco-=apuesta;
            cout<<"\nEl nuevo saldo en el banco:"<<SaldoenBanco<<endl;
            cout<<"\n vas muy mal se esta quebrando, no le parece?"<<endl;}
            cout<<"\nSi desea seguir jugando ingrese 1, si quiere salir del juego ingrese 0"<<endl;	
            cin>>opcion; 
            break;

            case 0:
            apuesta=0;
            cout<<"chaoo gracias por jugar";
            break;

            default:
            cout<<"Ingrese algun número permitido"<<endl;

        }
    }

    if (SaldoenBanco==0){
        cout<<"te quedaste sin plata!!";
    }
}