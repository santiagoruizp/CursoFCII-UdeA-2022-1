#include <iostream>
#include "punto3entregarinterfaz.cpp"
using namespace std;

int main(){
    double real,real2,imaginaria,imaginaria2;
    cout<<"Ingrese la parte real del primer número complejo"<<endl;
    cin>>real;
    cout<<"Ingrese la parte imaginaria del primer número complejo"<<endl;
    cin>>imaginaria;
    cout<<"Ingrese la parte real del segundo número complejo"<<endl;
    cin>>real2;
    cout<<"Ingrese la parte imaginaria del segundo número complejo"<<endl;
    cin>>imaginaria2;
    Complejo num(real, imaginaria); //se define un objeto
    num.resta(real2,imaginaria2);
    num.suma(real2,imaginaria2);
    num.multiplicacion(real2,imaginaria2);
    return 0;
}