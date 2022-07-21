#include<iostream>
#include "p3.h"
#include<limits>
using namespace std;

complex::complex(double a,double b){
    Repart=a;
    Impart=b;
}
void complex::asingdata(){
    cout<<"Asigne la parte real del nuevo número complejo: "<<endl;
    while(!(cin>>Repart)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"El programa solo admite números."<<endl;
    };
    cout<<"Asigne la parte imaginaria del nuevo número complejo:"<<endl;
    while(!(cin>>Impart)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"El programa solo admite números"<<endl;
    };
}
void complex::print(){
    cout<<Repart<<" + "<<Impart<<"j"<<endl;
}

void complex::getimpart(){
    cout<<"La parte imaginaria del numero es: "<<Impart<<endl;

}

void complex::getrealpart(){
    cout<<"La parte real del numero es: "<<Repart<<endl;
}

void complex::sum(double c,double d){
    cout<<c<<" + "<<d<<"j "<<"  +  "<<Repart<<" + "<<Impart<<"j =";
    Repart+=c;
    Impart+=d;
    print();
}

void complex::substraction(double c,double d){
    cout<<c<<" + "<<d<<"j "<<"  -  ("<<Repart<<" + "<<Impart<<"j) =";
    Repart-=c;
    Impart-=d;
    print();
}

void complex::product(double c,double d){
    cout<<c<<" + "<<d<<"j "<<"  **  ("<<Repart<<" + "<<Impart<<"j) =";
    double c1=Repart;
    double c2=Impart;
    Repart=c1*c-c2*d;
    Impart=c1*d+c2*c;
    print();

}

void complex::division(double c,double d){
    cout<<c<<" + "<<d<<"j "<<"  /  ("<<Repart<<" + "<<Impart<<"j) =";
    double c1=Repart;
    double c2=Impart;
    Repart=(c1*c+c2*d)/(c1*c1+c2*c2);
    Impart=(c1*d-c2*c)/(c1*c1+c2*c2);
    print();    

}