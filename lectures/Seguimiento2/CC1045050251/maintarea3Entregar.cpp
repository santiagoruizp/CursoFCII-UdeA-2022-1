#include <iostream>
#include "fechaEntregar.h"
using namespace std;

int main(){
    cout<<"Fecha hoy"<<endl;
    Fecha hoycomputo( 23, 8, 2023 );
    hoycomputo.imprimir();
    hoycomputo.diaSig();cout<<"\n";
    cout<<"-------------------------------------"<<"\n";

    cout<<"cambiando de mes"<<endl;
    Fecha cambiomes( 31, 5, 2024 );
    cambiomes.imprimir();
    cambiomes.diaSig();cout<<"\n";
    cout<<"-------------------------------------"<<"\n";

    cout<<"cambiando de año"<<endl;
    Fecha cambioanio( 31, 12, 2022 );
    cambioanio.imprimir();
    cambioanio.diaSig();cout<<"\n";
    cout<<"-------------------------------------"<<"\n";

    cout<<"de un anio bisiesto"<<endl;
    Fecha bisiesto( 28, 2, 2028 );
    bisiesto.imprimir();
    bisiesto.diaSig();cout<<"\n";
    cout<<"-------------------------------------"<<"\n";

    cout<<"de un anio no bisiesta"<<endl;
    Fecha nbisiesto( 28, 2, 2027 );
    nbisiesto.imprimir();
    nbisiesto.diaSig();cout<<"\n";
    cout<<"-------------------------------------"<<"\n";
    
    return 0;
}