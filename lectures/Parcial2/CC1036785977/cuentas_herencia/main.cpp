#include <iostream>
#include <iomanip>
using namespace std;

#include "CuentaAhorros.h"
#include "CuentaCheques.h"

int main()
{
  // Nota: en los mensajes del main se colocan los mismos valores de entrada del las inicializaciones, si se cambian los mensajes no lo haràn.

  cout << "Para la cuenta de ahorros: "<< endl;
  CuentaAhorros persona( 5000 , 10 ) ; // instancia objeto cuenta ahorros
  cout << "Saldo luego de iniciar con 5000 y interes del 10%:"<<endl; 
  persona.imprimirSaldo(); // imprime el saldo
  cout << "El monto de interes es: ";
  cout << persona.calcularInteres() << endl ; 
  //usando las funciones de Cuenta
  persona.abonar(persona.calcularInteres()); //abona el interes
  cout << "Saldo luego de abonar el interes: "<<endl;
  persona.imprimirSaldo();
  persona.cargar(4000); //retiremos
  cout << "Saldo luego de cargar 4000: "<<endl;
  persona.imprimirSaldo();
  persona.cargar(8000);
  cout << "Saldo luego de cargar mas del saldo (8000): "<<endl;
  persona.imprimirSaldo();
  cout << "El saldo final es de: " << persona.getSaldo() <<endl; //notar el  get.Saldo
  
  cout << "\n\nPara la cuenta de cheques "<< endl;
  CuentaCheques persona1( 10000 , 800 ) ; // instancia objeto cuenta ahorros
  cout << "Saldo luego de iniciar con 10000 y cuota de 800: "<<endl; 
  persona1.imprimirSaldo(); // imprime el saldo
  persona1.abonar(2000);
  cout << "Saldo luego de abonar 2000: "<<endl; 
  persona1.imprimirSaldo();
  persona1.cargar(3000); //retiremos 
  cout << "Saldo luego de cargar 3000: "<<endl;
  persona1.imprimirSaldo();
  persona1.cargar(20000);
  cout << "Saldo luego de cargar mas del saldo (20000): "<<endl;
  persona1.imprimirSaldo();
  cout << "El saldo final es de: " << persona1.getSaldo() <<endl; //notar el  get.Saldo
  
  
  return 0;
}
