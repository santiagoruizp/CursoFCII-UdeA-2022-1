#include <iostream>
#include "punto3_inter.cpp"
using namespace std;
int main()
{
double a1,b1,a2,b2;
cout<<"Ingrese la parte real del primer número y luego su parte imaginaria dando un enter"<<endl;
cin>>a1;
cin>>b1;
cout<<"Ingrese la parte real del segundo número y luego su parte imaginaria dando un enter"<<endl;
cin>>a2;
cin>>b2;
    Complejo a(a1, b1); //se define un objeto
    a.resta(a2,b2);
    a.suma(a2,b2);
    a.multiplicacion(a2,b2);
    a.division(a2,b2);
    return 0;
}
