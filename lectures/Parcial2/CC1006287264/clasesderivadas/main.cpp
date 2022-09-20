#include <iostream>
#include <iomanip>
using namespace std;

#include "Cuenta_ahorros.h"
#include "Cuenta_cheques.h"

int main()
{ cout << "\n\nCuenta de Ahorros: "<< endl;
  CuentaAhorros cuenta2( 1000 ,0.1) ;
  cout << "Saldo inicial:"<<cuenta2.getsaldo(); 
  cuenta2.calcularinteres();// cálculo de primera forma
  cuenta2.abonar(1000); // se abona 
  cout << "\nAbono:$"<<cuenta2.getabono();
  cout << "\nSaldo luego de abonar:"<<cuenta2.getsaldo();
  cuenta2.abonar(cuenta2.calcularinteres());// cálculo de seguna forma
  cuenta2.cargar(2000); // se carga
  cout << "Cargo:$"<<cuenta2.getcarga();
  cout << "\nSaldo total: $" << cuenta2.getsaldo() << endl;

  cout << "\n\nCuenta de cheques "<< endl;
  CuentaCheques persona1( 10000 , 800 ) ;
  cout << "Saldo inicial : "<<persona1.getsaldo(); 
  persona1.abonar(2000);
  persona1.cargar(2000);
  
  
  cout << "\nSaldo total: $" << persona1.getsaldo() << endl;
}