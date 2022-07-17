#include <iostream>

using namespace std;

int main(){
    float q,A,Ts,Ta; //variables
    int opcion;

    //ingreso de los datos
    cout << "Todos los datos ingresados deben estar en sistema internacional: \n";
    cout << "Ingrese la temperatura superficial T_s: "; cin >> Ts;
    cout << "Ingrese la temperatura ambiental T_a: "; cin >> Ta;
    cout << "seleccione el area que quiere ingresar:";
    cout<< "\n 1 Rectangular \n 2 Eliptica \n 3 Otra \n"; cin >> opcion;
    
    switch (opcion)
    {
        case 1:{
            float base,altura,h=8.7;

            cout << "Ingrese la base del rectangulo: \n"; cin >> base;
            cout << "Ingrese la altura del rectangulo: \n"; cin >> altura;
            A = base*altura;
            cout << "El area del rectangulo es: "<< A <<"\n";
            q = h*A*(Ts-Ta);
            cout << "Usando el coeficiente de calor convectivo h: "<< h <<"\n";
            cout << "El calor transferido por metro cuadrado es: "<< q <<"\n";
            return 0;}

        case 2:{
            float ejemayor,ejemenor,pi=3.14,h=8.7;

            cout << "Ingrese la longitud del eje mayor: \n"; cin >> ejemayor;
            cout << "Ingrese la longitud del eje menor: \n"; cin >> ejemenor;
            A = pi*ejemayor*ejemenor;
            cout << "El area de la elipse es: "<< A <<"\n";
            q = h*A*(Ts-Ta);
            cout << "Usando el coeficiente de calor convectivo h: "<< h <<"\n";
            cout << "El calor transferido por metro cuadrado es: "<< q <<"\n";
            return 0;}
       
        case 3:{
            float h=8.7;
            cout << "Ingrese el area \n"; cin >> A;
            cout << "El area es: "<< A <<"\n";
            q = h*A*(Ts-Ta);
            cout << "Usando el coeficiente de calor convectivo h: "<< h <<"\n";
            cout << "El calor transferido por metro cuadrado es: "<< q <<"\n";
        }
        break;
    }

    return 0;
}
