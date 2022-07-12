#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time

/*using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;*/

using namespace std;

int tirarDados();
int main()
{
  int SaldoenBlanco = 1000000;
  cout << "Su saldo es de " << SaldoenBlanco << " de pesos." << endl; 
  

  int option=1;
  
  while (option == 1){
  
  	int Apuesta;
  	cout << "Introduzca una apuesta." << endl;
  	cin >> Apuesta;

  	while(Apuesta > SaldoenBlanco){
		cout << "Debe ingresar una apuesta menor o igual que su saldo es blanco. Ingrese por favor un valor apropiado." << endl;
        	cin >> Apuesta;
  	}
  
  
  	enum Estado { CONTINUAR, GANO, PERDIO }; 
  
  	unsigned int miPunto = 0; 
  	Estado estadoJuego;
 	srand( time( 0 ) );

  	int sumaDeDados = tirarDados(); // primer tiro del dado
  	switch ( sumaDeDados )
    	{
    		case 7: 
    		case 11: 
      			estadoJuego = GANO;
      			break;
    		case 2: 
    		case 3: 
    		case 12:
      			estadoJuego = PERDIO;
      			break;
    		default: 
      			estadoJuego = CONTINUAR;
      			miPunto = sumaDeDados; 
      			cout << "El punto es: " << miPunto << endl;
      			break; 
    	} 

  
  	while ( estadoJuego == CONTINUAR )
    	{	
        	sumaDeDados = tirarDados();
      
      		if ( sumaDeDados == miPunto ) 
			estadoJuego = GANO;
      		else if ( sumaDeDados == 7 ) 
	  		estadoJuego = PERDIO;
    	} 
  
  	if ( estadoJuego == GANO ){
  	
    		cout << "El jugador gana." << endl;
    		SaldoenBlanco = SaldoenBlanco + Apuesta;
    		cout << "Ahora tiene: " << SaldoenBlanco << " pesos." << endl;
    	}
    	
  	else{
    		cout << "El jugador pierde." << endl;
    		SaldoenBlanco = SaldoenBlanco - Apuesta;
    		cout << "Ha quedado con " << SaldoenBlanco << " pesos." << endl;
    	}
    	
    	if (SaldoenBlanco==0){
    	
    		cout << "Lo siento. ¡Se ha quedado sin fondos!" << endl;
    		break;
    	
    	}
	
	if (estadoJuego == PERDIO && Apuesta >= SaldoenBlanco){
		cout << "Uhh... cuidado, perdiste un buen monto ahí." << endl;
	}
  	
  	else if (estadoJuego == PERDIO && Apuesta < SaldoenBlanco){
  		cout << "Bueno, perdiste pero todavía bastante por ganar." << endl;
  	
  	}
  	
  	else if (estadoJuego == GANO && Apuesta >= SaldoenBlanco*0.5){
  		cout << "Ufff, ¡esa fue buena!" << endl;
  	}
  	else if (estadoJuego == GANO && Apuesta < SaldoenBlanco*0.5){
  		cout << "¡Nada mal!,  ¿vamos por más?" << endl;
  	}
  		
  	
  	
  	cout << "Ingrese 1 si desea seguir jugando, 0 si no desea jugar más." << endl;
  	cin >> option;
  	
  	while(option != 0 && option != 1){
  		cout << "Ingresó un valor de opción no permitido, ingrese 0 si no desea jugar más y 1 si desea jugar más." << endl;
  		cin >> option;
  	}
  	
  	if (option == 1){
		cout << "¡Bienvenido/a!" << endl;
		cout << "Su saldo actual es de " << SaldoenBlanco << " pesos." << endl;	
  	}
  	else {
  		cout << "¡Hasta luego!"<< endl;
  	}
  	}
  
  
  	return 0;
} 


int tirarDados()
{
  int dado1 = 1 + rand() % 6; 
  int dado2 = 1 + rand() % 6; 
  
  int suma = dado1 + dado2; 
  

  cout << "El jugador tiro " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; 
} 
