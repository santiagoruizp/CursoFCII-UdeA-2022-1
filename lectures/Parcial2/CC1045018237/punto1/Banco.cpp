#include <iostream>
#include <iomanip>

#include "Cuenta.h"
#include "Cuentaderi.h"
#include "CuentaCheque.h"

using namespace std;

int main()
{
    Cuenta cuenta1( 50.00 ); // creamos un objeto para la cuenta
    CuentaAhorros cuenta2( 25.00, 3.0); // creamos un objeto para la cuenta de ahorros
    CuentaCheque cuenta3( 80.00, 1.0); // creamos un objeto para la cuentacheque

    cout << fixed << setprecision(2);

    //iniciamos el saldo de los objetos

    cout << "cuenta1 Saldo : $ " << cuenta1.getSaldo() << endl;
    cout << "cuenta2 Saldo : $ " << cuenta2.getSaldo() << endl;
    cout << "cuenta3 Saldo : $ " << cuenta3.getSaldo() << endl;

    cout << "\nintentando cargar $25.00 a la cuenta1." << endl;
    cuenta1.cargar(25.00);
    cout << "\nintentando cargar $30.00 a la cuenta1." << endl;
    cuenta2.cargar(30.00);
    cout << "\nintentando cargar $40.00 a la cuenta1." << endl;
    cuenta3.cargar(40.00);

    // saldos
    cout << "\ncuenta1 saldo : $" << cuenta1.getSaldo() << endl;
    cout << "\ncuenta2 saldo : $" << cuenta2.getSaldo() << endl;
    cout << "\ncuenta3 saldo : $" << cuenta3.getSaldo() << endl;

    cout << "\nAbonando $40.00 a la cuenta1." << endl;
    cuenta1.abonar( 40.00 );
    cout << "\nAbonando $65.00 a la cuenta1." << endl;
    cuenta2.abonar( 65.00 );
    cout << "\nAbonando $20.00 a la cuenta1." << endl;
    cuenta3.abonar( 20.00 );

    // saldos
    cout << "\ncuenta1 Saldo: $" << cuenta1.getSaldo() << endl;
    cout << "\ncuenta2 Saldo: $" << cuenta2.getSaldo() << endl;
    cout << "\ncuenta3 Saldo: $" << cuenta3.getSaldo() << endl;

    //adicionamos el interes a la cuenta de ahorros del objeto cuenta2

    double interesGanado = cuenta2.calcularInteres();
    cout << "\nagregando $" << interesGanado << " interes a cuenta2." << endl;
    cuenta2.abonar( interesGanado );
    
    cout << "|nuevo saldo de la cuenta2: $" << cuenta2.getSaldo() << endl;

}