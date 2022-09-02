
#include<iostream>
#include<iomanip>

using namespace std;

#include "CuentaBancaria.h"

// Clase base -------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

Cuenta::Cuenta(double saldoingresado){

    // Se valida el saldo ingresado
    saldo = ValidacionSaldo(saldoingresado);

}

double Cuenta::ValidacionSaldo(double saldotest){

    // El saldo para la validación debe ser positivo
    if (saldotest < 0.0 ){
        cout<<"Saldo ingresado inválido. Se estableció el saldo en 0.0"<<endl;
        return 0.0;
    }

    else 
        return saldotest;
        
}

double Cuenta::getSaldo() const{

    // Retorno del saldo actual
    return saldo;

}

void Cuenta::Abonar(double abono){

    // Se comprueba que el abono sea positivo y se sobreescribe el saldo
    if (abono < 0.0 )
        cout<<"Abono ingresado inválido. El saldo actual es "<< saldo <<"$"<<endl;
    else {
        saldo += abono;
        cout<<"Se abona "<<abono<<"$"<<". El saldo actual es "<< saldo <<"$"<<endl;
    }
}

void Cuenta::Cargar(double cargo){

    // Se comprueba que el cargo sea positivo, que no exceda el saldo y se retira
    if (cargo < 0.0 )
        cout<<"Cargo ingresado inválido. El saldo actual es "<< saldo <<"$"<<endl;

    else if (cargo > saldo)
        cout<<"El monto a cargar "<<cargo<<"$ excede el saldo de la cuenta. El saldo actual es "<< saldo <<"$"<<endl;
    else {       
        saldo -= cargo;
        cout<<"Se carga "<< cargo <<"$"<<". El saldo actual es "<< saldo <<"$"<<endl;
    }
}

// Clases derivadas--------------------------------------------------------------------
//-------------------------------------------------------------------------------------

CuentaAhorros::CuentaAhorros(double saldoingresado, double tasaingresada)
    : Cuenta(saldoingresado)
{
    // Si la tasa es positiva se carga a la variable privada de CuentaAhorros tasa
    if (tasaingresada < 0.0 ){
        cout<<"Tasa ingresada inválida. Se establece en 0.0"<<endl;
        tasa = 0.0;
    }
    else 
        tasa = tasaingresada;
}

double CuentaAhorros::CalcularInteres(){

    // Cálculo del interés de la cuenta
    cout<<"El interés de esta cuenta es: "<< tasa*getSaldo()/100 <<"$"<<endl;
    return tasa*getSaldo()/100;
}
//-------------------------------------------------------------------------------------

CuentaCheques::CuentaCheques(double saldoingresado, double cuotaingresada)
    : Cuenta(saldoingresado)
{
    // Si la cuota es positiva se carga a la variable privada de CuentaCheques cuota
    if (cuotaingresada < 0.0 ){
        cout<<"Cuota ingresada inválida. Se establece en 0.0"<<endl;
        cuota = 0.0;
    }
    else 
        cuota = cuotaingresada;
}

void CuentaCheques::Abonar(double abono){

    // Se utiliza la función Cuenta::Abonar de la clase base para sobreescribir el saldo luego del abono
    if (abono < 0.0 )
        cout<<"Abono ingresado inválido. El saldo actual es "<< getSaldo() <<"$"<<endl;
    else {
        cout<<"Abono de "<< abono <<"$. Se cobra la cuota de "<<cuota<<"$. ";
        Cuenta::Abonar(abono - cuota);

    }
}

void CuentaCheques::Cargar(double cargo){

    // Se utiliza la función Cuenta::Cargar de la clase base para sobreescribir el saldo luego del retiro
    if (cargo < 0.0 )
        cout<<"Cargo ingresado inválido. El saldo actual es "<< getSaldo() <<"$"<<endl;

    else 
        cout<<"Cargo de "<< cargo <<"$. Se cobra la cuota de "<<cuota<<"$. ";
        Cuenta::Cargar(cargo + cuota);    
}
//-------------------------------------------------------------------------------------