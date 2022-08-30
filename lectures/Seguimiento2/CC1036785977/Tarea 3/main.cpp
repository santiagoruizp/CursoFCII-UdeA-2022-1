#include <iostream>
#include "fecha.h"
using namespace std;

int main()
{
cout<<"Fecha normal"<<endl;
Fecha normal( 17, 8, 2022 );
normal.imprimir();
normal.diaSig();
cout<<"\n\n";

cout<<"Fecha fin de mes"<<endl;
Fecha fin( 31, 10, 1800 );
fin.imprimir();
fin.diaSig();
cout<<"\n\n";

cout<<"Fecha fin de año"<<endl;
Fecha finA( 31, 12, 2022 );
finA.imprimir();
finA.diaSig();
cout<<"\n\n";

cout<<"Fecha bisiesta"<<endl;
Fecha bisiesto( 28, 2, 2020 );
bisiesto.imprimir();
bisiesto.diaSig();
cout<<"\n\n";

cout<<"Fecha no bisiesta"<<endl;
Fecha nbisiesto( 28, 2, 2021 );
nbisiesto.imprimir();
nbisiesto.diaSig();
cout<<"\n\n";


cout<<"Fecha incorrecta"<<endl;
Fecha incorrecto( 15, 35, 1995 );
incorrecto.imprimir();
incorrecto.diaSig();
cout<<endl;

return 0;
}
