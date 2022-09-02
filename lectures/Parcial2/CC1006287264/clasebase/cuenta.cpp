#include <iostream>
using namespace std;
#include <stdexcept>
#include <cstdlib>
#include "cuenta.h"

Cuenta::Cuenta(  double saldo )
  
{ 


  //cin >> ventas;
  if ( saldo<0)
        {   
            //cin.fail() ;              
            cout<<"\nSaldo invalido"<< endl;
            //cin.clear();
            //cin.ignore();
            //cin >> ventas;
                
        }
 
  setsaldo( saldo); // valida y almacena las ventas brutas
  //setcarga( carga );
  //abonar(abono);
  
}



void Cuenta::setsaldo( double saldo )
{
  saldot = ( saldo < 0.0 ) ? 0.0 : saldo;
  //cout<< "Valor invalido: "<<endl;
}

double Cuenta::getsaldo() const
{
  return saldot;
}

void Cuenta::abonar( double abono )
{
  abonos = abono;
  if (abono<0.0){
    cout<< "\nAbono invalido: "<<endl;
    abonos= 0.0;
  }
  else{
  //abonos = ( abono< 0.0 ) ? 0.0 : abono;
  saldot = saldot + abonos;

  }//cout<< "Valor invalido: "<<endl;
}

double Cuenta::getabono() const
{
  return abonos;
}
void Cuenta::cargar( double carga)
{   
    if (cargas= carga>=0){
    if (carga<=getsaldo()){
    setsaldo(getsaldo()-carga);
    cargas= carga;
    //return 1;
    }
    else{
    cout<<"\nEl monto a cargar excede el saldo de la cuenta: El cargo es de 0.0" << endl;
    //return 0;
    }
  }
  else {
  cout<<"\nEl cargo ingresado es invalido:" << endl;
  //return 0;
  }
  
}

double Cuenta::getcarga() const
{
  return cargas;
}




void Cuenta::imprimir() const
{
  cout << "\n$" << getsaldo();
       //<<"\nCarga: " << getcarga()
       //<<"\nAbono: " << getabono()
       //<< "\nCarga: " << getsaldo();
       
}
