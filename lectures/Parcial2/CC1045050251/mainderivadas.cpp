#include <iostream>
#include <iomanip>
using namespace std;

#include "CuentaAhorros.h"
#include "CuentaCheques.h"

int main()
{
  
  cout << "Actualizando cuenta de ahorros: "<< endl;
  CuentaAhorros bancaria1( 10000 , 20 ) ; 
  cout << "Su saldo + interes..."<<endl; 
  bancaria1.imprimirSaldo(); 
  cout << "El interes es del: "<< bancaria1.calcularInteres() << endl ; 
  
  bancaria1.abonar(bancaria1.calcularInteres()); 
  cout << "Saldo abonando interes... "<<endl;
  bancaria1.imprimirSaldo();

  bancaria1.cargar(1200); 
  cout << "Saldo luego de retirar 1200... "<<endl;
  bancaria1.imprimirSaldo();
  bancaria1.imprimirSaldo();
  cout << "Saldo total: " << bancaria1.getSaldo() <<endl; 

  cout << "------------------------------"<< endl;
  cout << "\n Calculo con cheques "<< endl;
  CuentaCheques personacheques( 20000 , 500 ) ; 
  cout << "Saldo inicial 20000, cuota de 500: "<<endl; 
  personacheques.imprimirSaldo(); 
  personacheques.abonar(3000);
  cout << "Saldo + abono de 3000: "<<endl; 
  personacheques.imprimirSaldo();
  personacheques.cargar(700); 
  cout << "Saldo menos retiro de 700: "<<endl;
  personacheques.imprimirSaldo();
  cout << "Saldo total de: " << personacheques.getSaldo() <<endl;
  return 0;
}