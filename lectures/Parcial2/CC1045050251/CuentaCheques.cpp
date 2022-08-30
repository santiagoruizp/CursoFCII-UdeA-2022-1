#include <iostream>
using namespace std;

#include "CuentaCheques.h"

CuentaCheques::CuentaCheques( double _saldo, double _cuota ) : Cuenta( _saldo )
{
  setCuota(_cuota);  
}

void CuentaCheques::cargar( double retiro){
if (retiro>=0){
    if (retiro+cuota<=getSaldo()){ setSaldo(getSaldo()-retiro-cuota);
    }
    else{
    cout<<"Monto a retirar excede el saldo en la cuenta, retiro restablecido en 0,0" << endl;
    }
  }
  else { cout<<"El cargo ingresado es invalido: El cargo es de 0.0" << endl;
  }
}

void CuentaCheques::setCuota(double _cuota)
{
	if (_cuota > 0) { cuota = _cuota;}
	else{ cuota = 0; 
	cout<<"cuota de cargo invalida restablecida en 0.0 "<<endl;
	}
}
