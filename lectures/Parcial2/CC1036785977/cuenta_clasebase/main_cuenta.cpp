#include <iostream>
#include <iomanip>
using namespace std;

#include "ClaseCuenta.h"

int main()
{
  
  Cuenta persona(5000); // instancia objeto
  cout << "Saldo luego de iniciar"<<endl; 
  persona.imprimirSaldo(); // imprime el saldo
  persona.abonar(2000);
  cout << "Saldo luego de abonar"<<endl;
  persona.imprimirSaldo();
  persona.cargar(4000);
  cout << "Saldo luego de cargar"<<endl;
  persona.imprimirSaldo();
  persona.cargar(8000);
  cout << "Saldo luego de cargar mas del saldo"<<endl;
  persona.imprimirSaldo();
  cout << "El saldo final es de: " << persona.getSaldo() <<endl; //notar el get.Saldo
  
  
  return 0;
}
