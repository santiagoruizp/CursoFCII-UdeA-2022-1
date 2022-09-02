#include <iostream>
using namespace std;

#include "CuentaCheques.h"

// constructor
CuentaCheques::CuentaCheques( double ss, double cuo ) : Cuenta( ss )
{
  setCuota(cuo);  
}

void CuentaCheques::setCuota(double cuo)
{
	if (cuo > 0) {
	cuota = cuo;
	}
	else{
	cuota = 5000; // se establece un valor cualquiera
	cout<<"cuota de cargo invalida, establecida en "<<cuota<<endl;
	}
}

void CuentaCheques::cargar( double retiro)
{
if (retiro>=0){
    if (retiro+cuota<=getSaldo()){
    setSaldo(getSaldo()-retiro-cuota);
    }
    else{
    cout<<"El monto a cargar excede el saldo de la cuenta: El cargo es de 0.0" << endl;
    }
  }
  else {
  cout<<"El cargo ingresado es invalido: El cargo es de 0.0" << endl;
  }
}

