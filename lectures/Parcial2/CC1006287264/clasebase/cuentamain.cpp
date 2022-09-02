#include <iostream>
#include <iomanip>
using namespace std;

#include "cuenta.h"

int main()
{

  // instancia un objeto EmpleadoPorComision
  Cuenta persona(-1000 );
  cout << fixed << setprecision( 2 );
  
  cout << "Saldo inicial: "<<persona.getsaldo(); 
  persona.abonar(-2000) ;
  cout << "Abono:$"<<persona.getabono();
  cout << "\nSaldo luego de abonar:"<<persona.getsaldo();
  persona.cargar(-2000);// cargar 
  cout << "Cargo:$"<<persona.getcarga();
  cout << "\nSaldo luego de cargar:"<<persona.getsaldo();
  
/*
  // obtiene los datos del empleado por comisión
  cout << "\nInformacion del empleado obtenida por las funciones get: \n"
       << "\nEl saldo es " << empleado.getVentasBrutas()
       << "\nValor de abono " << empleado.getabono() 
       << "\nValor de carga " << empleado.getcarga() 
       << "\nSaldo final: "<<empleado.getsaldo()   << endl;
  
  //empleado.setsaldo( 8000 ); // establece las ventas brutas
  //empleado.setTarifaComision( .1 ); // establece la tarifa de comisión

  //cout << "\nInformacion actualizada del empleado, mostrada por la funcion imprimir: \n" << endl;
  //empleado.imprimir(); // muestra la nueva informacion del empleado
*/  
  // muestra los ingresos del empleado
  cout << "\n\nSaldo total: $" << persona.getsaldo() << endl;
  return 0;
}