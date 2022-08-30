#include <iostream>
using namespace std;

#include "cuenta_ahorros.h"

// constructor
CuentaAhorros::CuentaAhorros( double S, double tasaint) : Cuenta( S )
{ 
   if (tasaint < 0.0 ){
        cout<<"Tasa ingresada inválida. Se establece en 0.0"<<endl;
        tasadeinteres = 0.0;
    }
  setInteres(tasaint); // en porcentaje 0% - 100% 
}

double CuentaAhorros::calcularinteres()
{ 
  cout<<"\nEl interés de esta cuenta es: "<< tasadeinteres*getsaldo() <<endl;
  return getsaldo()*(tasadeinteres); // monto de interes
}

void CuentaAhorros::setInteres(double interes)
{

tasadeinteres = ( interes> 0.0 && interes < 1.0 ) ? interes: 0.0;
}

