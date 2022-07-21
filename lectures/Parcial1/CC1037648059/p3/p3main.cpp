#include "p3.h"
#include<iostream>
using namespace std;

int main(){
    cout<<"Bienvenidos a la clase de operaciones básicas entre complejos, para editar los valores entre a p3main.cpp"<<endl;
    cout<<"Este es el numero complejo que está en el main por defecto:"<<endl;
    complex mycomplex(2,3);
    mycomplex.print();
    
    mycomplex.getimpart();
    mycomplex.getrealpart();
    cout<<"Ingrese ahora nuevos valores con la funcion de adquisición de datos:"<<endl;
    mycomplex.asingdata();
    mycomplex.print();
    cout<<"Se hace la suma con los valores ingresados en el main:"<<endl;
    mycomplex.sum(6,7);
    cout<<"Se hace la resta con los valores ingresados en el main:"<<endl;
    mycomplex.substraction(8,9);
    cout<<"Se hace el producto con los valores ingresados en el main:"<<endl;
    mycomplex.product(2,3);
    cout<<"Se hace la división con los valores ingresados en el main:"<<endl;
    mycomplex.division(2,3);
    return 0;

}