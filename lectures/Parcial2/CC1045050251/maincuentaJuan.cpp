#include <iostream>
#include <iomanip>
using namespace std;


#include "clasebaseJuan.h"

int main()
{
  Cuenta bancaria1(10700); 
  cout << "Saldo "<< bancaria1.getSaldo()<< endl; 
  bancaria1.abonar(3200);
  cout << "Sumando el abono..."<<endl;
  bancaria1.mostrarSaldo();
  cout << "--------------------"<<endl; 
  
  //hace un retiro
  bancaria1.cargar(2300);
  cout << "Saldo luego de retirar"<<endl;
  bancaria1.mostrarSaldo(); 
  cout << "-----------------"<<endl; 

  
  cout << "Su saldo es de: " << bancaria1.getSaldo() <<endl; 

  return 0;
}
