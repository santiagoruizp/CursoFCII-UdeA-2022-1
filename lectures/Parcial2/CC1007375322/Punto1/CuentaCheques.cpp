#include <iostream>
using namespace std;

#include "CuentaBancaria.h"
//constructor de clase heredada de cuenta -> cuenta de cheques
CuentaCheques::CuentaCheques(double saldo, double montcuota)
    : Cuenta(saldo){
        if(montcuota>=0.0){
            cuota=montcuota;
        }else{
            cout <<"Interes incorrecto, debe ser entre 0 y 1";
        }

    };
//función miembro para redefinir abono con la resta de la cuota por transacción
void CuentaCheques::abonar(double abono){
    bool cond=Cuenta::abonar(abono);
    if(cond){
        cout<<"Cuota de manejo por transacción por tanto ";
        if(!Cuenta::cargar(cuota)){
            Cuenta::cargar(abono);//si no se puede cobrar la cuota, entonces no se realiza el abono
            cout<<"no se puede hacer la transacción, abone dinero suficiente para pagar la cuota por transacción"<<endl;
        }
    }
};

//función miembro para redefinir carga con la resta de la cuota por transacción
void CuentaCheques::cargar(double cargo){
    if(Cuenta::cargar(cargo)){
        cout<<"Cuota de manejo por transacción por tanto ";
        if(!Cuenta::cargar(cuota)){
            Cuenta::abonar(cargo);//si no se puede cobrar la cuota, entonces no se realiza el abono
            cout<<"no se puede hacer la transacción, abone dinero suficiente para pagar la cuota por transacción"<<endl;
        }
    }
};
//esta función miembro nos permite interactuar con el usuario que crea la cuenta de cheques
//así el pueda acceder a las otras funciones miembro abonar, cargar o visualizar su saldo 
void CuentaCheques::opciones(){
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