
#include<iostream>
#include<iomanip>

using namespace std;

#include "CuentaBancaria.h"

int main(){

    cout<<"---> Se crea una cuenta común con saldo 1000$"<<endl;
    Cuenta cuenta1(1000);
    cuenta1.Abonar(1000);
    cuenta1.Cargar(2500);
    cuenta1.Cargar(250);

    cout<<endl<<"---> Se crea una cuenta de ahorros con saldo 2000$ e intereses del 1%"<<endl;

    CuentaAhorros cuenta2(2000, 1);
    cuenta2.CalcularInteres();
    cuenta2.Abonar(1000);
    cuenta2.Cargar(2000);

    cout<<endl<<"---> Se crea una cuenta de cheques con saldo 5000$ y cuota de 100$"<<endl;

    CuentaCheques cuenta3(5000, 100);
    cuenta3.Abonar(1000);
    cuenta3.Cargar(3000);

    return 0;

}