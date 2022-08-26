#include <iostream>
using namespace std;

#include "CuentaBancaria.h"

void IntCuenta(Cuenta);
void IntCuentaAhorros(CuentaAhorros);
void IntCuentaCheques(CuentaCheques);

int main(){

    bool cond= true;
    // se interactua con el usuario, preguntando que tipo de cuenta desea crear, una vez elejida se crea la cuenta
    // y se entra a la funcion miembro "opciones" correspondiente a la cuenta, así el usuario podra interactuar con las diversas
    //funciones miembro que posee la clase 
    while(cond){
        int elec;
        double saldo,interes,cuota;
        cout<<"Bienvenido al sistema de Cuentas Bancarias, a continuación elija el tipo de cuenta que desea crear"<<endl;
        cout<<"1) Cuenta \n 2) Cuenta de Ahorros \n 3) Cuenta de Cheques \n Ingrese el número correspondiente a su elección: "<<endl;
        cin>>elec;
        if(elec==1){
            cout<<"Ingrese el saldo inicial de la Cuenta:"<<endl;
            cin>>saldo;
            Cuenta cuenta1(saldo);
            //IntCuenta(cuenta1);
            cuenta1.opciones();
        }
        if(elec==2){
            cout<<"Ingrese el saldo inicial de la Cuenta de Ahorros:"<<endl;
            cin>>saldo;
            cout<<"Ingrese el interes de la Cuenta de Ahorros:"<<endl;
            cin>>interes;
            CuentaAhorros cuenta2(saldo,interes);
            //IntCuentaAhorros(cuenta2);
            cuenta2.opciones();
        }
        if(elec==3){

            cout<<"Ingrese el saldo inicial de la Cuenta de Cheques:"<<endl;
            cin>>saldo;
            cout<<"Ingrese la cuota de la Cuenta de Cheques:"<<endl;
            cin>>cuota;
            CuentaCheques cuenta3(saldo,cuota);
            //IntCuentaCheques(cuenta3);
            cuenta3.opciones();
        }
        cout <<"Si desea crear otra cuenta introduzca 1, si no 0"<<endl;
        cin>>elec;
        if(elec==1){
            cond=true;
        }else cond=false;
    
    }
};