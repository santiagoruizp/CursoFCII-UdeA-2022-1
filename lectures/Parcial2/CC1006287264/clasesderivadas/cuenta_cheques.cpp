#include <iostream>
using namespace std;

#include "cuenta_cheques.h"

CuentaCheques::CuentaCheques( double S, double ci) : Cuenta( S )
{
    // Si la cuota es positiva se carga a la variable privada de CuentaCheques cuota
    if (ci < 0.0 ){
        cout<<"Cuota ingresada inválida. Se establece en 0.0"<<endl;
        ci = 0.0;
        cuota=ci;
    }
    
   setCuota(ci);
        
}
void CuentaCheques::setCuota(double ci ){
  cuota= ci;
}

void CuentaCheques::abonar(double abono){
  if (( abono< 0.0 ) )
  cout<<"Abono ingresado inválido"<<endl;
  else{
   cout<<"\nAbono de $"<<abono <<" y cuota de $"<<cuota;
   Cuenta::abonar(abono -cuota);
  }
}
void CuentaCheques::cargar(double cargo){
  if (( cargo< 0.0 ) )
  cout<<"\nCargo ingresado inválido"<<endl;
  else{
   cout<<"\nCargo de $"<<cargo <<" y cuota de $"<<cuota;
   Cuenta::cargar(cargo +cuota);// se garantiza que el cargo más la cuota sea menor al saldo 
  }
  
  
  
  
  
}