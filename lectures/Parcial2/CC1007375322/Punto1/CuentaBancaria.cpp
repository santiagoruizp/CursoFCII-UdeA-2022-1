#include <iostream>
using namespace std;

#include "CuentaBancaria.h"
//se definen funciones miembro de la clase Cuenta
//constructor
Cuenta::Cuenta(double saldoCuent){
    if(saldoCuent>=0.0)
        saldo=saldoCuent;// se define el saldo si es mayor o igual a cero
    else{
        cout <<"Saldo inicial invalido, se inicializa en 0.0";// si es negativo el saldo, se lanza el error y se inicializa en 0.0
        saldo=0.0;
    }
}
//funcion miembro abonar
bool Cuenta::abonar(double abono){
    //se evalua que el abono sea valido
    if(abono>=0){
        saldo+=abono;// se añade el abono
        cout<< "Se abona "<<abono<<"$ a la cuenta."<< "El nuevo saldo es "<<saldo<<"$"<<endl;
        return true;
    }else{
        cout<<"Abono invalido, debe ser un valor positivo"<<endl;
        return false;
    }
}
//funcion miembro cargar
bool Cuenta::cargar(double cargo){
    //se evalua valides de la carga
    if(cargo>=0){
        if(cargo>saldo){// se verifica que el cargo sea menor  o igual al saldo
            cout << "El monto a cargar excedio el saldo de la cuenta"<<endl;
            return false;
        }else{
            saldo-=cargo;//se realiza el cargo
            cout<< "Se cargo "<<cargo<<"$ a la cuenta."<< "El nuevo saldo es "<<saldo<<"$"<<endl;
            return true;
        }
    }else{
        cout<<"Cargo invalido, debe ser un valor positivo"<<endl;
        return false;
    }
}
// funcion miembro que sustrae el saldo para las clases heredadas
double Cuenta::getSaldo(){
    return saldo;
}
//esta función miembro nos permite interactuar con el usuario que crea la cuenta
//así el pueda acceder a las otras funciones miembro abonar, cargar o visualizar su saldo
void Cuenta::opciones(){
    bool cond=true;
    int elec;
    while(cond){
        cout<<"Que operación desea realizar sobre su cuenta: \n 1) Abonar \n 2) Cargar \n 3) Visualizar saldo \n Introduzca el número correspondiente a su elección:"<<endl;
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
            
            default:
                cout<<"Introduzca una opción valida"<<endl;
            }

        cout <<"Si desea realizar otra operación introduzca 1, si no 0"<<endl;
        cin>>elec;
        if(elec==1){
            cond=true;
        }else cond=false;
    };
}