#include <iostream>
using namespace std;

#include "CuentaBancaria.h"
//constructor de clase heredada de cuenta -> cuenta de ahorros
CuentaAhorros::CuentaAhorros(double saldo, double interesAhor)
    : Cuenta(saldo){
        if(interesAhor>=0.0 && interesAhor<=1){
            interes=interesAhor;
        }else{
            cout <<"Interes incorrecto, debe ser entre 0 y 1";
        }

    };
//funcion miembro para calcular interes
double CuentaAhorros::calcularInteres( ){
    return interes*getSaldo();
};
//esta función miembro nos permite interactuar con el usuario que crea la cuenta de ahorros
//así el pueda acceder a las otras funciones miembro abonar, cargar, visualizar su saldo o añadir interes 
void CuentaAhorros::opciones( ){
    bool cond=true;
    int elec;
    while(cond){
        cout<<"Que operación desea realizar sobre su Cuenta de Ahorros: \n 1) Abonar \n 2) Cargar \n 3) Visualizar saldo \n 4) Agregar interes \n Introduzca el número correspondiente a su elección:"<<endl;
        cin>>elec;
        switch (elec)
            {
            case 1:
                double abono;
                cout<<"Ingrese el valor a abonar:"<<endl;
                cin>>abono;
                abonar(abono);
                break;
            case 2:
                double cargo;
                cout<<"Ingrese el valor a cargar:"<<endl;
                cin>>cargo;
                cargar(cargo);
                break;
            case 3:
                cout<<"Su saldo actual es "<<getSaldo()<<endl;
                break;
            case 4:
                double interes;
                interes=calcularInteres();
                cout<<"Por interes ";
                abonar(interes);
                break;
            
            default:
                cout<<"Introduzca una opción valida"<<endl;
            }

        cout <<"Si desea realizar otra operación introduzca 1, si no 0"<<endl;
        cin>>elec;
        if(elec==1){
            cond=true;
        }else cond=false;
    }
};